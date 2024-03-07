// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Struct.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Enum.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Struct_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Struct_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Struct_2eproto;
namespace Protocol {
class Player;
struct PlayerDefaultTypeInternal;
extern PlayerDefaultTypeInternal _Player_default_instance_;
}  // namespace Protocol
PROTOBUF_NAMESPACE_OPEN
template<> ::Protocol::Player* Arena::CreateMaybeMessage<::Protocol::Player>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace Protocol {

// ===================================================================

class Player final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:Protocol.Player) */ {
 public:
  inline Player() : Player(nullptr) {}
  ~Player() override;
  explicit constexpr Player(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Player(const Player& from);
  Player(Player&& from) noexcept
    : Player() {
    *this = ::std::move(from);
  }

  inline Player& operator=(const Player& from) {
    CopyFrom(from);
    return *this;
  }
  inline Player& operator=(Player&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
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
  static const Player& default_instance() {
    return *internal_default_instance();
  }
  static inline const Player* internal_default_instance() {
    return reinterpret_cast<const Player*>(
               &_Player_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Player& a, Player& b) {
    a.Swap(&b);
  }
  inline void Swap(Player* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Player* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Player* New() const final {
    return new Player();
  }

  Player* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Player>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Player& from);
  void MergeFrom(const Player& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Player* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "Protocol.Player";
  }
  protected:
  explicit Player(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 2,
    kIdFieldNumber = 1,
    kPlayerTypeFieldNumber = 3,
    kPxFieldNumber = 4,
    kPyFieldNumber = 5,
    kPzFieldNumber = 6,
    kRxFieldNumber = 7,
    kRyFieldNumber = 8,
    kRzFieldNumber = 9,
  };
  // string name = 2;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_FUTURE_MUST_USE_RESULT std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // uint64 id = 1;
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::uint64 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // .Protocol.PlayerType playerType = 3;
  void clear_playertype();
  ::Protocol::PlayerType playertype() const;
  void set_playertype(::Protocol::PlayerType value);
  private:
  ::Protocol::PlayerType _internal_playertype() const;
  void _internal_set_playertype(::Protocol::PlayerType value);
  public:

  // float px = 4;
  void clear_px();
  float px() const;
  void set_px(float value);
  private:
  float _internal_px() const;
  void _internal_set_px(float value);
  public:

  // float py = 5;
  void clear_py();
  float py() const;
  void set_py(float value);
  private:
  float _internal_py() const;
  void _internal_set_py(float value);
  public:

  // float pz = 6;
  void clear_pz();
  float pz() const;
  void set_pz(float value);
  private:
  float _internal_pz() const;
  void _internal_set_pz(float value);
  public:

  // float rx = 7;
  void clear_rx();
  float rx() const;
  void set_rx(float value);
  private:
  float _internal_rx() const;
  void _internal_set_rx(float value);
  public:

  // float ry = 8;
  void clear_ry();
  float ry() const;
  void set_ry(float value);
  private:
  float _internal_ry() const;
  void _internal_set_ry(float value);
  public:

  // float rz = 9;
  void clear_rz();
  float rz() const;
  void set_rz(float value);
  private:
  float _internal_rz() const;
  void _internal_set_rz(float value);
  public:

  // @@protoc_insertion_point(class_scope:Protocol.Player)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::uint64 id_;
  int playertype_;
  float px_;
  float py_;
  float pz_;
  float rx_;
  float ry_;
  float rz_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Struct_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Player

// uint64 id = 1;
inline void Player::clear_id() {
  id_ = uint64_t{0u};
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 Player::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 Player::id() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.id)
  return _internal_id();
}
inline void Player::_internal_set_id(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  id_ = value;
}
inline void Player::set_id(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:Protocol.Player.id)
}

// string name = 2;
inline void Player::clear_name() {
  name_.ClearToEmpty();
}
inline const std::string& Player::name() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void Player::set_name(ArgT0&& arg0, ArgT... args) {
 
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:Protocol.Player.name)
}
inline std::string* Player::mutable_name() {
  // @@protoc_insertion_point(field_mutable:Protocol.Player.name)
  return _internal_mutable_name();
}
inline const std::string& Player::_internal_name() const {
  return name_.Get();
}
inline void Player::_internal_set_name(const std::string& value) {
  
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* Player::_internal_mutable_name() {
  
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* Player::release_name() {
  // @@protoc_insertion_point(field_release:Protocol.Player.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void Player::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:Protocol.Player.name)
}

// .Protocol.PlayerType playerType = 3;
inline void Player::clear_playertype() {
  playertype_ = 0;
}
inline ::Protocol::PlayerType Player::_internal_playertype() const {
  return static_cast< ::Protocol::PlayerType >(playertype_);
}
inline ::Protocol::PlayerType Player::playertype() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.playerType)
  return _internal_playertype();
}
inline void Player::_internal_set_playertype(::Protocol::PlayerType value) {
  
  playertype_ = value;
}
inline void Player::set_playertype(::Protocol::PlayerType value) {
  _internal_set_playertype(value);
  // @@protoc_insertion_point(field_set:Protocol.Player.playerType)
}

// float px = 4;
inline void Player::clear_px() {
  px_ = 0;
}
inline float Player::_internal_px() const {
  return px_;
}
inline float Player::px() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.px)
  return _internal_px();
}
inline void Player::_internal_set_px(float value) {
  
  px_ = value;
}
inline void Player::set_px(float value) {
  _internal_set_px(value);
  // @@protoc_insertion_point(field_set:Protocol.Player.px)
}

