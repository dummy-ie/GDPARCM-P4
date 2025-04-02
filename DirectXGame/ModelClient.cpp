#include "ModelClient.h"

#include <fstream>
#include <grpcpp/create_channel.h>

#include "GameObjectManager.h"
#include "LogUtils.h"
#include "MathUtil.h"
#include "RandomUtils.h"

ModelClient::ModelClient(const std::string& target, const std::string& modelName, std::mutex* coutMutex)
{
	this->coutMutex = coutMutex;
	this->modelName = modelName;

	grpc::ChannelArguments channelArgs;
	channelArgs.SetMaxReceiveMessageSize(INT_MAX);  // Increase max receive size
	channelArgs.SetMaxSendMessageSize(INT_MAX);    // Increase max send size
	this->stub_ = ModelLoader::NewStub(grpc::CreateCustomChannel(target, grpc::InsecureChannelCredentials(), channelArgs));
}


std::string ModelClient::getModel(const std::string& model) const
{
	std::cout << "Requesting " + model + " from server. \n";

	ModelRequest request;
	ModelReply reply;
	grpc::ClientContext context;

	request.set_modelname(model);

	const std::chrono::time_point deadline = std::chrono::system_clock::now() +
		std::chrono::milliseconds(20000);
	context.set_deadline(deadline);

	std::string fileName = assetsPath.string() + modelName + ".obj";
	std::ofstream out(fileName, std::ios::binary);
	const std::unique_ptr reader(stub_->GetModel(&context, request));
	while (reader->Read(&reply)) 
	{
		std::cout << "Received " << reply.objfile().size() << " bytes\n";
		out << reply.objfile();
	}

	if (Status status = reader->Finish(); status.ok())
	{
		return fileName;
	}
	else
	{
		std::cout << status.error_code() << ": " << status.error_message()
			<< '\n';
		return "RPC failed";
	}

	// if (const grpc::Status status = stub_->GetModel(&context, request, &reply);
	// 	status.ok()) {
	// 	return reply.objfile();
	// }
	// else {
	// 	std::cout << status.error_code() << ": " << status.error_message()
	// 		<< '\n';
	// 	return "RPC failed";
	// }
}

ModelClient::~ModelClient()
{
	delete this;
}

void ModelClient::runClient() const
{
	const std::string reply = getModel(modelName);

	if (reply == "RPC failed")
	{
		gdeng03::LogUtils::error(reply);
		return;
	}

	gdeng03::LogUtils::log("Model " + modelName + " received successfully.");
	gdeng03::LogUtils::log(this, "Loading " + reply);

	const auto newObj = gdeng03::GameObjectManager::get()->createObject(reply, modelName);
	newObj->setPosition(gdeng03::randomRangeVector3D(-2, 2));
	newObj->setRotation(gdeng03::randomRangeVector3D(0, 360));
}

void ModelClient::run()
{
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	sleep(1000);
	std::lock_guard guard(*coutMutex);
	runClient();
}
