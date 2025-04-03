#include "ModelServer.h"

#include <fstream>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

ModelServer::ModelServer(bool& isRunning) : isRunning(isRunning)
{
}

grpc::Status ModelServer::GetModel(grpc::ServerContext* context, const ModelRequest* request, grpc::ServerWriter<ModelReply>* writer)
{
	isRunning = true;

	const std::string name(request->modelname() + ".obj");
	const std::string log("Sending " + name + " to client...\n");
	const std::filesystem::path path = assetsPath / name;
	std::cout << "Path: " << path << '\n';

	// const auto size = std::filesystem::file_size(path);
	// std::string content(size, '\0');
	// std::ifstream in(path);
	// in.read(content.data(), size);

	std::ifstream t(path, std::ios::binary);
	std::string line;
	int numBytesToRead = 10 * 1024; // 10KB
	
	while (t)
	{
		std::vector<char> buffer(numBytesToRead);
		t.read(buffer.data(), buffer.size());
		if (std::streamsize bytesRead = t.gcount(); bytesRead > 0)
		{
			ModelReply modelReply;
			modelReply.set_objfile(std::string(buffer.data(), bytesRead));
			writer->Write(modelReply);
		}
	}

	std::cout << log;
	return grpc::Status::OK;
}

void ModelServer::runServer(uint16_t port)
{
	std::string serverAddress = absl::StrFormat("localhost:%d", port);

	grpc::EnableDefaultHealthCheckService(true);
	grpc::reflection::InitProtoReflectionServerBuilderPlugin();
	grpc::ServerBuilder builder;
	// Listen on the given address without any authentication mechanism.
	builder.AddListeningPort(serverAddress, grpc::InsecureServerCredentials());
	// Register "service" as the instance through which we'll communicate with
	// clients. In this case it corresponds to an *synchronous* service.
	builder.RegisterService(this);

	// Set max message size to 2GB. lol. HAHAHAHA
	// builder.SetMaxReceiveMessageSize(INT_MAX);
	// builder.SetMaxSendMessageSize(INT_MAX);
	// builder.SetMaxMessageSize(INT_MAX);

	// Finally assemble the server.
	server = builder.BuildAndStart();
	std::cout << "Server listening on " << serverAddress << std::endl;
	// Wait for the server to shutdown. Note that some other thread must be
	// responsible for shutting down the server for this call to ever return.
	server->Wait();
}

// void ModelServer::stop()
// {
// 	// shut down the server, but wait 30 seconds for all RPC calls to finish.
// 	const std::chrono::time_point shutdownTime = std::chrono::system_clock::now() +
// 		std::chrono::milliseconds(30000);
// 	server->Shutdown(shutdownTime);
// }

void ModelServer::run()
{
	runServer(50051);
}

ModelServer::~ModelServer()
{
	// shut down the server, but wait 30 seconds for all RPC calls to finish.
	const std::chrono::time_point shutdownTime = std::chrono::system_clock::now() +
		std::chrono::milliseconds(shutdownDuration);
	server->Shutdown(shutdownTime);

	sleep(shutdownDuration);

	isRunning = false;
}
