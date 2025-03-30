#pragma once
#include <cstdint>
#include "modelLoader.pb.h"
#include "modelLoader.grpc.pb.h"
#include "IETThread.h"

class ModelServer final : public ModelLoader::Service, public IETThread  {
public:
	grpc::Status sendModel(grpc::ServerContext* context, const ModelRequest* request, ModelReply* response) override;
	static void runServer(uint16_t port);

	void run() override;
};

