// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/pbSpell.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "proto/pbSpell.pb.h"

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

const ::google::protobuf::Descriptor* pbSpellClient_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  pbSpellClient_reflection_ = NULL;
const ::google::protobuf::Descriptor* pbSpellDB_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  pbSpellDB_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_proto_2fpbSpell_2eproto() {
  protobuf_AddDesc_proto_2fpbSpell_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "proto/pbSpell.proto");
  GOOGLE_CHECK(file != NULL);
  pbSpellClient_descriptor_ = file->message_type(0);
  static const int pbSpellClient_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellClient, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellClient, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellClient, casttime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellClient, cdtime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellClient, costmp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellClient, usetime_),
  };
  pbSpellClient_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      pbSpellClient_descriptor_,
      pbSpellClient::default_instance_,
      pbSpellClient_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellClient, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellClient, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(pbSpellClient));
  pbSpellDB_descriptor_ = file->message_type(1);
  static const int pbSpellDB_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellDB, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellDB, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellDB, casttime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellDB, cdtime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellDB, costmp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellDB, lastcasttime_),
  };
  pbSpellDB_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      pbSpellDB_descriptor_,
      pbSpellDB::default_instance_,
      pbSpellDB_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellDB, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(pbSpellDB, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(pbSpellDB));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_proto_2fpbSpell_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    pbSpellClient_descriptor_, &pbSpellClient::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    pbSpellDB_descriptor_, &pbSpellDB::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_proto_2fpbSpell_2eproto() {
  delete pbSpellClient::default_instance_;
  delete pbSpellClient_reflection_;
  delete pbSpellDB::default_instance_;
  delete pbSpellDB_reflection_;
}

void protobuf_AddDesc_proto_2fpbSpell_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023proto/pbSpell.proto\"l\n\rpbSpellClient\022\n"
    "\n\002Id\030\001 \002(\005\022\014\n\004Name\030\002 \002(\t\022\020\n\010CastTime\030\003 \002"
    "(\005\022\016\n\006CDTime\030\004 \002(\005\022\016\n\006CostMp\030\005 \002(\005\022\017\n\007Us"
    "eTime\030\006 \002(\005\"m\n\tpbSpellDB\022\n\n\002Id\030\001 \002(\005\022\014\n\004"
    "Name\030\002 \002(\t\022\020\n\010CastTime\030\003 \002(\005\022\016\n\006CDTime\030\004"
    " \002(\005\022\016\n\006CostMp\030\005 \002(\005\022\024\n\014LastCastTime\030\006 \002"
    "(\003", 242);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "proto/pbSpell.proto", &protobuf_RegisterTypes);
  pbSpellClient::default_instance_ = new pbSpellClient();
  pbSpellDB::default_instance_ = new pbSpellDB();
  pbSpellClient::default_instance_->InitAsDefaultInstance();
  pbSpellDB::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_proto_2fpbSpell_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_proto_2fpbSpell_2eproto {
  StaticDescriptorInitializer_proto_2fpbSpell_2eproto() {
    protobuf_AddDesc_proto_2fpbSpell_2eproto();
  }
} static_descriptor_initializer_proto_2fpbSpell_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int pbSpellClient::kIdFieldNumber;
const int pbSpellClient::kNameFieldNumber;
const int pbSpellClient::kCastTimeFieldNumber;
const int pbSpellClient::kCDTimeFieldNumber;
const int pbSpellClient::kCostMpFieldNumber;
const int pbSpellClient::kUseTimeFieldNumber;
#endif  // !_MSC_VER

pbSpellClient::pbSpellClient()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void pbSpellClient::InitAsDefaultInstance() {
}

pbSpellClient::pbSpellClient(const pbSpellClient& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void pbSpellClient::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  casttime_ = 0;
  cdtime_ = 0;
  costmp_ = 0;
  usetime_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

pbSpellClient::~pbSpellClient() {
  SharedDtor();
}

void pbSpellClient::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (this != default_instance_) {
  }
}

