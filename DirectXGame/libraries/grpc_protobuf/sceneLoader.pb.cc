// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: sceneLoader.proto
// Protobuf C++ Version: 5.29.1

#include "sceneLoader.pb.h"

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

inline constexpr SceneRequest::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : scenename_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR SceneRequest::SceneRequest(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct SceneRequestDefaultTypeInternal {
  PROTOBUF_CONSTEXPR SceneRequestDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~SceneRequestDefaultTypeInternal() {}
  union {
    SceneRequest _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 SceneRequestDefaultTypeInternal _SceneRequest_default_instance_;

inline constexpr SceneReply::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : scenefile_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        _cached_size_{0} {}

template <typename>
PROTOBUF_CONSTEXPR SceneReply::SceneReply(::_pbi::ConstantInitialized)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(_class_data_.base()),
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(),
#endif  // PROTOBUF_CUSTOM_VTABLE
      _impl_(::_pbi::ConstantInitialized()) {
}
struct SceneReplyDefaultTypeInternal {
  PROTOBUF_CONSTEXPR SceneReplyDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~SceneReplyDefaultTypeInternal() {}
  union {
    SceneReply _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 SceneReplyDefaultTypeInternal _SceneReply_default_instance_;
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_sceneLoader_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_sceneLoader_2eproto = nullptr;
const ::uint32_t
    TableStruct_sceneLoader_2eproto::offsets[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
        protodesc_cold) = {
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::SceneRequest, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::SceneRequest, _impl_.scenename_),
        ~0u,  // no _has_bits_
        PROTOBUF_FIELD_OFFSET(::SceneReply, _internal_metadata_),
        ~0u,  // no _extensions_
        ~0u,  // no _oneof_case_
        ~0u,  // no _weak_field_map_
        ~0u,  // no _inlined_string_donated_
        ~0u,  // no _split_
        ~0u,  // no sizeof(Split)
        PROTOBUF_FIELD_OFFSET(::SceneReply, _impl_.scenefile_),
};

static const ::_pbi::MigrationSchema
    schemas[] ABSL_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
        {0, -1, -1, sizeof(::SceneRequest)},
        {9, -1, -1, sizeof(::SceneReply)},
};
static const ::_pb::Message* const file_default_instances[] = {
    &::_SceneRequest_default_instance_._instance,
    &::_SceneReply_default_instance_._instance,
};
const char descriptor_table_protodef_sceneLoader_2eproto[] ABSL_ATTRIBUTE_SECTION_VARIABLE(
    protodesc_cold) = {
    "\n\021sceneLoader.proto\"!\n\014SceneRequest\022\021\n\ts"
    "ceneName\030\001 \001(\t\"\037\n\nSceneReply\022\021\n\tsceneFil"
    "e\030\001 \001(\t27\n\013SceneLoader\022(\n\010GetScene\022\r.Sce"
    "neRequest\032\013.SceneReply\"\000b\006proto3"
};
static ::absl::once_flag descriptor_table_sceneLoader_2eproto_once;
PROTOBUF_CONSTINIT const ::_pbi::DescriptorTable descriptor_table_sceneLoader_2eproto = {
    false,
    false,
    152,
    descriptor_table_protodef_sceneLoader_2eproto,
    "sceneLoader.proto",
    &descriptor_table_sceneLoader_2eproto_once,
    nullptr,
    0,
    2,
    schemas,
    file_default_instances,
    TableStruct_sceneLoader_2eproto::offsets,
    file_level_enum_descriptors_sceneLoader_2eproto,
    file_level_service_descriptors_sceneLoader_2eproto,
};
// ===================================================================

class SceneRequest::_Internal {
 public:
};

SceneRequest::SceneRequest(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:SceneRequest)
}
inline PROTOBUF_NDEBUG_INLINE SceneRequest::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::SceneRequest& from_msg)
      : scenename_(arena, from.scenename_),
        _cached_size_{0} {}

SceneRequest::SceneRequest(
    ::google::protobuf::Arena* arena,
    const SceneRequest& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SceneRequest* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:SceneRequest)
}
inline PROTOBUF_NDEBUG_INLINE SceneRequest::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : scenename_(arena),
        _cached_size_{0} {}

inline void SceneRequest::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
SceneRequest::~SceneRequest() {
  // @@protoc_insertion_point(destructor:SceneRequest)
  SharedDtor(*this);
}
inline void SceneRequest::SharedDtor(MessageLite& self) {
  SceneRequest& this_ = static_cast<SceneRequest&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.scenename_.Destroy();
  this_._impl_.~Impl_();
}

