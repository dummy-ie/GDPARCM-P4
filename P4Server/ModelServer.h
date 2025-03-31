#pragma once
#include <cstdint>
#include "modelLoader.pb.h"
#include "modelLoader.grpc.pb.h"

class ModelServer final : public ModelLoader::Service  {
public:
	grpc::Status GetModel(grpc::ServerContext* context, const ModelRequest* request, grpc::ServerWriter<ModelReply>* writer) override;
	static void runServer(uint16_t port);

private:
	std::filesystem::path assetsPath = std::filesystem::path("../../P4Server/assets/");
};

