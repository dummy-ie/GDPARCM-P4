#include "ModelServer.h"

#include <fstream>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

grpc::Status ModelServer::GetModel(grpc::ServerContext* context, const ModelRequest* request, grpc::ServerWriter<ModelReply>* writer)
{
	const std::string name(request->modelname() + ".obj");
	const std::string log("Hello from " + name + " :D \n");
	const std::filesystem::path path = assetsPath / name;
	std::cout << "Path: " << path << '\n';

	// const auto size = std::filesystem::file_size(path);
	// std::string content(size, '\0');
	// std::ifstream in(path);
	// in.read(content.data(), size);

	const std::ifstream t(path, std::ios::binary);
	std::stringstream reply;
	reply << t.rdbuf();

	ModelReply modelReply;
	modelReply.set_objfile(reply.str());

	writer->Write(modelReply);
	std::cout << log;
	return grpc::Status::OK;
}

void ModelServer::runServer(uint16_t port)
{
	std::string serverAddress = absl::StrFormat("localhost:%d", port);
	ModelServer service;

	grpc::EnableDefaultHealthCheckService(true);
	grpc::reflection::InitProtoReflectionServerBuilderPlugin();
	grpc::ServerBuilder builder;
	// Listen on the given address without any authentication mechanism.
	builder.AddListeningPort(serverAddress, grpc::InsecureServerCredentials());
	// Register "service" as the instance through which we'll communicate with
	// clients. In this case it corresponds to an *synchronous* service.
	builder.RegisterService(&service);

	// Set max message size to 2GB. lol. HAHAHAHA
	builder.SetMaxReceiveMessageSize(INT_MAX);
	builder.SetMaxSendMessageSize(INT_MAX);
	// builder.SetMaxMessageSize(INT_MAX);

	// Finally assemble the server.
	std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
	std::cout << "Server listening on " << serverAddress << std::endl;
	// Wait for the server to shutdown. Note that some other thread must be
	// responsible for shutting down the server for this call to ever return.
	server->Wait();
}
