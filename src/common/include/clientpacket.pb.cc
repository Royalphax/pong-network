// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: clientpacket.proto

#include "clientpacket.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

PROTOBUF_CONSTEXPR ClientPacket::ClientPacket(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_._has_bits_)*/{}
  , /*decltype(_impl_._cached_size_)*/{}
  , /*decltype(_impl_.name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.id_)*/0
  , /*decltype(_impl_.paddledir_)*/0} {}
struct ClientPacketDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ClientPacketDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ClientPacketDefaultTypeInternal() {}
  union {
    ClientPacket _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ClientPacketDefaultTypeInternal _ClientPacket_default_instance_;
static ::_pb::Metadata file_level_metadata_clientpacket_2eproto[1];
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_clientpacket_2eproto[1];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_clientpacket_2eproto = nullptr;

const uint32_t TableStruct_clientpacket_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  PROTOBUF_FIELD_OFFSET(::ClientPacket, _impl_._has_bits_),
  PROTOBUF_FIELD_OFFSET(::ClientPacket, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ClientPacket, _impl_.id_),
  PROTOBUF_FIELD_OFFSET(::ClientPacket, _impl_.name_),
  PROTOBUF_FIELD_OFFSET(::ClientPacket, _impl_.paddledir_),
  1,
  0,
  2,
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, 9, -1, sizeof(::ClientPacket)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::_ClientPacket_default_instance_._instance,
};

const char descriptor_table_protodef_clientpacket_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\022clientpacket.proto\"\235\001\n\014ClientPacket\022\n\n"
  "\002id\030\001 \002(\005\022\014\n\004name\030\002 \002(\t\0226\n\tpaddleDir\030\003 \001"
  "(\0162\035.ClientPacket.PaddleDirection:\004NONE\""
  ";\n\017PaddleDirection\022\010\n\004NONE\020\000\022\017\n\013PADDLE_D"
  "OWN\020\001\022\r\n\tPADDLE_UP\020\002"
  ;
static ::_pbi::once_flag descriptor_table_clientpacket_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_clientpacket_2eproto = {
    false, false, 180, descriptor_table_protodef_clientpacket_2eproto,
    "clientpacket.proto",
    &descriptor_table_clientpacket_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_clientpacket_2eproto::offsets,
    file_level_metadata_clientpacket_2eproto, file_level_enum_descriptors_clientpacket_2eproto,
    file_level_service_descriptors_clientpacket_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_clientpacket_2eproto_getter() {
  return &descriptor_table_clientpacket_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_clientpacket_2eproto(&descriptor_table_clientpacket_2eproto);
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ClientPacket_PaddleDirection_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_clientpacket_2eproto);
  return file_level_enum_descriptors_clientpacket_2eproto[0];
}
bool ClientPacket_PaddleDirection_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))
constexpr ClientPacket_PaddleDirection ClientPacket::NONE;
constexpr ClientPacket_PaddleDirection ClientPacket::PADDLE_DOWN;
constexpr ClientPacket_PaddleDirection ClientPacket::PADDLE_UP;
constexpr ClientPacket_PaddleDirection ClientPacket::PaddleDirection_MIN;
constexpr ClientPacket_PaddleDirection ClientPacket::PaddleDirection_MAX;
constexpr int ClientPacket::PaddleDirection_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || (_MSC_VER >= 1900 && _MSC_VER < 1912))

// ===================================================================

class ClientPacket::_Internal {
 public:
  using HasBits = decltype(std::declval<ClientPacket>()._impl_._has_bits_);
  static void set_has_id(HasBits* has_bits) {
    (*has_bits)[0] |= 2u;
  }
  static void set_has_name(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
  static void set_has_paddledir(HasBits* has_bits) {
    (*has_bits)[0] |= 4u;
  }
  static bool MissingRequiredFields(const HasBits& has_bits) {
    return ((has_bits[0] & 0x00000003) ^ 0x00000003) != 0;
  }
};

ClientPacket::ClientPacket(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:ClientPacket)
}
ClientPacket::ClientPacket(const ClientPacket& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ClientPacket* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){from._impl_._has_bits_}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.name_){}
    , decltype(_impl_.id_){}
    , decltype(_impl_.paddledir_){}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (from._internal_has_name()) {
    _this->_impl_.name_.Set(from._internal_name(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.id_, &from._impl_.id_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.paddledir_) -
    reinterpret_cast<char*>(&_impl_.id_)) + sizeof(_impl_.paddledir_));
  // @@protoc_insertion_point(copy_constructor:ClientPacket)
}

inline void ClientPacket::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_._has_bits_){}
    , /*decltype(_impl_._cached_size_)*/{}
    , decltype(_impl_.name_){}
    , decltype(_impl_.id_){0}
    , decltype(_impl_.paddledir_){0}
  };
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

