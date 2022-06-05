// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: serverpacket.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_serverpacket_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_serverpacket_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_serverpacket_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_serverpacket_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_serverpacket_2eproto;
class ServerPacket;
struct ServerPacketDefaultTypeInternal;
extern ServerPacketDefaultTypeInternal _ServerPacket_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::ServerPacket* Arena::CreateMaybeMessage<::ServerPacket>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

enum ServerPacket_GameState : int {
  ServerPacket_GameState_GAME_MENU = 0,
  ServerPacket_GameState_GAME_START = 1,
  ServerPacket_GameState_GAME_PLAY = 2,
  ServerPacket_GameState_GAME_OVER = 3,
  ServerPacket_GameState_GAME_QUIT = 4
};
bool ServerPacket_GameState_IsValid(int value);
constexpr ServerPacket_GameState ServerPacket_GameState_GameState_MIN = ServerPacket_GameState_GAME_MENU;
constexpr ServerPacket_GameState ServerPacket_GameState_GameState_MAX = ServerPacket_GameState_GAME_QUIT;
constexpr int ServerPacket_GameState_GameState_ARRAYSIZE = ServerPacket_GameState_GameState_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ServerPacket_GameState_descriptor();
template<typename T>
inline const std::string& ServerPacket_GameState_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ServerPacket_GameState>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ServerPacket_GameState_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ServerPacket_GameState_descriptor(), enum_t_value);
}
inline bool ServerPacket_GameState_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ServerPacket_GameState* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ServerPacket_GameState>(
    ServerPacket_GameState_descriptor(), name, value);
}
// ===================================================================

