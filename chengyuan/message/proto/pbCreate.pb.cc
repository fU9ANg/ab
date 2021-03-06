// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/pbCreate.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "proto/pbCreate.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* pbCreateClient_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  pbCreateClient_reflection_ = NULL;
const ::google::protobuf::Descriptor* pbCreateDB_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  pbCreateDB_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_proto_2fpbCreate_2eproto() {
  protobuf_AddDesc_proto_2fpbCreate_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "proto/pbCreate.proto");
  GOOGLE_CHECK(file != NULL);
  pbCreateClient_descriptor_ = file->message_type(0);
  static const int pbCreateClient_offsets_[4] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbCreateClient, hp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbCreateClient, mp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbCreateClient, props_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbCreateClient, spells_),
  };
  pbCreateClient_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      pbCreateClient_descriptor_,
      pbCreateClient::default_instance_,
      pbCreateClient_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbCreateClient, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbCreateClient, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(pbCreateClient));
  pbCreateDB_descriptor_ = file->message_type(1);
  static const int pbCreateDB_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbCreateDB, hp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbCreateDB, props_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbCreateDB, level_),
  };
  pbCreateDB_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      pbCreateDB_descriptor_,
      pbCreateDB::default_instance_,
      pbCreateDB_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbCreateDB, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbCreateDB, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(pbCreateDB));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_proto_2fpbCreate_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    pbCreateClient_descriptor_, &pbCreateClient::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    pbCreateDB_descriptor_, &pbCreateDB::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_proto_2fpbCreate_2eproto() {
  delete pbCreateClient::default_instance_;
  delete pbCreateClient_reflection_;
  delete pbCreateDB::default_instance_;
  delete pbCreateDB_reflection_;
}

void protobuf_AddDesc_proto_2fpbCreate_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::protobuf_AddDesc_proto_2fpbSpell_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\024proto/pbCreate.proto\032\023proto/pbSpell.pr"
    "oto\"W\n\016pbCreateClient\022\n\n\002hp\030\001 \002(\005\022\n\n\002mp\030"
    "\002 \002(\005\022\r\n\005props\030\003 \003(\005\022\036\n\006spells\030\004 \003(\0132\016.p"
    "bSpellClient\"6\n\npbCreateDB\022\n\n\002hp\030\001 \002(\005\022\r"
    "\n\005props\030\002 \003(\005\022\r\n\005level\030\003 \002(\005", 188);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "proto/pbCreate.proto", &protobuf_RegisterTypes);
  pbCreateClient::default_instance_ = new pbCreateClient();
  pbCreateDB::default_instance_ = new pbCreateDB();
  pbCreateClient::default_instance_->InitAsDefaultInstance();
  pbCreateDB::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_proto_2fpbCreate_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_proto_2fpbCreate_2eproto {
  StaticDescriptorInitializer_proto_2fpbCreate_2eproto() {
    protobuf_AddDesc_proto_2fpbCreate_2eproto();
  }
} static_descriptor_initializer_proto_2fpbCreate_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int pbCreateClient::kHpFieldNumber;
const int pbCreateClient::kMpFieldNumber;
const int pbCreateClient::kPropsFieldNumber;
const int pbCreateClient::kSpellsFieldNumber;
#endif  // !_MSC_VER

pbCreateClient::pbCreateClient()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void pbCreateClient::InitAsDefaultInstance() {
}

pbCreateClient::pbCreateClient(const pbCreateClient& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void pbCreateClient::SharedCtor() {
  _cached_size_ = 0;
  hp_ = 0;
  mp_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

pbCreateClient::~pbCreateClient() {
  SharedDtor();
}

void pbCreateClient::SharedDtor() {
  if (this != default_instance_) {
  }
}

void pbCreateClient::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* pbCreateClient::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return pbCreateClient_descriptor_;
}

const pbCreateClient& pbCreateClient::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_proto_2fpbCreate_2eproto();
  return *default_instance_;
}

pbCreateClient* pbCreateClient::default_instance_ = NULL;

pbCreateClient* pbCreateClient::New() const {
  return new pbCreateClient;
}

