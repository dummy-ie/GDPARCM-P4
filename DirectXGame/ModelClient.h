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

private:
	void runClient() const;
	std::string getModel(const std::string& model) const;

private:
	std::mutex* coutMutex;
	std::vector<std::string> modelNames;
	std::unique_ptr<ModelLoader::Stub> stub_;
	std::filesystem::path assetsPath = std::filesystem::path("assets/models/");;
};

