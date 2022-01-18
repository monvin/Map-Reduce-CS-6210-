// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: masterworker.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_masterworker_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_masterworker_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3014000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3014000 < PROTOBUF_MIN_PROTOC_VERSION
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
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_masterworker_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_masterworker_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_masterworker_2eproto;
namespace masterworker {
class FileInfo;
class FileInfoDefaultTypeInternal;
extern FileInfoDefaultTypeInternal _FileInfo_default_instance_;
class WorkConfirmation;
class WorkConfirmationDefaultTypeInternal;
extern WorkConfirmationDefaultTypeInternal _WorkConfirmation_default_instance_;
class WorkDetails;
class WorkDetailsDefaultTypeInternal;
extern WorkDetailsDefaultTypeInternal _WorkDetails_default_instance_;
}  // namespace masterworker
PROTOBUF_NAMESPACE_OPEN
template<> ::masterworker::FileInfo* Arena::CreateMaybeMessage<::masterworker::FileInfo>(Arena*);
template<> ::masterworker::WorkConfirmation* Arena::CreateMaybeMessage<::masterworker::WorkConfirmation>(Arena*);
template<> ::masterworker::WorkDetails* Arena::CreateMaybeMessage<::masterworker::WorkDetails>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace masterworker {

// ===================================================================

class FileInfo PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:masterworker.FileInfo) */ {
 public:
  inline FileInfo() : FileInfo(nullptr) {}
  virtual ~FileInfo();

  FileInfo(const FileInfo& from);
  FileInfo(FileInfo&& from) noexcept
    : FileInfo() {
    *this = ::std::move(from);
  }