void pbCreateClient::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    hp_ = 0;
    mp_ = 0;
  }
  props_.Clear();
  spells_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool pbCreateClient::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 hp = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &hp_)));
          set_has_hp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_mp;
        break;
      }

      // required int32 mp = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_mp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &mp_)));
          set_has_mp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_props;
        break;
      }

      // repeated int32 props = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_props:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 24, input, this->mutable_props())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_props())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_props;
        if (input->ExpectTag(34)) goto parse_spells;
        break;
      }

      // repeated .pbSpellClient spells = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_spells:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_spells()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(34)) goto parse_spells;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void pbCreateClient::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 hp = 1;
  if (has_hp()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->hp(), output);
  }

  // required int32 mp = 2;
  if (has_mp()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->mp(), output);
  }

  // repeated int32 props = 3;
  for (int i = 0; i < this->props_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      3, this->props(i), output);
  }

  // repeated .pbSpellClient spells = 4;
  for (int i = 0; i < this->spells_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->spells(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* pbCreateClient::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 hp = 1;
  if (has_hp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->hp(), target);
  }

  // required int32 mp = 2;
  if (has_mp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->mp(), target);
  }

  // repeated int32 props = 3;
  for (int i = 0; i < this->props_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32ToArray(3, this->props(i), target);
  }

  // repeated .pbSpellClient spells = 4;
  for (int i = 0; i < this->spells_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        4, this->spells(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int pbCreateClient::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 hp = 1;
    if (has_hp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->hp());
    }

    // required int32 mp = 2;
    if (has_mp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->mp());
    }

  }
  // repeated int32 props = 3;
  {
    int data_size = 0;
    for (int i = 0; i < this->props_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->props(i));
    }
    total_size += 1 * this->props_size() + data_size;
  }

  // repeated .pbSpellClient spells = 4;
  total_size += 1 * this->spells_size();
  for (int i = 0; i < this->spells_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->spells(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void pbCreateClient::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const pbCreateClient* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const pbCreateClient*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void pbCreateClient::MergeFrom(const pbCreateClient& from) {
  GOOGLE_CHECK_NE(&from, this);
  props_.MergeFrom(from.props_);
  spells_.MergeFrom(from.spells_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_hp()) {
      set_hp(from.hp());
    }
    if (from.has_mp()) {
      set_mp(from.mp());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void pbCreateClient::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void pbCreateClient::CopyFrom(const pbCreateClient& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool pbCreateClient::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  for (int i = 0; i < spells_size(); i++) {
    if (!this->spells(i).IsInitialized()) return false;
  }
  return true;
}

void pbCreateClient::Swap(pbCreateClient* other) {
  if (other != this) {
    std::swap(hp_, other->hp_);
    std::swap(mp_, other->mp_);
    props_.Swap(&other->props_);
    spells_.Swap(&other->spells_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata pbCreateClient::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = pbCreateClient_descriptor_;
  metadata.reflection = pbCreateClient_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int pbCreateDB::kHpFieldNumber;
const int pbCreateDB::kPropsFieldNumber;
const int pbCreateDB::kLevelFieldNumber;
#endif  // !_MSC_VER

pbCreateDB::pbCreateDB()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void pbCreateDB::InitAsDefaultInstance() {
}

pbCreateDB::pbCreateDB(const pbCreateDB& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void pbCreateDB::SharedCtor() {
  _cached_size_ = 0;
  hp_ = 0;
  level_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

pbCreateDB::~pbCreateDB() {
  SharedDtor();
}

void pbCreateDB::SharedDtor() {
  if (this != default_instance_) {
  }
}

void pbCreateDB::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* pbCreateDB::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return pbCreateDB_descriptor_;
}

const pbCreateDB& pbCreateDB::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_proto_2fpbCreate_2eproto();
  return *default_instance_;
}

pbCreateDB* pbCreateDB::default_instance_ = NULL;

pbCreateDB* pbCreateDB::New() const {
  return new pbCreateDB;
}

void pbCreateDB::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    hp_ = 0;
    level_ = 0;
  }
  props_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool pbCreateDB::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 hp = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &hp_)));
          set_has_hp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_props;
        break;
      }

      // repeated int32 props = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_props:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 1, 16, input, this->mutable_props())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, this->mutable_props())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_props;
        if (input->ExpectTag(24)) goto parse_level;
        break;
      }

      // required int32 level = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_level:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &level_)));
          set_has_level();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void pbCreateDB::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 hp = 1;
  if (has_hp()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->hp(), output);
  }

  // repeated int32 props = 2;
  for (int i = 0; i < this->props_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(
      2, this->props(i), output);
  }

  // required int32 level = 3;
  if (has_level()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->level(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* pbCreateDB::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 hp = 1;
  if (has_hp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->hp(), target);
  }

  // repeated int32 props = 2;
  for (int i = 0; i < this->props_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteInt32ToArray(2, this->props(i), target);
  }

  // required int32 level = 3;
  if (has_level()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->level(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int pbCreateDB::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 hp = 1;
    if (has_hp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->hp());
    }

    // required int32 level = 3;
    if (has_level()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->level());
    }

  }
  // repeated int32 props = 2;
  {
    int data_size = 0;
    for (int i = 0; i < this->props_size(); i++) {
      data_size += ::google::protobuf::internal::WireFormatLite::
        Int32Size(this->props(i));
    }
    total_size += 1 * this->props_size() + data_size;
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void pbCreateDB::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const pbCreateDB* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const pbCreateDB*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void pbCreateDB::MergeFrom(const pbCreateDB& from) {
  GOOGLE_CHECK_NE(&from, this);
  props_.MergeFrom(from.props_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_hp()) {
      set_hp(from.hp());
    }
    if (from.has_level()) {
      set_level(from.level());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void pbCreateDB::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void pbCreateDB::CopyFrom(const pbCreateDB& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool pbCreateDB::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000005) != 0x00000005) return false;

  return true;
}

void pbCreateDB::Swap(pbCreateDB* other) {
  if (other != this) {
    std::swap(hp_, other->hp_);
    props_.Swap(&other->props_);
    std::swap(level_, other->level_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata pbCreateDB::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = pbCreateDB_descriptor_;
  metadata.reflection = pbCreateDB_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