inline void* SceneRequest::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) SceneRequest(arena);
}
constexpr auto SceneRequest::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::CopyInit(sizeof(SceneRequest),
                                            alignof(SceneRequest));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull SceneRequest::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_SceneRequest_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &SceneRequest::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<SceneRequest>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &SceneRequest::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<SceneRequest>(), &SceneRequest::ByteSizeLong,
            &SceneRequest::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(SceneRequest, _impl_._cached_size_),
        false,
    },
    &SceneRequest::kDescriptorMethods,
    &descriptor_table_sceneLoader_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* SceneRequest::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 30, 2> SceneRequest::_table_ = {
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
    ::_pbi::TcParser::GetTable<::SceneRequest>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string sceneName = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(SceneRequest, _impl_.scenename_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string sceneName = 1;
    {PROTOBUF_FIELD_OFFSET(SceneRequest, _impl_.scenename_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\14\11\0\0\0\0\0\0"
    "SceneRequest"
    "sceneName"
  }},
};

PROTOBUF_NOINLINE void SceneRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:SceneRequest)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.scenename_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* SceneRequest::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const SceneRequest& this_ = static_cast<const SceneRequest&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* SceneRequest::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const SceneRequest& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:SceneRequest)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // string sceneName = 1;
          if (!this_._internal_scenename().empty()) {
            const std::string& _s = this_._internal_scenename();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "SceneRequest.sceneName");
            target = stream->WriteStringMaybeAliased(1, _s, target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:SceneRequest)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t SceneRequest::ByteSizeLong(const MessageLite& base) {
          const SceneRequest& this_ = static_cast<const SceneRequest&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t SceneRequest::ByteSizeLong() const {
          const SceneRequest& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:SceneRequest)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

           {
            // string sceneName = 1;
            if (!this_._internal_scenename().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_scenename());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void SceneRequest::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<SceneRequest*>(&to_msg);
  auto& from = static_cast<const SceneRequest&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:SceneRequest)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_scenename().empty()) {
    _this->_internal_set_scenename(from._internal_scenename());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void SceneRequest::CopyFrom(const SceneRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:SceneRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void SceneRequest::InternalSwap(SceneRequest* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.scenename_, &other->_impl_.scenename_, arena);
}

::google::protobuf::Metadata SceneRequest::GetMetadata() const {
  return ::google::protobuf::Message::GetMetadataImpl(GetClassData()->full());
}
// ===================================================================

class SceneReply::_Internal {
 public:
};

SceneReply::SceneReply(::google::protobuf::Arena* arena)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:SceneReply)
}
inline PROTOBUF_NDEBUG_INLINE SceneReply::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from, const ::SceneReply& from_msg)
      : scenefile_(arena, from.scenefile_),
        _cached_size_{0} {}

SceneReply::SceneReply(
    ::google::protobuf::Arena* arena,
    const SceneReply& from)
#if defined(PROTOBUF_CUSTOM_VTABLE)
    : ::google::protobuf::Message(arena, _class_data_.base()) {
#else   // PROTOBUF_CUSTOM_VTABLE
    : ::google::protobuf::Message(arena) {
#endif  // PROTOBUF_CUSTOM_VTABLE
  SceneReply* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_, from);

  // @@protoc_insertion_point(copy_constructor:SceneReply)
}
inline PROTOBUF_NDEBUG_INLINE SceneReply::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : scenefile_(arena),
        _cached_size_{0} {}

inline void SceneReply::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
}
SceneReply::~SceneReply() {
  // @@protoc_insertion_point(destructor:SceneReply)
  SharedDtor(*this);
}
inline void SceneReply::SharedDtor(MessageLite& self) {
  SceneReply& this_ = static_cast<SceneReply&>(self);
  this_._internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  ABSL_DCHECK(this_.GetArena() == nullptr);
  this_._impl_.scenefile_.Destroy();
  this_._impl_.~Impl_();
}

