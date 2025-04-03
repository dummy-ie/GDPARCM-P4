#pragma once
#include <string>
#include "modelLoader.grpc.pb.h"
#include "IETThread.h"
#include "IExecutionEvent.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

class ModelClient : public IETThread
{
public:
	ModelClient(const std::string& target, const std::string& modelName, std::mutex* coutMutex, gd::IExecutionEvent* event);
	~ModelClient() override;
	void run() override;

private:
	void runClient() const;
	std::string getModel(const std::string& model) const;

private:
	gd::IExecutionEvent* event;

	std::mutex* coutMutex;
	std::string modelName;
	std::unique_ptr<ModelLoader::Stub> stub_;
	std::filesystem::path assetsPath = std::filesystem::path("assets/models/");;
};

