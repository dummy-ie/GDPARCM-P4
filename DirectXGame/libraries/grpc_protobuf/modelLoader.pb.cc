// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: modelLoader.proto
// Protobuf C++ Version: 5.29.1

#include "modelLoader.pb.h"

#include <algorithm>
#include <type_traits>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/generated_message_tctable_impl.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;

inline constexpr ModelRequest::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : modelname_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR ModelRequest::ModelRequest(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct ModelRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ModelRequestDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ModelRequestDefaultTypeInternal() {}
  union {
    ModelRequest _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ModelRequestDefaultTypeInternal _ModelRequest_default_instance_;

inline constexpr ModelReply::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : objfile_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        texture_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        texwidth_{0},
        texheight_{0},
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR ModelReply::ModelReply(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct ModelReplyDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ModelReplyDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~ModelReplyDefaultTypeInternal() {}
  union {
    ModelReply _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ModelReplyDefaultTypeInternal _ModelReply_default_instance_;
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_modelLoader_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_modelLoader_2eproto = nullptr;
const ::uint32_t
    TableStruct_modelLoader_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::ModelRequest, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::ModelRequest, _impl_.modelname_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::ModelReply, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::ModelReply, _impl_.objfile_),
        PROTOBUF_FIELD_OFFSET(::ModelReply, _impl_.texwidth_),
        PROTOBUF_FIELD_OFFSET(::ModelReply, _impl_.texheight_),
        PROTOBUF_FIELD_OFFSET(::ModelReply, _impl_.texture_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::ModelRequest)},
        {9, -1, -1, sizeof(::ModelReply)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::_ModelRequest_default_instance_._instance,
    &::_ModelReply_default_instance_._instance,
};
const char descriptor_table_protodef_modelLoader_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\021modelLoader.proto\"!\n\014ModelRequest\022\021\n\tm"
    "odelName\030\001 \001(\t\"S\n\nModelReply\022\017\n\007objFile\030"
    "\001 \001(\t\022\020\n\010texWidth\030\002 \001(\005\022\021\n\ttexHeight\030\003 \001"
    "(\005\022\017\n\007texture\030\004 \001(\01427\n\013ModelLoader\022(\n\010Ge"
    "tModel\022\r.ModelRequest\032\013.ModelReply\"\000b\006pr"
    "oto3"
};
static ::absl::once_flag descriptor_table_modelLoader_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_modelLoader_2eproto = {
    false,
    false,
    204,
    descriptor_table_protodef_modelLoader_2eproto,
    "modelLoader.proto",
    &descriptor_table_modelLoader_2eproto_once,
    nullptr,
    0,
    2,
    schemas,
    file_default_instances,
    TableStruct_modelLoader_2eproto::offsets,
    file_level_enum_descriptors_modelLoader_2eproto,
    file_level_service_descriptors_modelLoader_2eproto,
};
// ===================================================================

class ModelRequest::_Internal {
 public:
};

ModelRequest::ModelRequest(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:ModelRequest)
}
inline PROTOBUF_NDEBUG_INLINE ModelRequest::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::ModelRequest& from_msg)
      : modelname_(arena, from.modelname_),
        _cached_size_{0} {}

ModelRequest::ModelRequest(
    ::google::protobuf::Arena* arena,
    const ModelRequest& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  ModelRequest* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:ModelRequest)
}
inline PROTOBUF_NDEBUG_INLINE ModelRequest::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : modelname_(arena),
        _cached_size_{0} {}

inline void ModelRequest::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
ModelRequest::~ModelRequest() {
  // @@protoc_insertion_point(destructor:ModelRequest)
  SharedDtor(*this);
}
inline void ModelRequest::SharedDtor(MessageLite& self) {
  ModelRequest& this_ = static_cast<ModelRequest&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.modelname_.Destroy();
  this_._impl_.~Impl_();
}

inline void* ModelRequest::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) ModelRequest(arena);
}
constexpr auto ModelRequest::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::CopyInit(sizeof(ModelRequest),
                                            alignof(ModelRequest));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull ModelRequest::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_ModelRequest_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &ModelRequest::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<ModelRequest>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &ModelRequest::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<ModelRequest>(), &ModelRequest::ByteSizeLong,
            &ModelRequest::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(ModelRequest, _impl_._cached_size_),
        false,
    },
    &ModelRequest::kDescriptorMethods,
    &descriptor_table_modelLoader_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* ModelRequest::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 30, 2> ModelRequest::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    1, 0,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967294,  // skipmap
    offsetof(decltype(_table_), field_entries),
    1,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::ModelRequest>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string modelName = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(ModelRequest, _impl_.modelname_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string modelName = 1;
    {PROTOBUF_FIELD_OFFSET(ModelRequest, _impl_.modelname_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\14\11\0\0\0\0\0\0"
    "ModelRequest"
    "modelName"
  }},
};

