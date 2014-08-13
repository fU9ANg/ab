// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: proto/pbCreature.proto

#ifndef PROTOBUF_proto_2fpbCreature_2eproto__INCLUDED
#define PROTOBUF_proto_2fpbCreature_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "proto/pbBuffer.pb.h"
#include "proto/pbCreate.pb.h"
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_proto_2fpbCreature_2eproto();
void protobuf_AssignDesc_proto_2fpbCreature_2eproto();
void protobuf_ShutdownFile_proto_2fpbCreature_2eproto();

class pbCreatureClient;
class pbCreatureDB;

// ===================================================================

class pbCreatureClient : public ::google::protobuf::Message {
 public:
  pbCreatureClient();
  virtual ~pbCreatureClient();

  pbCreatureClient(const pbCreatureClient& from);

  inline pbCreatureClient& operator=(const pbCreatureClient& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const pbCreatureClient& default_instance();

  void Swap(pbCreatureClient* other);

  // implements Message ----------------------------------------------

  pbCreatureClient* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const pbCreatureClient& from);
  void MergeFrom(const pbCreatureClient& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 PosX = 1;
  inline bool has_posx() const;
  inline void clear_posx();
  static const int kPosXFieldNumber = 1;
  inline ::google::protobuf::int32 posx() const;
  inline void set_posx(::google::protobuf::int32 value);

  // repeated .pbBufferClient Buffs = 2;
  inline int buffs_size() const;
  inline void clear_buffs();
  static const int kBuffsFieldNumber = 2;
  inline const ::pbBufferClient& buffs(int index) const;
  inline ::pbBufferClient* mutable_buffs(int index);
  inline ::pbBufferClient* add_buffs();
  inline const ::google::protobuf::RepeatedPtrField< ::pbBufferClient >&
      buffs() const;
  inline ::google::protobuf::RepeatedPtrField< ::pbBufferClient >*
      mutable_buffs();

  // required .pbCreateClient base = 3;
  inline bool has_base() const;
  inline void clear_base();
  static const int kBaseFieldNumber = 3;
  inline const ::pbCreateClient& base() const;
  inline ::pbCreateClient* mutable_base();
  inline ::pbCreateClient* release_base();
  inline void set_allocated_base(::pbCreateClient* base);

  // @@protoc_insertion_point(class_scope:pbCreatureClient)
 private:
  inline void set_has_posx();
  inline void clear_has_posx();
  inline void set_has_base();
  inline void clear_has_base();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::pbBufferClient > buffs_;
  ::pbCreateClient* base_;
  ::google::protobuf::int32 posx_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_proto_2fpbCreature_2eproto();
  friend void protobuf_AssignDesc_proto_2fpbCreature_2eproto();
  friend void protobuf_ShutdownFile_proto_2fpbCreature_2eproto();

  void InitAsDefaultInstance();
  static pbCreatureClient* default_instance_;
};
// -------------------------------------------------------------------

class pbCreatureDB : public ::google::protobuf::Message {
 public:
  pbCreatureDB();
  virtual ~pbCreatureDB();

  pbCreatureDB(const pbCreatureDB& from);