  inline FileInfo& operator=(const FileInfo& from) {
    CopyFrom(from);
    return *this;
  }
  inline FileInfo& operator=(FileInfo&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const FileInfo& default_instance();

  static inline const FileInfo* internal_default_instance() {
    return reinterpret_cast<const FileInfo*>(
               &_FileInfo_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(FileInfo& a, FileInfo& b) {
    a.Swap(&b);
  }
  inline void Swap(FileInfo* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(FileInfo* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FileInfo* New() const final {
    return CreateMaybeMessage<FileInfo>(nullptr);
  }

  FileInfo* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FileInfo>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FileInfo& from);
  void MergeFrom(const FileInfo& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(FileInfo* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "masterworker.FileInfo";
  }
  protected:
  explicit FileInfo(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_masterworker_2eproto);
    return ::descriptor_table_masterworker_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kInputFileFieldNumber = 1,
    kFileOffsetFieldNumber = 2,
  };
  // string input_file = 1;
  void clear_input_file();
  const std::string& input_file() const;
  void set_input_file(const std::string& value);
  void set_input_file(std::string&& value);
  void set_input_file(const char* value);
  void set_input_file(const char* value, size_t size);
  std::string* mutable_input_file();
  std::string* release_input_file();
  void set_allocated_input_file(std::string* input_file);
  private:
  const std::string& _internal_input_file() const;
  void _internal_set_input_file(const std::string& value);
  std::string* _internal_mutable_input_file();
  public:

  // double file_offset = 2;
  void clear_file_offset();
  double file_offset() const;
  void set_file_offset(double value);
  private:
  double _internal_file_offset() const;
  void _internal_set_file_offset(double value);
  public:

  // @@protoc_insertion_point(class_scope:masterworker.FileInfo)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr input_file_;
  double file_offset_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_masterworker_2eproto;
};
// -------------------------------------------------------------------

class WorkDetails PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:masterworker.WorkDetails) */ {
 public:
  inline WorkDetails() : WorkDetails(nullptr) {}
  virtual ~WorkDetails();

  WorkDetails(const WorkDetails& from);
  WorkDetails(WorkDetails&& from) noexcept
    : WorkDetails() {
    *this = ::std::move(from);
  }

  inline WorkDetails& operator=(const WorkDetails& from) {
    CopyFrom(from);
    return *this;
  }
  inline WorkDetails& operator=(WorkDetails&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const WorkDetails& default_instance();

  static inline const WorkDetails* internal_default_instance() {
    return reinterpret_cast<const WorkDetails*>(
               &_WorkDetails_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(WorkDetails& a, WorkDetails& b) {
    a.Swap(&b);
  }
  inline void Swap(WorkDetails* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(WorkDetails* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline WorkDetails* New() const final {
    return CreateMaybeMessage<WorkDetails>(nullptr);
  }

  WorkDetails* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<WorkDetails>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const WorkDetails& from);
  void MergeFrom(const WorkDetails& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(WorkDetails* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "masterworker.WorkDetails";
  }
  protected:
  explicit WorkDetails(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_masterworker_2eproto);
    return ::descriptor_table_masterworker_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFileDetailsFieldNumber = 2,
    kCompletedJobsFieldNumber = 7,
    kUserIdFieldNumber = 3,
    kInitialFileStartFieldNumber = 1,
    kJobIdFieldNumber = 5,
    kFileCountFieldNumber = 6,
    kIsMapperFieldNumber = 4,
  };
  // repeated .masterworker.FileInfo FileDetails = 2;
  int filedetails_size() const;
  private:
  int _internal_filedetails_size() const;
  public:
  void clear_filedetails();
  ::masterworker::FileInfo* mutable_filedetails(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::masterworker::FileInfo >*
      mutable_filedetails();
  private:
  const ::masterworker::FileInfo& _internal_filedetails(int index) const;
  ::masterworker::FileInfo* _internal_add_filedetails();
  public:
  const ::masterworker::FileInfo& filedetails(int index) const;
  ::masterworker::FileInfo* add_filedetails();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::masterworker::FileInfo >&
      filedetails() const;

  // repeated double completed_jobs = 7;
  int completed_jobs_size() const;
  private:
  int _internal_completed_jobs_size() const;
  public:
  void clear_completed_jobs();
  private:
  double _internal_completed_jobs(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      _internal_completed_jobs() const;
  void _internal_add_completed_jobs(double value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      _internal_mutable_completed_jobs();
  public:
  double completed_jobs(int index) const;
  void set_completed_jobs(int index, double value);
  void add_completed_jobs(double value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
      completed_jobs() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
      mutable_completed_jobs();

  // string user_id = 3;
  void clear_user_id();
  const std::string& user_id() const;
  void set_user_id(const std::string& value);
  void set_user_id(std::string&& value);
  void set_user_id(const char* value);
  void set_user_id(const char* value, size_t size);
  std::string* mutable_user_id();
  std::string* release_user_id();
  void set_allocated_user_id(std::string* user_id);
  private:
  const std::string& _internal_user_id() const;
  void _internal_set_user_id(const std::string& value);
  std::string* _internal_mutable_user_id();
  public:

  // double initial_file_start = 1;
  void clear_initial_file_start();
  double initial_file_start() const;
  void set_initial_file_start(double value);
  private:
  double _internal_initial_file_start() const;
  void _internal_set_initial_file_start(double value);
  public:

  // double job_id = 5;
  void clear_job_id();
  double job_id() const;
  void set_job_id(double value);
  private:
  double _internal_job_id() const;
  void _internal_set_job_id(double value);
  public:

  // double file_count = 6;
  void clear_file_count();
  double file_count() const;
  void set_file_count(double value);
  private:
  double _internal_file_count() const;
  void _internal_set_file_count(double value);
  public:

  // bool is_mapper = 4;
  void clear_is_mapper();
  bool is_mapper() const;
  void set_is_mapper(bool value);
  private:
  bool _internal_is_mapper() const;
  void _internal_set_is_mapper(bool value);
  public:

  // @@protoc_insertion_point(class_scope:masterworker.WorkDetails)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::masterworker::FileInfo > filedetails_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< double > completed_jobs_;
  mutable std::atomic<int> _completed_jobs_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr user_id_;
  double initial_file_start_;
  double job_id_;
  double file_count_;
  bool is_mapper_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_masterworker_2eproto;
};
// -------------------------------------------------------------------

class WorkConfirmation PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:masterworker.WorkConfirmation) */ {
 public:
  inline WorkConfirmation() : WorkConfirmation(nullptr) {}
  virtual ~WorkConfirmation();

  WorkConfirmation(const WorkConfirmation& from);
  WorkConfirmation(WorkConfirmation&& from) noexcept
    : WorkConfirmation() {
    *this = ::std::move(from);
  }

  inline WorkConfirmation& operator=(const WorkConfirmation& from) {
    CopyFrom(from);
    return *this;
  }
  inline WorkConfirmation& operator=(WorkConfirmation&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const WorkConfirmation& default_instance();

  static inline const WorkConfirmation* internal_default_instance() {
    return reinterpret_cast<const WorkConfirmation*>(
               &_WorkConfirmation_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(WorkConfirmation& a, WorkConfirmation& b) {
    a.Swap(&b);
  }
  inline void Swap(WorkConfirmation* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(WorkConfirmation* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline WorkConfirmation* New() const final {
    return CreateMaybeMessage<WorkConfirmation>(nullptr);
  }

  WorkConfirmation* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<WorkConfirmation>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const WorkConfirmation& from);
  void MergeFrom(const WorkConfirmation& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(WorkConfirmation* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "masterworker.WorkConfirmation";
  }
  protected:
  explicit WorkConfirmation(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_masterworker_2eproto);
    return ::descriptor_table_masterworker_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kJobIdFieldNumber = 2,
    kIsMapperFieldNumber = 1,
  };
  // double job_id = 2;
  void clear_job_id();
  double job_id() const;
  void set_job_id(double value);
  private:
  double _internal_job_id() const;
  void _internal_set_job_id(double value);
  public:

  // bool is_mapper = 1;
  void clear_is_mapper();
  bool is_mapper() const;
  void set_is_mapper(bool value);
  private:
  bool _internal_is_mapper() const;
  void _internal_set_is_mapper(bool value);
  public:

  // @@protoc_insertion_point(class_scope:masterworker.WorkConfirmation)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  double job_id_;
  bool is_mapper_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_masterworker_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// FileInfo

// string input_file = 1;
inline void FileInfo::clear_input_file() {
  input_file_.ClearToEmpty();
}
inline const std::string& FileInfo::input_file() const {
  // @@protoc_insertion_point(field_get:masterworker.FileInfo.input_file)
  return _internal_input_file();
}
inline void FileInfo::set_input_file(const std::string& value) {
  _internal_set_input_file(value);
  // @@protoc_insertion_point(field_set:masterworker.FileInfo.input_file)
}
inline std::string* FileInfo::mutable_input_file() {
  // @@protoc_insertion_point(field_mutable:masterworker.FileInfo.input_file)
  return _internal_mutable_input_file();
}
inline const std::string& FileInfo::_internal_input_file() const {
  return input_file_.Get();
}
inline void FileInfo::_internal_set_input_file(const std::string& value) {
  
  input_file_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void FileInfo::set_input_file(std::string&& value) {
  
  input_file_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:masterworker.FileInfo.input_file)
}
inline void FileInfo::set_input_file(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  input_file_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:masterworker.FileInfo.input_file)
}
inline void FileInfo::set_input_file(const char* value,
    size_t size) {
  
  input_file_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:masterworker.FileInfo.input_file)
}
inline std::string* FileInfo::_internal_mutable_input_file() {
  
  return input_file_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* FileInfo::release_input_file() {
  // @@protoc_insertion_point(field_release:masterworker.FileInfo.input_file)
  return input_file_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void FileInfo::set_allocated_input_file(std::string* input_file) {
  if (input_file != nullptr) {
    
  } else {
    
  }
  input_file_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), input_file,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:masterworker.FileInfo.input_file)
}

// double file_offset = 2;
inline void FileInfo::clear_file_offset() {
  file_offset_ = 0;
}
inline double FileInfo::_internal_file_offset() const {
  return file_offset_;
}
inline double FileInfo::file_offset() const {
  // @@protoc_insertion_point(field_get:masterworker.FileInfo.file_offset)
  return _internal_file_offset();
}
inline void FileInfo::_internal_set_file_offset(double value) {
  
  file_offset_ = value;
}
inline void FileInfo::set_file_offset(double value) {
  _internal_set_file_offset(value);
  // @@protoc_insertion_point(field_set:masterworker.FileInfo.file_offset)
}

// -------------------------------------------------------------------

// WorkDetails

// double initial_file_start = 1;
inline void WorkDetails::clear_initial_file_start() {
  initial_file_start_ = 0;
}
inline double WorkDetails::_internal_initial_file_start() const {
  return initial_file_start_;
}
inline double WorkDetails::initial_file_start() const {
  // @@protoc_insertion_point(field_get:masterworker.WorkDetails.initial_file_start)
  return _internal_initial_file_start();
}
inline void WorkDetails::_internal_set_initial_file_start(double value) {
  
  initial_file_start_ = value;
}
inline void WorkDetails::set_initial_file_start(double value) {
  _internal_set_initial_file_start(value);
  // @@protoc_insertion_point(field_set:masterworker.WorkDetails.initial_file_start)
}

// repeated .masterworker.FileInfo FileDetails = 2;
inline int WorkDetails::_internal_filedetails_size() const {
  return filedetails_.size();
}
inline int WorkDetails::filedetails_size() const {
  return _internal_filedetails_size();
}
inline void WorkDetails::clear_filedetails() {
  filedetails_.Clear();
}
inline ::masterworker::FileInfo* WorkDetails::mutable_filedetails(int index) {
  // @@protoc_insertion_point(field_mutable:masterworker.WorkDetails.FileDetails)
  return filedetails_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::masterworker::FileInfo >*
WorkDetails::mutable_filedetails() {
  // @@protoc_insertion_point(field_mutable_list:masterworker.WorkDetails.FileDetails)
  return &filedetails_;
}
inline const ::masterworker::FileInfo& WorkDetails::_internal_filedetails(int index) const {
  return filedetails_.Get(index);
}
inline const ::masterworker::FileInfo& WorkDetails::filedetails(int index) const {
  // @@protoc_insertion_point(field_get:masterworker.WorkDetails.FileDetails)
  return _internal_filedetails(index);
}
inline ::masterworker::FileInfo* WorkDetails::_internal_add_filedetails() {
  return filedetails_.Add();
}
inline ::masterworker::FileInfo* WorkDetails::add_filedetails() {
  // @@protoc_insertion_point(field_add:masterworker.WorkDetails.FileDetails)
  return _internal_add_filedetails();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::masterworker::FileInfo >&
WorkDetails::filedetails() const {
  // @@protoc_insertion_point(field_list:masterworker.WorkDetails.FileDetails)
  return filedetails_;
}

// string user_id = 3;
inline void WorkDetails::clear_user_id() {
  user_id_.ClearToEmpty();
}
inline const std::string& WorkDetails::user_id() const {
  // @@protoc_insertion_point(field_get:masterworker.WorkDetails.user_id)
  return _internal_user_id();
}
inline void WorkDetails::set_user_id(const std::string& value) {
  _internal_set_user_id(value);
  // @@protoc_insertion_point(field_set:masterworker.WorkDetails.user_id)
}
inline std::string* WorkDetails::mutable_user_id() {
  // @@protoc_insertion_point(field_mutable:masterworker.WorkDetails.user_id)
  return _internal_mutable_user_id();
}
inline const std::string& WorkDetails::_internal_user_id() const {
  return user_id_.Get();
}
inline void WorkDetails::_internal_set_user_id(const std::string& value) {
  
  user_id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArena());
}
inline void WorkDetails::set_user_id(std::string&& value) {
  
  user_id_.Set(
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:masterworker.WorkDetails.user_id)
}
inline void WorkDetails::set_user_id(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  user_id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(value), GetArena());
  // @@protoc_insertion_point(field_set_char:masterworker.WorkDetails.user_id)
}
inline void WorkDetails::set_user_id(const char* value,
    size_t size) {
  
  user_id_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:masterworker.WorkDetails.user_id)
}
inline std::string* WorkDetails::_internal_mutable_user_id() {
  
  return user_id_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArena());
}
inline std::string* WorkDetails::release_user_id() {
  // @@protoc_insertion_point(field_release:masterworker.WorkDetails.user_id)
  return user_id_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void WorkDetails::set_allocated_user_id(std::string* user_id) {
  if (user_id != nullptr) {
    
  } else {
    
  }
  user_id_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), user_id,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:masterworker.WorkDetails.user_id)
}

// bool is_mapper = 4;
inline void WorkDetails::clear_is_mapper() {
  is_mapper_ = false;
}
inline bool WorkDetails::_internal_is_mapper() const {
  return is_mapper_;
}
inline bool WorkDetails::is_mapper() const {
  // @@protoc_insertion_point(field_get:masterworker.WorkDetails.is_mapper)
  return _internal_is_mapper();
}
inline void WorkDetails::_internal_set_is_mapper(bool value) {
  
  is_mapper_ = value;
}
inline void WorkDetails::set_is_mapper(bool value) {
  _internal_set_is_mapper(value);
  // @@protoc_insertion_point(field_set:masterworker.WorkDetails.is_mapper)
}

// double job_id = 5;
inline void WorkDetails::clear_job_id() {
  job_id_ = 0;
}
inline double WorkDetails::_internal_job_id() const {
  return job_id_;
}
inline double WorkDetails::job_id() const {
  // @@protoc_insertion_point(field_get:masterworker.WorkDetails.job_id)
  return _internal_job_id();
}
inline void WorkDetails::_internal_set_job_id(double value) {
  
  job_id_ = value;
}
inline void WorkDetails::set_job_id(double value) {
  _internal_set_job_id(value);
  // @@protoc_insertion_point(field_set:masterworker.WorkDetails.job_id)
}

// double file_count = 6;
inline void WorkDetails::clear_file_count() {
  file_count_ = 0;
}
inline double WorkDetails::_internal_file_count() const {
  return file_count_;
}
inline double WorkDetails::file_count() const {
  // @@protoc_insertion_point(field_get:masterworker.WorkDetails.file_count)
  return _internal_file_count();
}
inline void WorkDetails::_internal_set_file_count(double value) {
  
  file_count_ = value;
}
inline void WorkDetails::set_file_count(double value) {
  _internal_set_file_count(value);
  // @@protoc_insertion_point(field_set:masterworker.WorkDetails.file_count)
}

// repeated double completed_jobs = 7;
inline int WorkDetails::_internal_completed_jobs_size() const {
  return completed_jobs_.size();
}
inline int WorkDetails::completed_jobs_size() const {
  return _internal_completed_jobs_size();
}
inline void WorkDetails::clear_completed_jobs() {
  completed_jobs_.Clear();
}
inline double WorkDetails::_internal_completed_jobs(int index) const {
  return completed_jobs_.Get(index);
}
inline double WorkDetails::completed_jobs(int index) const {
  // @@protoc_insertion_point(field_get:masterworker.WorkDetails.completed_jobs)
  return _internal_completed_jobs(index);
}
inline void WorkDetails::set_completed_jobs(int index, double value) {
  completed_jobs_.Set(index, value);
  // @@protoc_insertion_point(field_set:masterworker.WorkDetails.completed_jobs)
}
inline void WorkDetails::_internal_add_completed_jobs(double value) {
  completed_jobs_.Add(value);
}
inline void WorkDetails::add_completed_jobs(double value) {
  _internal_add_completed_jobs(value);
  // @@protoc_insertion_point(field_add:masterworker.WorkDetails.completed_jobs)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
WorkDetails::_internal_completed_jobs() const {
  return completed_jobs_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >&
WorkDetails::completed_jobs() const {
  // @@protoc_insertion_point(field_list:masterworker.WorkDetails.completed_jobs)
  return _internal_completed_jobs();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
WorkDetails::_internal_mutable_completed_jobs() {
  return &completed_jobs_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< double >*
WorkDetails::mutable_completed_jobs() {
  // @@protoc_insertion_point(field_mutable_list:masterworker.WorkDetails.completed_jobs)
  return _internal_mutable_completed_jobs();
}

// -------------------------------------------------------------------

// WorkConfirmation

// bool is_mapper = 1;
inline void WorkConfirmation::clear_is_mapper() {
  is_mapper_ = false;
}
inline bool WorkConfirmation::_internal_is_mapper() const {
  return is_mapper_;
}
inline bool WorkConfirmation::is_mapper() const {
  // @@protoc_insertion_point(field_get:masterworker.WorkConfirmation.is_mapper)
  return _internal_is_mapper();
}
inline void WorkConfirmation::_internal_set_is_mapper(bool value) {
  
  is_mapper_ = value;
}
inline void WorkConfirmation::set_is_mapper(bool value) {
  _internal_set_is_mapper(value);
  // @@protoc_insertion_point(field_set:masterworker.WorkConfirmation.is_mapper)
}

// double job_id = 2;
inline void WorkConfirmation::clear_job_id() {
  job_id_ = 0;
}
inline double WorkConfirmation::_internal_job_id() const {
  return job_id_;
}
inline double WorkConfirmation::job_id() const {
  // @@protoc_insertion_point(field_get:masterworker.WorkConfirmation.job_id)
  return _internal_job_id();
}
inline void WorkConfirmation::_internal_set_job_id(double value) {
  
  job_id_ = value;
}
inline void WorkConfirmation::set_job_id(double value) {
  _internal_set_job_id(value);
  // @@protoc_insertion_point(field_set:masterworker.WorkConfirmation.job_id)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace masterworker

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_masterworker_2eproto