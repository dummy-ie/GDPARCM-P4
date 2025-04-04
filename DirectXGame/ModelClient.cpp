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
	this->modelNames.push_back(modelName);

	const grpc::ChannelArguments channelArgs;
	// channelArgs.SetMaxReceiveMessageSize(INT_MAX);  // Increase max receive size
	// channelArgs.SetMaxSendMessageSize(INT_MAX);    // Increase max send size
	this->stub_ = ModelLoader::NewStub(grpc::CreateCustomChannel(target, grpc::InsecureChannelCredentials(), channelArgs));
}

ModelClient::ModelClient(const std::string& target, const std::vector<std::string>& modelNames, std::mutex* coutMutex)
{
	this->coutMutex = coutMutex;
	this->modelNames = modelNames;
	const grpc::ChannelArguments channelArgs;
	// channelArgs.SetMaxReceiveMessageSize(INT_MAX);  // Increase max receive size
	// channelArgs.SetMaxSendMessageSize(INT_MAX);    // Increase max send size
	this->stub_ = ModelLoader::NewStub(grpc::CreateCustomChannel(target, grpc::InsecureChannelCredentials(), channelArgs));
}


std::string ModelClient::getModel(const std::string& model)
{
	std::cout << "Requesting " + model + " from server. \n";

	ModelRequest request;
	ModelReply reply;
	grpc::ClientContext context;

	request.set_modelname(model);

	const std::chrono::time_point deadline = std::chrono::system_clock::now() +
		std::chrono::milliseconds(30000);
	context.set_deadline(deadline);

	std::string fileName = assetsPath.string() + model + ".obj";
	std::ofstream out(fileName, std::ios::binary);
	const std::unique_ptr reader(stub_->GetModel(&context, request));
	while (reader->Read(&reply))
	{
		//sleep(1000);
		//std::cout << "File Size " << reply.objfilesize() << "\n";
		//std::cout << "Received " << reply.objfile().size() << " bytes\n";
		this->totalBytesReceived_ += reply.objfile().size();

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
}

int32_t ModelClient::getModelSize(const std::string& model)
{
	std::cout << "Requesting " + model + " from server. \n";

	ModelRequest request;
	ModelReply reply;
	grpc::ClientContext context;

	request.set_modelname(model);

	const std::chrono::time_point deadline = std::chrono::system_clock::now() +
		std::chrono::milliseconds(30000);
	context.set_deadline(deadline);

	std::string fileName = assetsPath.string() + model + ".obj";
	std::ofstream out(fileName, std::ios::binary);
	const std::unique_ptr reader(stub_->GetModelSize(&context, request));

	int32_t fileSize;

	while (reader->Read(&reply))
	{
		fileSize = reply.objfilesize();
	}

	if (Status status = reader->Finish(); status.ok())
	{
		return fileSize;
	}
	else
	{
		std::cout << status.error_code() << ": " << status.error_message()
			<< '\n';
		return -1;
	}
}

uint32_t ModelClient::getFileSize()
{
	return this->fileSize_;
}

uint32_t ModelClient::getTotalBytesReceived()
{
	return this->totalBytesReceived_;
}

void ModelClient::deleteModels()
{
	for (std::string name : modelNames)
	{
		gdeng03::GameObjectManager::get()->deleteObjectByName(name + " Mesh");
		//const std::string fileName = assetsPath.string() + name + ".obj";
		//std::filesystem::remove(fileName);
	}
}

ModelClient::~ModelClient()
{
	delete this;
}

void ModelClient::runClient()
{
	for (std::string name : modelNames)
	{
		const int32_t reply = getModelSize(name);

		if (reply == -1)
		{
			gdeng03::LogUtils::error("RPC failed");
			return;
		}
		gdeng03::LogUtils::log("Model " + name + " file size received successfully.");

		this->fileSize_ += reply;
	}
	this->fileSize_--;
	for (std::string name : modelNames)
	{
		const std::string reply = getModel(name);

		if (reply == "RPC failed")
		{
			gdeng03::LogUtils::error(reply);
			return;
		}

		gdeng03::LogUtils::log("Model " + name + " received successfully.");
		gdeng03::LogUtils::log(this, "Model is stored at " + reply);

		const auto newObj = gdeng03::GameObjectManager::get()->createObject(reply, name);
		newObj->setPosition(gdeng03::randomRangeVector3D(-2, 2));
		newObj->setRotation(gdeng03::randomRangeVector3D(0, 360));
	}
}

void ModelClient::run()
{
	//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	sleep(1000);
	std::lock_guard guard(*coutMutex);
	runClient();
}