void pbSpellClient::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* pbSpellClient::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return pbSpellClient_descriptor_;
}

const pbSpellClient& pbSpellClient::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_proto_2fpbSpell_2eproto();
  return *default_instance_;
}

pbSpellClient* pbSpellClient::default_instance_ = NULL;

pbSpellClient* pbSpellClient::New() const {
  return new pbSpellClient;
}

void pbSpellClient::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0;
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    casttime_ = 0;
    cdtime_ = 0;
    costmp_ = 0;
    usetime_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool pbSpellClient::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 Id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_Name;
        break;
      }

      // required string Name = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_Name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_CastTime;
        break;
      }

      // required int32 CastTime = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_CastTime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &casttime_)));
          set_has_casttime();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_CDTime;
        break;
      }

      // required int32 CDTime = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_CDTime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &cdtime_)));
          set_has_cdtime();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_CostMp;
        break;
      }

      // required int32 CostMp = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_CostMp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &costmp_)));
          set_has_costmp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_UseTime;
        break;
      }

      // required int32 UseTime = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_UseTime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &usetime_)));
          set_has_usetime();
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

void pbSpellClient::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 Id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // required string Name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->name(), output);
  }

  // required int32 CastTime = 3;
  if (has_casttime()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->casttime(), output);
  }

  // required int32 CDTime = 4;
  if (has_cdtime()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->cdtime(), output);
  }

  // required int32 CostMp = 5;
  if (has_costmp()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->costmp(), output);
  }

  // required int32 UseTime = 6;
  if (has_usetime()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->usetime(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* pbSpellClient::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 Id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // required string Name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->name(), target);
  }

  // required int32 CastTime = 3;
  if (has_casttime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->casttime(), target);
  }

  // required int32 CDTime = 4;
  if (has_cdtime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->cdtime(), target);
  }

  // required int32 CostMp = 5;
  if (has_costmp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->costmp(), target);
  }

  // required int32 UseTime = 6;
  if (has_usetime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->usetime(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int pbSpellClient::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 Id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // required string Name = 2;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // required int32 CastTime = 3;
    if (has_casttime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->casttime());
    }

    // required int32 CDTime = 4;
    if (has_cdtime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->cdtime());
    }

    // required int32 CostMp = 5;
    if (has_costmp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->costmp());
    }

    // required int32 UseTime = 6;
    if (has_usetime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->usetime());
    }

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

void pbSpellClient::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const pbSpellClient* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const pbSpellClient*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void pbSpellClient::MergeFrom(const pbSpellClient& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_casttime()) {
      set_casttime(from.casttime());
    }
    if (from.has_cdtime()) {
      set_cdtime(from.cdtime());
    }
    if (from.has_costmp()) {
      set_costmp(from.costmp());
    }
    if (from.has_usetime()) {
      set_usetime(from.usetime());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void pbSpellClient::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void pbSpellClient::CopyFrom(const pbSpellClient& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool pbSpellClient::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000003f) != 0x0000003f) return false;

  return true;
}