  inline pbCreatureDB& operator=(const pbCreatureDB& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const pbCreatureDB& default_instance();

  void Swap(pbCreatureDB* other);

  // implements Message ----------------------------------------------

  pbCreatureDB* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const pbCreatureDB& from);
  void MergeFrom(const pbCreatureDB& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required int32 PosY = 1;
  inline bool has_posy() const;
  inline void clear_posy();
  static const int kPosYFieldNumber = 1;
  inline ::google::protobuf::int32 posy() const;
  inline void set_posy(::google::protobuf::int32 value);

  // repeated .pbBufferDB Buffs = 2;
  inline int buffs_size() const;
  inline void clear_buffs();
  static const int kBuffsFieldNumber = 2;
  inline const ::pbBufferDB& buffs(int index) const;
  inline ::pbBufferDB* mutable_buffs(int index);
  inline ::pbBufferDB* add_buffs();
  inline const ::google::protobuf::RepeatedPtrField< ::pbBufferDB >&
      buffs() const;
  inline ::google::protobuf::RepeatedPtrField< ::pbBufferDB >*
      mutable_buffs();

  // required .pbCreateDB base = 3;
  inline bool has_base() const;
  inline void clear_base();
  static const int kBaseFieldNumber = 3;
  inline const ::pbCreateDB& base() const;
  inline ::pbCreateDB* mutable_base();
  inline ::pbCreateDB* release_base();
  inline void set_allocated_base(::pbCreateDB* base);

  // @@protoc_insertion_point(class_scope:pbCreatureDB)
 private:
  inline void set_has_posy();
  inline void clear_has_posy();
  inline void set_has_base();
  inline void clear_has_base();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::pbBufferDB > buffs_;
  ::pbCreateDB* base_;
  ::google::protobuf::int32 posy_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_proto_2fpbCreature_2eproto();
  friend void protobuf_AssignDesc_proto_2fpbCreature_2eproto();
  friend void protobuf_ShutdownFile_proto_2fpbCreature_2eproto();

  void InitAsDefaultInstance();
  static pbCreatureDB* default_instance_;
};
// ===================================================================


// ===================================================================

// pbCreatureClient

// required int32 PosX = 1;
inline bool pbCreatureClient::has_posx() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void pbCreatureClient::set_has_posx() {
  _has_bits_[0] |= 0x00000001u;
}
inline void pbCreatureClient::clear_has_posx() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void pbCreatureClient::clear_posx() {
  posx_ = 0;
  clear_has_posx();
}
inline ::google::protobuf::int32 pbCreatureClient::posx() const {
  return posx_;
}
inline void pbCreatureClient::set_posx(::google::protobuf::int32 value) {
  set_has_posx();
  posx_ = value;
}

// repeated .pbBufferClient Buffs = 2;
inline int pbCreatureClient::buffs_size() const {
  return buffs_.size();
}
inline void pbCreatureClient::clear_buffs() {
  buffs_.Clear();
}
inline const ::pbBufferClient& pbCreatureClient::buffs(int index) const {
  return buffs_.Get(index);
}
inline ::pbBufferClient* pbCreatureClient::mutable_buffs(int index) {
  return buffs_.Mutable(index);
}
inline ::pbBufferClient* pbCreatureClient::add_buffs() {
  return buffs_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::pbBufferClient >&
pbCreatureClient::buffs() const {
  return buffs_;
}
inline ::google::protobuf::RepeatedPtrField< ::pbBufferClient >*
pbCreatureClient::mutable_buffs() {
  return &buffs_;
}

// required .pbCreateClient base = 3;
inline bool pbCreatureClient::has_base() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void pbCreatureClient::set_has_base() {
  _has_bits_[0] |= 0x00000004u;
}
inline void pbCreatureClient::clear_has_base() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void pbCreatureClient::clear_base() {
  if (base_ != NULL) base_->::pbCreateClient::Clear();
  clear_has_base();
}
inline const ::pbCreateClient& pbCreatureClient::base() const {
  return base_ != NULL ? *base_ : *default_instance_->base_;
}
inline ::pbCreateClient* pbCreatureClient::mutable_base() {
  set_has_base();
  if (base_ == NULL) base_ = new ::pbCreateClient;
  return base_;
}
inline ::pbCreateClient* pbCreatureClient::release_base() {
  clear_has_base();
  ::pbCreateClient* temp = base_;
  base_ = NULL;
  return temp;
}
inline void pbCreatureClient::set_allocated_base(::pbCreateClient* base) {
  delete base_;
  base_ = base;
  if (base) {
    set_has_base();
  } else {
    clear_has_base();
  }
}

// -------------------------------------------------------------------

// pbCreatureDB

// required int32 PosY = 1;
inline bool pbCreatureDB::has_posy() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void pbCreatureDB::set_has_posy() {
  _has_bits_[0] |= 0x00000001u;
}
inline void pbCreatureDB::clear_has_posy() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void pbCreatureDB::clear_posy() {
  posy_ = 0;
  clear_has_posy();
}
inline ::google::protobuf::int32 pbCreatureDB::posy() const {
  return posy_;
}
inline void pbCreatureDB::set_posy(::google::protobuf::int32 value) {
  set_has_posy();
  posy_ = value;
}

// repeated .pbBufferDB Buffs = 2;
inline int pbCreatureDB::buffs_size() const {
  return buffs_.size();
}
inline void pbCreatureDB::clear_buffs() {
  buffs_.Clear();
}
inline const ::pbBufferDB& pbCreatureDB::buffs(int index) const {
  return buffs_.Get(index);
}
inline ::pbBufferDB* pbCreatureDB::mutable_buffs(int index) {
  return buffs_.Mutable(index);
}
inline ::pbBufferDB* pbCreatureDB::add_buffs() {
  return buffs_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::pbBufferDB >&
pbCreatureDB::buffs() const {
  return buffs_;
}
inline ::google::protobuf::RepeatedPtrField< ::pbBufferDB >*
pbCreatureDB::mutable_buffs() {
  return &buffs_;
}

// required .pbCreateDB base = 3;
inline bool pbCreatureDB::has_base() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void pbCreatureDB::set_has_base() {
  _has_bits_[0] |= 0x00000004u;
}
inline void pbCreatureDB::clear_has_base() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void pbCreatureDB::clear_base() {
  if (base_ != NULL) base_->::pbCreateDB::Clear();
  clear_has_base();
}
inline const ::pbCreateDB& pbCreatureDB::base() const {
  return base_ != NULL ? *base_ : *default_instance_->base_;
}
inline ::pbCreateDB* pbCreatureDB::mutable_base() {
  set_has_base();
  if (base_ == NULL) base_ = new ::pbCreateDB;
  return base_;
}
inline ::pbCreateDB* pbCreatureDB::release_base() {
  clear_has_base();
  ::pbCreateDB* temp = base_;
  base_ = NULL;
  return temp;
}
inline void pbCreatureDB::set_allocated_base(::pbCreateDB* base) {
  delete base_;
  base_ = base;
  if (base) {
    set_has_base();
  } else {
    clear_has_base();
  }
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_proto_2fpbCreature_2eproto__INCLUDED
