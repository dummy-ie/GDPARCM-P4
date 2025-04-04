#pragma once
#include <cstdint>
#include "modelLoader.pb.h"
#include "modelLoader.grpc.pb.h"
#include "../DirectXGame/IETThread.h"

class ModelServer final : public ModelLoader::Service, public IETThread  {
public:
	ModelServer(bool& isRunning);

	grpc::Status GetModel(grpc::ServerContext* context, const ModelRequest* request, grpc::ServerWriter<ModelReply>* writer) override;
	grpc::Status GetModelSize(grpc::ServerContext* context, const ModelRequest* request, grpc::ServerWriter<ModelReply>* writer) override;
	void runServer(uint16_t port);

	//void stop();
	void run() override;
	~ModelServer() override;

private:
	bool& isRunning;
	int shutdownDuration = 10000;

	std::unique_ptr<grpc::Server> server;
	std::filesystem::path assetsPath = std::filesystem::path("../../P4Server/assets/");
};