void pbSpellClient::Swap(pbSpellClient* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(name_, other->name_);
    std::swap(casttime_, other->casttime_);
    std::swap(cdtime_, other->cdtime_);
    std::swap(costmp_, other->costmp_);
    std::swap(usetime_, other->usetime_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata pbSpellClient::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = pbSpellClient_descriptor_;
  metadata.reflection = pbSpellClient_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int pbSpellDB::kIdFieldNumber;
const int pbSpellDB::kNameFieldNumber;
const int pbSpellDB::kCastTimeFieldNumber;
const int pbSpellDB::kCDTimeFieldNumber;
const int pbSpellDB::kCostMpFieldNumber;
const int pbSpellDB::kLastCastTimeFieldNumber;
#endif  // !_MSC_VER

pbSpellDB::pbSpellDB()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void pbSpellDB::InitAsDefaultInstance() {
}

pbSpellDB::pbSpellDB(const pbSpellDB& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void pbSpellDB::SharedCtor() {
  _cached_size_ = 0;
  id_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  casttime_ = 0;
  cdtime_ = 0;
  costmp_ = 0;
  lastcasttime_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

pbSpellDB::~pbSpellDB() {
  SharedDtor();
}

void pbSpellDB::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (this != default_instance_) {
  }
}

void pbSpellDB::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* pbSpellDB::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return pbSpellDB_descriptor_;
}

const pbSpellDB& pbSpellDB::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_proto_2fpbSpell_2eproto();
  return *default_instance_;
}

pbSpellDB* pbSpellDB::default_instance_ = NULL;

pbSpellDB* pbSpellDB::New() const {
  return new pbSpellDB;
}

void pbSpellDB::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    id_ = 0;
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    casttime_ = 0;
    cdtime_ = 0;
    costmp_ = 0;
    lastcasttime_ = GOOGLE_LONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool pbSpellDB::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int32 Id = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(18)) goto parse_Name;
        break;
      }

      // required string Name = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_Name:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_CastTime;
        break;
      }

      // required int32 CastTime = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_CastTime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &casttime_)));
          set_has_casttime();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_CDTime;
        break;
      }

      // required int32 CDTime = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_CDTime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &cdtime_)));
          set_has_cdtime();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_CostMp;
        break;
      }

      // required int32 CostMp = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_CostMp:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &costmp_)));
          set_has_costmp();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_LastCastTime;
        break;
      }

      // required int64 LastCastTime = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_LastCastTime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &lastcasttime_)));
          set_has_lastcasttime();
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

void pbSpellDB::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required int32 Id = 1;
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // required string Name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      2, this->name(), output);
  }

  // required int32 CastTime = 3;
  if (has_casttime()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->casttime(), output);
  }

  // required int32 CDTime = 4;
  if (has_cdtime()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->cdtime(), output);
  }

  // required int32 CostMp = 5;
  if (has_costmp()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->costmp(), output);
  }

  // required int64 LastCastTime = 6;
  if (has_lastcasttime()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(6, this->lastcasttime(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* pbSpellDB::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required int32 Id = 1;
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // required string Name = 2;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        2, this->name(), target);
  }

  // required int32 CastTime = 3;
  if (has_casttime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->casttime(), target);
  }

  // required int32 CDTime = 4;
  if (has_cdtime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->cdtime(), target);
  }

  // required int32 CostMp = 5;
  if (has_costmp()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->costmp(), target);
  }

  // required int64 LastCastTime = 6;
  if (has_lastcasttime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(6, this->lastcasttime(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int pbSpellDB::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int32 Id = 1;
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // required string Name = 2;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // required int32 CastTime = 3;
    if (has_casttime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->casttime());
    }

    // required int32 CDTime = 4;
    if (has_cdtime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->cdtime());
    }

    // required int32 CostMp = 5;
    if (has_costmp()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->costmp());
    }

    // required int64 LastCastTime = 6;
    if (has_lastcasttime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->lastcasttime());
    }

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

void pbSpellDB::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const pbSpellDB* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const pbSpellDB*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void pbSpellDB::MergeFrom(const pbSpellDB& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_casttime()) {
      set_casttime(from.casttime());
    }
    if (from.has_cdtime()) {
      set_cdtime(from.cdtime());
    }
    if (from.has_costmp()) {
      set_costmp(from.costmp());
    }
    if (from.has_lastcasttime()) {
      set_lastcasttime(from.lastcasttime());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void pbSpellDB::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void pbSpellDB::CopyFrom(const pbSpellDB& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool pbSpellDB::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000003f) != 0x0000003f) return false;

  return true;
}

void pbSpellDB::Swap(pbSpellDB* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(name_, other->name_);
    std::swap(casttime_, other->casttime_);
    std::swap(cdtime_, other->cdtime_);
    std::swap(costmp_, other->costmp_);
    std::swap(lastcasttime_, other->lastcasttime_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata pbSpellDB::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = pbSpellDB_descriptor_;
  metadata.reflection = pbSpellDB_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