PROTOBUF_NOINLINE void ModelRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:ModelRequest)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.modelname_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* ModelRequest::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const ModelRequest& this_ = static_cast<const ModelRequest&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* ModelRequest::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const ModelRequest& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:ModelRequest)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // string modelName = 1;
          if (!this_._internal_modelname().empty()) {
            const std::string& _s = this_._internal_modelname();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "ModelRequest.modelName");
            target = stream->WriteStringMaybeAliased(1, _s, target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:ModelRequest)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t ModelRequest::ByteSizeLong(const MessageLite& base) {
          const ModelRequest& this_ = static_cast<const ModelRequest&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t ModelRequest::ByteSizeLong() const {
          const ModelRequest& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:ModelRequest)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

           {
            // string modelName = 1;
            if (!this_._internal_modelname().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_modelname());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void ModelRequest::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<ModelRequest*>(&to_msg);
  auto& from = static_cast<const ModelRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:ModelRequest)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_modelname().empty()) {
    _this->_internal_set_modelname(from._internal_modelname());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void ModelRequest::CopyFrom(const ModelRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ModelRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void ModelRequest::InternalSwap(ModelRequest* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.modelname_, &other->_impl_.modelname_, arena);
}

::google::protobuf::Metadata ModelRequest::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class ModelReply::_Internal {
 public:
};

ModelReply::ModelReply(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:ModelReply)
}
inline PROTOBUF_NDEBUG_INLINE ModelReply::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::ModelReply& from_msg)
      : objfile_(arena, from.objfile_),
        texture_(arena, from.texture_),
        _cached_size_{0} {}

ModelReply::ModelReply(
    ::google::protobuf::Arena* arena,
    const ModelReply& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  ModelReply* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, texwidth_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, texwidth_),
           offsetof(Impl_, texheight_) -
               offsetof(Impl_, texwidth_) +
               sizeof(Impl_::texheight_));

  // @@protoc_insertion_point(copy_constructor:ModelReply)
}
inline PROTOBUF_NDEBUG_INLINE ModelReply::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : objfile_(arena),
        texture_(arena),
        _cached_size_{0} {}

inline void ModelReply::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, texwidth_),
           0,
           offsetof(Impl_, texheight_) -
               offsetof(Impl_, texwidth_) +
               sizeof(Impl_::texheight_));
}
ModelReply::~ModelReply() {
  // @@protoc_insertion_point(destructor:ModelReply)
  SharedDtor(*this);
}
inline void ModelReply::SharedDtor(MessageLite& self) {
  ModelReply& this_ = static_cast<ModelReply&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.objfile_.Destroy();
  this_._impl_.texture_.Destroy();
  this_._impl_.~Impl_();
}