class ServerPacket final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ServerPacket) */ {
 public:
  inline ServerPacket() : ServerPacket(nullptr) {}
  ~ServerPacket() override;
  explicit PROTOBUF_CONSTEXPR ServerPacket(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  ServerPacket(const ServerPacket& from);
  ServerPacket(ServerPacket&& from) noexcept
    : ServerPacket() {
    *this = ::std::move(from);
  }

  inline ServerPacket& operator=(const ServerPacket& from) {
    CopyFrom(from);
    return *this;
  }
  inline ServerPacket& operator=(ServerPacket&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const ServerPacket& default_instance() {
    return *internal_default_instance();
  }
  static inline const ServerPacket* internal_default_instance() {
    return reinterpret_cast<const ServerPacket*>(
               &_ServerPacket_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ServerPacket& a, ServerPacket& b) {
    a.Swap(&b);
  }
  inline void Swap(ServerPacket* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(ServerPacket* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  ServerPacket* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<ServerPacket>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const ServerPacket& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const ServerPacket& from) {
    ServerPacket::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ServerPacket* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ServerPacket";
  }
  protected:
  explicit ServerPacket(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef ServerPacket_GameState GameState;
  static constexpr GameState GAME_MENU =
    ServerPacket_GameState_GAME_MENU;
  static constexpr GameState GAME_START =
    ServerPacket_GameState_GAME_START;
  static constexpr GameState GAME_PLAY =
    ServerPacket_GameState_GAME_PLAY;
  static constexpr GameState GAME_OVER =
    ServerPacket_GameState_GAME_OVER;
  static constexpr GameState GAME_QUIT =
    ServerPacket_GameState_GAME_QUIT;
  static inline bool GameState_IsValid(int value) {
    return ServerPacket_GameState_IsValid(value);
  }
  static constexpr GameState GameState_MIN =
    ServerPacket_GameState_GameState_MIN;
  static constexpr GameState GameState_MAX =
    ServerPacket_GameState_GameState_MAX;
  static constexpr int GameState_ARRAYSIZE =
    ServerPacket_GameState_GameState_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  GameState_descriptor() {
    return ServerPacket_GameState_descriptor();
  }
  template<typename T>
  static inline const std::string& GameState_Name(T enum_t_value) {
    static_assert(::std::is_same<T, GameState>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function GameState_Name.");
    return ServerPacket_GameState_Name(enum_t_value);
  }
  static inline bool GameState_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      GameState* value) {
    return ServerPacket_GameState_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kBallXFieldNumber = 1,
    kBallYFieldNumber = 2,
    kPaddleXFieldNumber = 3,
    kPaddleYFieldNumber = 4,
    kClientScoreFieldNumber = 5,
    kEnemyScoreFieldNumber = 6,
    kGameStateFieldNumber = 7,
  };
  // required int32 ballX = 1;
  bool has_ballx() const;
  private:
  bool _internal_has_ballx() const;
  public:
  void clear_ballx();
  int32_t ballx() const;
  void set_ballx(int32_t value);
  private:
  int32_t _internal_ballx() const;
  void _internal_set_ballx(int32_t value);
  public:

  // required int32 ballY = 2;
  bool has_bally() const;
  private:
  bool _internal_has_bally() const;
  public:
  void clear_bally();
  int32_t bally() const;
  void set_bally(int32_t value);
  private:
  int32_t _internal_bally() const;
  void _internal_set_bally(int32_t value);
  public:

  // required int32 paddleX = 3;
  bool has_paddlex() const;
  private:
  bool _internal_has_paddlex() const;
  public:
  void clear_paddlex();
  int32_t paddlex() const;
  void set_paddlex(int32_t value);
  private:
  int32_t _internal_paddlex() const;
  void _internal_set_paddlex(int32_t value);
  public:

  // required int32 paddleY = 4;
  bool has_paddley() const;
  private:
  bool _internal_has_paddley() const;
  public:
  void clear_paddley();
  int32_t paddley() const;
  void set_paddley(int32_t value);
  private:
  int32_t _internal_paddley() const;
  void _internal_set_paddley(int32_t value);
  public:

  // required int32 clientScore = 5;
  bool has_clientscore() const;
  private:
  bool _internal_has_clientscore() const;
  public:
  void clear_clientscore();
  int32_t clientscore() const;
  void set_clientscore(int32_t value);
  private:
  int32_t _internal_clientscore() const;
  void _internal_set_clientscore(int32_t value);
  public:

  // required int32 enemyScore = 6;
  bool has_enemyscore() const;
  private:
  bool _internal_has_enemyscore() const;
  public:
  void clear_enemyscore();
  int32_t enemyscore() const;
  void set_enemyscore(int32_t value);
  private:
  int32_t _internal_enemyscore() const;
  void _internal_set_enemyscore(int32_t value);
  public:

  // required .ServerPacket.GameState gameState = 7;
  bool has_gamestate() const;
  private:
  bool _internal_has_gamestate() const;
  public:
  void clear_gamestate();
  ::ServerPacket_GameState gamestate() const;
  void set_gamestate(::ServerPacket_GameState value);
  private:
  ::ServerPacket_GameState _internal_gamestate() const;
  void _internal_set_gamestate(::ServerPacket_GameState value);
  public:

  // @@protoc_insertion_point(class_scope:ServerPacket)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    int32_t ballx_;
    int32_t bally_;
    int32_t paddlex_;
    int32_t paddley_;
    int32_t clientscore_;
    int32_t enemyscore_;
    int gamestate_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_serverpacket_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ServerPacket

// required int32 ballX = 1;
inline bool ServerPacket::_internal_has_ballx() const {
  bool value = (_impl_._has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ServerPacket::has_ballx() const {
  return _internal_has_ballx();
}
inline void ServerPacket::clear_ballx() {
  _impl_.ballx_ = 0;
  _impl_._has_bits_[0] &= ~0x00000001u;
}
inline int32_t ServerPacket::_internal_ballx() const {
  return _impl_.ballx_;
}
inline int32_t ServerPacket::ballx() const {
  // @@protoc_insertion_point(field_get:ServerPacket.ballX)
  return _internal_ballx();
}
inline void ServerPacket::_internal_set_ballx(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000001u;
  _impl_.ballx_ = value;
}
inline void ServerPacket::set_ballx(int32_t value) {
  _internal_set_ballx(value);
  // @@protoc_insertion_point(field_set:ServerPacket.ballX)
}

// required int32 ballY = 2;
inline bool ServerPacket::_internal_has_bally() const {
  bool value = (_impl_._has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ServerPacket::has_bally() const {
  return _internal_has_bally();
}
inline void ServerPacket::clear_bally() {
  _impl_.bally_ = 0;
  _impl_._has_bits_[0] &= ~0x00000002u;
}
inline int32_t ServerPacket::_internal_bally() const {
  return _impl_.bally_;
}
inline int32_t ServerPacket::bally() const {
  // @@protoc_insertion_point(field_get:ServerPacket.ballY)
  return _internal_bally();
}
inline void ServerPacket::_internal_set_bally(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000002u;
  _impl_.bally_ = value;
}
inline void ServerPacket::set_bally(int32_t value) {
  _internal_set_bally(value);
  // @@protoc_insertion_point(field_set:ServerPacket.ballY)
}

// required int32 paddleX = 3;
inline bool ServerPacket::_internal_has_paddlex() const {
  bool value = (_impl_._has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool ServerPacket::has_paddlex() const {
  return _internal_has_paddlex();
}
inline void ServerPacket::clear_paddlex() {
  _impl_.paddlex_ = 0;
  _impl_._has_bits_[0] &= ~0x00000004u;
}
inline int32_t ServerPacket::_internal_paddlex() const {
  return _impl_.paddlex_;
}
inline int32_t ServerPacket::paddlex() const {
  // @@protoc_insertion_point(field_get:ServerPacket.paddleX)
  return _internal_paddlex();
}
inline void ServerPacket::_internal_set_paddlex(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000004u;
  _impl_.paddlex_ = value;
}
inline void ServerPacket::set_paddlex(int32_t value) {
  _internal_set_paddlex(value);
  // @@protoc_insertion_point(field_set:ServerPacket.paddleX)
}

// required int32 paddleY = 4;
inline bool ServerPacket::_internal_has_paddley() const {
  bool value = (_impl_._has_bits_[0] & 0x00000008u) != 0;
  return value;
}
inline bool ServerPacket::has_paddley() const {
  return _internal_has_paddley();
}
inline void ServerPacket::clear_paddley() {
  _impl_.paddley_ = 0;
  _impl_._has_bits_[0] &= ~0x00000008u;
}
inline int32_t ServerPacket::_internal_paddley() const {
  return _impl_.paddley_;
}
inline int32_t ServerPacket::paddley() const {
  // @@protoc_insertion_point(field_get:ServerPacket.paddleY)
  return _internal_paddley();
}
inline void ServerPacket::_internal_set_paddley(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000008u;
  _impl_.paddley_ = value;
}
inline void ServerPacket::set_paddley(int32_t value) {
  _internal_set_paddley(value);
  // @@protoc_insertion_point(field_set:ServerPacket.paddleY)
}

// required int32 clientScore = 5;
inline bool ServerPacket::_internal_has_clientscore() const {
  bool value = (_impl_._has_bits_[0] & 0x00000010u) != 0;
  return value;
}
inline bool ServerPacket::has_clientscore() const {
  return _internal_has_clientscore();
}
inline void ServerPacket::clear_clientscore() {
  _impl_.clientscore_ = 0;
  _impl_._has_bits_[0] &= ~0x00000010u;
}
inline int32_t ServerPacket::_internal_clientscore() const {
  return _impl_.clientscore_;
}
inline int32_t ServerPacket::clientscore() const {
  // @@protoc_insertion_point(field_get:ServerPacket.clientScore)
  return _internal_clientscore();
}
inline void ServerPacket::_internal_set_clientscore(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000010u;
  _impl_.clientscore_ = value;
}
inline void ServerPacket::set_clientscore(int32_t value) {
  _internal_set_clientscore(value);
  // @@protoc_insertion_point(field_set:ServerPacket.clientScore)
}

// required int32 enemyScore = 6;
inline bool ServerPacket::_internal_has_enemyscore() const {
  bool value = (_impl_._has_bits_[0] & 0x00000020u) != 0;
  return value;
}
inline bool ServerPacket::has_enemyscore() const {
  return _internal_has_enemyscore();
}
inline void ServerPacket::clear_enemyscore() {
  _impl_.enemyscore_ = 0;
  _impl_._has_bits_[0] &= ~0x00000020u;
}
inline int32_t ServerPacket::_internal_enemyscore() const {
  return _impl_.enemyscore_;
}
inline int32_t ServerPacket::enemyscore() const {
  // @@protoc_insertion_point(field_get:ServerPacket.enemyScore)
  return _internal_enemyscore();
}
inline void ServerPacket::_internal_set_enemyscore(int32_t value) {
  _impl_._has_bits_[0] |= 0x00000020u;
  _impl_.enemyscore_ = value;
}
inline void ServerPacket::set_enemyscore(int32_t value) {
  _internal_set_enemyscore(value);
  // @@protoc_insertion_point(field_set:ServerPacket.enemyScore)
}

// required .ServerPacket.GameState gameState = 7;
inline bool ServerPacket::_internal_has_gamestate() const {
  bool value = (_impl_._has_bits_[0] & 0x00000040u) != 0;
  return value;
}
inline bool ServerPacket::has_gamestate() const {
  return _internal_has_gamestate();
}
inline void ServerPacket::clear_gamestate() {
  _impl_.gamestate_ = 0;
  _impl_._has_bits_[0] &= ~0x00000040u;
}
inline ::ServerPacket_GameState ServerPacket::_internal_gamestate() const {
  return static_cast< ::ServerPacket_GameState >(_impl_.gamestate_);
}
inline ::ServerPacket_GameState ServerPacket::gamestate() const {
  // @@protoc_insertion_point(field_get:ServerPacket.gameState)
  return _internal_gamestate();
}
inline void ServerPacket::_internal_set_gamestate(::ServerPacket_GameState value) {
  assert(::ServerPacket_GameState_IsValid(value));
  _impl_._has_bits_[0] |= 0x00000040u;
  _impl_.gamestate_ = value;
}
inline void ServerPacket::set_gamestate(::ServerPacket_GameState value) {
  _internal_set_gamestate(value);
  // @@protoc_insertion_point(field_set:ServerPacket.gameState)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::ServerPacket_GameState> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::ServerPacket_GameState>() {
  return ::ServerPacket_GameState_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_serverpacket_2eproto