// float py = 5;
inline void Player::clear_py() {
  py_ = 0;
}
inline float Player::_internal_py() const {
  return py_;
}
inline float Player::py() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.py)
  return _internal_py();
}
inline void Player::_internal_set_py(float value) {
  
  py_ = value;
}
inline void Player::set_py(float value) {
  _internal_set_py(value);
  // @@protoc_insertion_point(field_set:Protocol.Player.py)
}

// float pz = 6;
inline void Player::clear_pz() {
  pz_ = 0;
}
inline float Player::_internal_pz() const {
  return pz_;
}
inline float Player::pz() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.pz)
  return _internal_pz();
}
inline void Player::_internal_set_pz(float value) {
  
  pz_ = value;
}
inline void Player::set_pz(float value) {
  _internal_set_pz(value);
  // @@protoc_insertion_point(field_set:Protocol.Player.pz)
}

// float rx = 7;
inline void Player::clear_rx() {
  rx_ = 0;
}
inline float Player::_internal_rx() const {
  return rx_;
}
inline float Player::rx() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.rx)
  return _internal_rx();
}
inline void Player::_internal_set_rx(float value) {
  
  rx_ = value;
}
inline void Player::set_rx(float value) {
  _internal_set_rx(value);
  // @@protoc_insertion_point(field_set:Protocol.Player.rx)
}

// float ry = 8;
inline void Player::clear_ry() {
  ry_ = 0;
}
inline float Player::_internal_ry() const {
  return ry_;
}
inline float Player::ry() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.ry)
  return _internal_ry();
}
inline void Player::_internal_set_ry(float value) {
  
  ry_ = value;
}
inline void Player::set_ry(float value) {
  _internal_set_ry(value);
  // @@protoc_insertion_point(field_set:Protocol.Player.ry)
}

// float rz = 9;
inline void Player::clear_rz() {
  rz_ = 0;
}
inline float Player::_internal_rz() const {
  return rz_;
}
inline float Player::rz() const {
  // @@protoc_insertion_point(field_get:Protocol.Player.rz)
  return _internal_rz();
}
inline void Player::_internal_set_rz(float value) {
  
  rz_ = value;
}
inline void Player::set_rz(float value) {
  _internal_set_rz(value);
  // @@protoc_insertion_point(field_set:Protocol.Player.rz)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace Protocol

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Struct_2eproto