ClientPacket::~ClientPacket() {
  // @@protoc_insertion_point(destructor:ClientPacket)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ClientPacket::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.name_.Destroy();
}

void ClientPacket::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ClientPacket::Clear() {
// @@protoc_insertion_point(message_clear_start:ClientPacket)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    _impl_.name_.ClearNonDefaultToEmpty();
  }
  if (cached_has_bits & 0x00000006u) {
    ::memset(&_impl_.id_, 0, static_cast<size_t>(
        reinterpret_cast<char*>(&_impl_.paddledir_) -
        reinterpret_cast<char*>(&_impl_.id_)) + sizeof(_impl_.paddledir_));
  }
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ClientPacket::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  _Internal::HasBits has_bits{};
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // required int32 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _Internal::set_has_id(&has_bits);
          _impl_.id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // required string name = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          #ifndef NDEBUG
          ::_pbi::VerifyUTF8(str, "ClientPacket.name");
          #endif  // !NDEBUG
        } else
          goto handle_unusual;
        continue;
      // optional .ClientPacket.PaddleDirection paddleDir = 3 [default = NONE];
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          uint64_t val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          if (PROTOBUF_PREDICT_TRUE(::ClientPacket_PaddleDirection_IsValid(val))) {
            _internal_set_paddledir(static_cast<::ClientPacket_PaddleDirection>(val));
          } else {
            ::PROTOBUF_NAMESPACE_ID::internal::WriteVarint(3, val, mutable_unknown_fields());
          }
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  _impl_._has_bits_.Or(has_bits);
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ClientPacket::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ClientPacket)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // required int32 id = 1;
  if (cached_has_bits & 0x00000002u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_id(), target);
  }

  // required string name = 2;
  if (cached_has_bits & 0x00000001u) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::VerifyUTF8StringNamedField(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SERIALIZE,
      "ClientPacket.name");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_name(), target);
  }

  // optional .ClientPacket.PaddleDirection paddleDir = 3 [default = NONE];
  if (cached_has_bits & 0x00000004u) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteEnumToArray(
      3, this->_internal_paddledir(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ClientPacket)
  return target;
}

size_t ClientPacket::RequiredFieldsByteSizeFallback() const {
// @@protoc_insertion_point(required_fields_byte_size_fallback_start:ClientPacket)
  size_t total_size = 0;

  if (_internal_has_name()) {
    // required string name = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  if (_internal_has_id()) {
    // required int32 id = 1;
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_id());
  }

  return total_size;
}
size_t ClientPacket::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ClientPacket)
  size_t total_size = 0;

  if (((_impl_._has_bits_[0] & 0x00000003) ^ 0x00000003) == 0) {  // All required fields are present.
    // required string name = 2;
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());

    // required int32 id = 1;
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_id());

  } else {
    total_size += RequiredFieldsByteSizeFallback();
  }
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // optional .ClientPacket.PaddleDirection paddleDir = 3 [default = NONE];
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000004u) {
    total_size += 1 +
      ::_pbi::WireFormatLite::EnumSize(this->_internal_paddledir());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ClientPacket::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ClientPacket::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ClientPacket::GetClassData() const { return &_class_data_; }


void ClientPacket::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ClientPacket*>(&to_msg);
  auto& from = static_cast<const ClientPacket&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:ClientPacket)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  cached_has_bits = from._impl_._has_bits_[0];
  if (cached_has_bits & 0x00000007u) {
    if (cached_has_bits & 0x00000001u) {
      _this->_internal_set_name(from._internal_name());
    }
    if (cached_has_bits & 0x00000002u) {
      _this->_impl_.id_ = from._impl_.id_;
    }
    if (cached_has_bits & 0x00000004u) {
      _this->_impl_.paddledir_ = from._impl_.paddledir_;
    }
    _this->_impl_._has_bits_[0] |= cached_has_bits;
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ClientPacket::CopyFrom(const ClientPacket& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ClientPacket)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ClientPacket::IsInitialized() const {
  if (_Internal::MissingRequiredFields(_impl_._has_bits_)) return false;
  return true;
}

void ClientPacket::InternalSwap(ClientPacket* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.name_, lhs_arena,
      &other->_impl_.name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(ClientPacket, _impl_.paddledir_)
      + sizeof(ClientPacket::_impl_.paddledir_)
      - PROTOBUF_FIELD_OFFSET(ClientPacket, _impl_.id_)>(
          reinterpret_cast<char*>(&_impl_.id_),
          reinterpret_cast<char*>(&other->_impl_.id_));
}

::PROTOBUF_NAMESPACE_ID::Metadata ClientPacket::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_clientpacket_2eproto_getter, &descriptor_table_clientpacket_2eproto_once,
      file_level_metadata_clientpacket_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::ClientPacket*
Arena::CreateMaybeMessage< ::ClientPacket >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ClientPacket >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
