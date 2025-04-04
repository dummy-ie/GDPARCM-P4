#pragma once
#include <string>
#include "modelLoader.grpc.pb.h"
#include "IETThread.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

class ModelClient : public IETThread
{
public:
	ModelClient(const std::string& target, const std::string& modelName, std::mutex* coutMutex);
	ModelClient(const std::string& target, const std::vector<std::string>& modelNames, std::mutex* coutMutex);
	~ModelClient() override;
	void run() override;
	uint32_t getFileSize();
	uint32_t getTotalBytesReceived();

	void deleteModels();
	bool isFinished();
	bool isLoading();

private:
	void runClient();
	std::string getModel(const std::string& model);
	int32_t getModelSize(const std::string& model);


private:
	uint32_t fileSize_ = 1;
	uint32_t totalBytesReceived_ = 0;

	std::mutex* coutMutex;
	std::vector<std::string> modelNames;
	std::unique_ptr<ModelLoader::Stub> stub_;
	std::filesystem::path assetsPath = std::filesystem::path("assets/models/");

	bool finished = false;
	bool loading = false;
};