inline void* ModelReply::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) ModelReply(arena);
}
constexpr auto ModelReply::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::CopyInit(sizeof(ModelReply),
                                            alignof(ModelReply));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull ModelReply::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_ModelReply_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &ModelReply::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<ModelReply>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &ModelReply::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<ModelReply>(), &ModelReply::ByteSizeLong,
            &ModelReply::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(ModelReply, _impl_._cached_size_),
        false,
    },
    &ModelReply::kDescriptorMethods,
    &descriptor_table_modelLoader_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* ModelReply::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<2, 4, 0, 26, 2> ModelReply::_table_ = {
  {
    0,  // no _has_bits_
    0, // no _extensions_
    4, 24,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967280,  // skipmap
    offsetof(decltype(_table_), field_entries),
    4,  // num_field_entries
    0,  // num_aux_entries
    offsetof(decltype(_table_), field_names),  // no aux_entries
    _class_data_.base(),
    nullptr,  // post_loop_handler
    ::_pbi::TcParser::GenericFallback,  // fallback
    #ifdef PROTOBUF_PREFETCH_PARSE_TABLE
    ::_pbi::TcParser::GetTable<::ModelReply>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // bytes texture = 4;
    {::_pbi::TcParser::FastBS1,
     {34, 63, 0, PROTOBUF_FIELD_OFFSET(ModelReply, _impl_.texture_)}},
    // string objFile = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(ModelReply, _impl_.objfile_)}},
    // int32 texWidth = 2;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(ModelReply, _impl_.texwidth_), 63>(),
     {16, 63, 0, PROTOBUF_FIELD_OFFSET(ModelReply, _impl_.texwidth_)}},
    // int32 texHeight = 3;
    {::_pbi::TcParser::SingularVarintNoZag1<::uint32_t, offsetof(ModelReply, _impl_.texheight_), 63>(),
     {24, 63, 0, PROTOBUF_FIELD_OFFSET(ModelReply, _impl_.texheight_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string objFile = 1;
    {PROTOBUF_FIELD_OFFSET(ModelReply, _impl_.objfile_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // int32 texWidth = 2;
    {PROTOBUF_FIELD_OFFSET(ModelReply, _impl_.texwidth_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // int32 texHeight = 3;
    {PROTOBUF_FIELD_OFFSET(ModelReply, _impl_.texheight_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kInt32)},
    // bytes texture = 4;
    {PROTOBUF_FIELD_OFFSET(ModelReply, _impl_.texture_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBytes | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\12\7\0\0\0\0\0\0"
    "ModelReply"
    "objFile"
  }},
};

PROTOBUF_NOINLINE void ModelReply::Clear() {
// @@protoc_insertion_point(message_clear_start:ModelReply)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.objfile_.ClearToEmpty();
  _impl_.texture_.ClearToEmpty();
  ::memset(&_impl_.texwidth_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.texheight_) -
      reinterpret_cast<char*>(&_impl_.texwidth_)) + sizeof(_impl_.texheight_));
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* ModelReply::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const ModelReply& this_ = static_cast<const ModelReply&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* ModelReply::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const ModelReply& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:ModelReply)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // string objFile = 1;
          if (!this_._internal_objfile().empty()) {
            const std::string& _s = this_._internal_objfile();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "ModelReply.objFile");
            target = stream->WriteStringMaybeAliased(1, _s, target);
          }

          // int32 texWidth = 2;
          if (this_._internal_texwidth() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt32ToArrayWithField<2>(
                    stream, this_._internal_texwidth(), target);
          }

          // int32 texHeight = 3;
          if (this_._internal_texheight() != 0) {
            target = ::google::protobuf::internal::WireFormatLite::
                WriteInt32ToArrayWithField<3>(
                    stream, this_._internal_texheight(), target);
          }

          // bytes texture = 4;
          if (!this_._internal_texture().empty()) {
            const std::string& _s = this_._internal_texture();
            target = stream->WriteBytesMaybeAliased(4, _s, target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:ModelReply)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t ModelReply::ByteSizeLong(const MessageLite& base) {
          const ModelReply& this_ = static_cast<const ModelReply&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t ModelReply::ByteSizeLong() const {
          const ModelReply& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:ModelReply)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

          ::_pbi::Prefetch5LinesFrom7Lines(&this_);
           {
            // string objFile = 1;
            if (!this_._internal_objfile().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_objfile());
            }
            // bytes texture = 4;
            if (!this_._internal_texture().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::BytesSize(
                                              this_._internal_texture());
            }
            // int32 texWidth = 2;
            if (this_._internal_texwidth() != 0) {
              total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
                  this_._internal_texwidth());
            }
            // int32 texHeight = 3;
            if (this_._internal_texheight() != 0) {
              total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(
                  this_._internal_texheight());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void ModelReply::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<ModelReply*>(&to_msg);
  auto& from = static_cast<const ModelReply&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:ModelReply)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_objfile().empty()) {
    _this->_internal_set_objfile(from._internal_objfile());
  }
  if (!from._internal_texture().empty()) {
    _this->_internal_set_texture(from._internal_texture());
  }
  if (from._internal_texwidth() != 0) {
    _this->_impl_.texwidth_ = from._impl_.texwidth_;
  }
  if (from._internal_texheight() != 0) {
    _this->_impl_.texheight_ = from._impl_.texheight_;
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void ModelReply::CopyFrom(const ModelReply& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ModelReply)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void ModelReply::InternalSwap(ModelReply* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.objfile_, &other->_impl_.objfile_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.texture_, &other->_impl_.texture_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ModelReply, _impl_.texheight_)
      + sizeof(ModelReply::_impl_.texheight_)
      - PROTOBUF_FIELD_OFFSET(ModelReply, _impl_.texwidth_)>(
          reinterpret_cast<char*>(&_impl_.texwidth_),
          reinterpret_cast<char*>(&other->_impl_.texwidth_));
}

::google::protobuf::Metadata ModelReply::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// @@protoc_insertion_point(namespace_scope)
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::std::false_type
    _static_init2_ PROTOBUF_UNUSED =
        (::_pbi::AddDescriptors(&descriptor_table_modelLoader_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
