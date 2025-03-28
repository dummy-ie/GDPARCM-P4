// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: sceneLoader.proto

#include "sceneLoader.pb.h"
#include "sceneLoader.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>

static const char* SceneLoader_method_names[] = {
  "/SceneLoader/GetScene",
};

std::unique_ptr< SceneLoader::Stub> SceneLoader::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< SceneLoader::Stub> stub(new SceneLoader::Stub(channel, options));
  return stub;
}

SceneLoader::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetScene_(SceneLoader_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status SceneLoader::Stub::GetScene(::grpc::ClientContext* context, const ::SceneRequest& request, ::SceneReply* response) {
  return ::grpc::internal::BlockingUnaryCall< ::SceneRequest, ::SceneReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetScene_, context, request, response);
}

void SceneLoader::Stub::async::GetScene(::grpc::ClientContext* context, const ::SceneRequest* request, ::SceneReply* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::SceneRequest, ::SceneReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetScene_, context, request, response, std::move(f));
}

void SceneLoader::Stub::async::GetScene(::grpc::ClientContext* context, const ::SceneRequest* request, ::SceneReply* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetScene_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::SceneReply>* SceneLoader::Stub::PrepareAsyncGetSceneRaw(::grpc::ClientContext* context, const ::SceneRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::SceneReply, ::SceneRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetScene_, context, request);
}

::grpc::ClientAsyncResponseReader< ::SceneReply>* SceneLoader::Stub::AsyncGetSceneRaw(::grpc::ClientContext* context, const ::SceneRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetSceneRaw(context, request, cq);
  result->StartCall();
  return result;
}

SceneLoader::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SceneLoader_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SceneLoader::Service, ::SceneRequest, ::SceneReply, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](SceneLoader::Service* service,
             ::grpc::ServerContext* ctx,
             const ::SceneRequest* req,
             ::SceneReply* resp) {
               return service->GetScene(ctx, req, resp);
             }, this)));
}

SceneLoader::Service::~Service() {
}

::grpc::Status SceneLoader::Service::GetScene(::grpc::ServerContext* context, const ::SceneRequest* request, ::SceneReply* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