inline void* SceneReply::PlacementNew_(const void*, void* mem,
                                        ::google::protobuf::Arena* arena) {
  return ::new (mem) SceneReply(arena);
}
constexpr auto SceneReply::InternalNewImpl_() {
  return ::google::protobuf::internal::MessageCreator::CopyInit(sizeof(SceneReply),
                                            alignof(SceneReply));
}
PROTOBUF_CONSTINIT
PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::google::protobuf::internal::ClassDataFull SceneReply::_class_data_ = {
    ::google::protobuf::internal::ClassData{
        &_SceneReply_default_instance_._instance,
        &_table_.header,
        nullptr,  // OnDemandRegisterArenaDtor
        nullptr,  // IsInitialized
        &SceneReply::MergeImpl,
        ::google::protobuf::Message::GetNewImpl<SceneReply>(),
#if defined(PROTOBUF_CUSTOM_VTABLE)
        &SceneReply::SharedDtor,
        ::google::protobuf::Message::GetClearImpl<SceneReply>(), &SceneReply::ByteSizeLong,
            &SceneReply::_InternalSerialize,
#endif  // PROTOBUF_CUSTOM_VTABLE
        PROTOBUF_FIELD_OFFSET(SceneReply, _impl_._cached_size_),
        false,
    },
    &SceneReply::kDescriptorMethods,
    &descriptor_table_sceneLoader_2eproto,
    nullptr,  // tracker
};
const ::google::protobuf::internal::ClassData* SceneReply::GetClassData() const {
  ::google::protobuf::internal::PrefetchToLocalCache(&_class_data_);
  ::google::protobuf::internal::PrefetchToLocalCache(_class_data_.tc_table);
  return _class_data_.base();
}
PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<0, 1, 0, 28, 2> SceneReply::_table_ = {
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
    ::_pbi::TcParser::GetTable<::SceneReply>(),  // to_prefetch
    #endif  // PROTOBUF_PREFETCH_PARSE_TABLE
  }, {{
    // string sceneFile = 1;
    {::_pbi::TcParser::FastUS1,
     {10, 63, 0, PROTOBUF_FIELD_OFFSET(SceneReply, _impl_.scenefile_)}},
  }}, {{
    65535, 65535
  }}, {{
    // string sceneFile = 1;
    {PROTOBUF_FIELD_OFFSET(SceneReply, _impl_.scenefile_), 0, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }},
  // no aux_entries
  {{
    "\12\11\0\0\0\0\0\0"
    "SceneReply"
    "sceneFile"
  }},
};

PROTOBUF_NOINLINE void SceneReply::Clear() {
// @@protoc_insertion_point(message_clear_start:SceneReply)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.scenefile_.ClearToEmpty();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::uint8_t* SceneReply::_InternalSerialize(
            const MessageLite& base, ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) {
          const SceneReply& this_ = static_cast<const SceneReply&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::uint8_t* SceneReply::_InternalSerialize(
            ::uint8_t* target,
            ::google::protobuf::io::EpsCopyOutputStream* stream) const {
          const SceneReply& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(serialize_to_array_start:SceneReply)
          ::uint32_t cached_has_bits = 0;
          (void)cached_has_bits;

          // string sceneFile = 1;
          if (!this_._internal_scenefile().empty()) {
            const std::string& _s = this_._internal_scenefile();
            ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
                _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "SceneReply.sceneFile");
            target = stream->WriteStringMaybeAliased(1, _s, target);
          }

          if (PROTOBUF_PREDICT_FALSE(this_._internal_metadata_.have_unknown_fields())) {
            target =
                ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
                    this_._internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
          }
          // @@protoc_insertion_point(serialize_to_array_end:SceneReply)
          return target;
        }

#if defined(PROTOBUF_CUSTOM_VTABLE)
        ::size_t SceneReply::ByteSizeLong(const MessageLite& base) {
          const SceneReply& this_ = static_cast<const SceneReply&>(base);
#else   // PROTOBUF_CUSTOM_VTABLE
        ::size_t SceneReply::ByteSizeLong() const {
          const SceneReply& this_ = *this;
#endif  // PROTOBUF_CUSTOM_VTABLE
          // @@protoc_insertion_point(message_byte_size_start:SceneReply)
          ::size_t total_size = 0;

          ::uint32_t cached_has_bits = 0;
          // Prevent compiler warnings about cached_has_bits being unused
          (void)cached_has_bits;

           {
            // string sceneFile = 1;
            if (!this_._internal_scenefile().empty()) {
              total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                              this_._internal_scenefile());
            }
          }
          return this_.MaybeComputeUnknownFieldsSize(total_size,
                                                     &this_._impl_._cached_size_);
        }

void SceneReply::MergeImpl(::google::protobuf::MessageLite& to_msg, const ::google::protobuf::MessageLite& from_msg) {
  auto* const _this = static_cast<SceneReply*>(&to_msg);
  auto& from = static_cast<const SceneReply&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:SceneReply)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_scenefile().empty()) {
    _this->_internal_set_scenefile(from._internal_scenefile());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void SceneReply::CopyFrom(const SceneReply& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:SceneReply)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}


void SceneReply::InternalSwap(SceneReply* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.scenefile_, &other->_impl_.scenefile_, arena);
}

::google::protobuf::Metadata SceneReply::GetMetadata() const {
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
        (::_pbi::AddDescriptors(&descriptor_table_sceneLoader_2eproto),
         ::std::false_type{});
#include "google/protobuf/port_undef.inc"
