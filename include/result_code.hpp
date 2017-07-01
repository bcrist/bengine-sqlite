#pragma once
#ifndef BE_SQLITE_RESULT_CODE_HPP_
#define BE_SQLITE_RESULT_CODE_HPP_

#include "sqlite_autolink.hpp"
#include "sqlite.hpp"
#include <be/core/enum_traits.hpp>

/*!! include 'result_code' !! 321 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
enum class ResultCode : U8 {
   ok = SQLITE_OK,
   error = SQLITE_ERROR,
   internal_error = SQLITE_INTERNAL,
   permission_denied = SQLITE_PERM,
   aborted = SQLITE_ABORT,
   database_locked = SQLITE_BUSY,
   table_locked = SQLITE_LOCKED,
   not_enough_memory = SQLITE_NOMEM,
   read_only_database = SQLITE_READONLY,
   interrupted = SQLITE_INTERRUPT,
   io_error = SQLITE_IOERR,
   database_corrupt = SQLITE_CORRUPT,
   opcode_not_found = SQLITE_NOTFOUND,
   no_space_on_device = SQLITE_FULL,
   cant_open_file = SQLITE_CANTOPEN,
   lock_protocol_error = SQLITE_PROTOCOL,
   database_empty = SQLITE_EMPTY,
   schema_changed = SQLITE_SCHEMA,
   field_length_error = SQLITE_TOOBIG,
   constraint_error = SQLITE_CONSTRAINT,
   data_type_mismatch = SQLITE_MISMATCH,
   api_misuse = SQLITE_MISUSE,
   no_large_file_support = SQLITE_NOLFS,
   authorization_denied = SQLITE_AUTH,
   format_error = SQLITE_FORMAT,
   out_of_range = SQLITE_RANGE,
   not_a_database = SQLITE_NOTADB,
   notice = SQLITE_NOTICE,
   warning = SQLITE_WARNING,
   row_available = SQLITE_ROW,
   done = SQLITE_DONE
};

bool is_valid(ResultCode constant) noexcept;
const char* result_code_name(ResultCode constant) noexcept;
std::array<const ResultCode, 31> result_code_values() noexcept;
std::ostream& operator<<(std::ostream& os, ResultCode constant);

} // be::sqlite

namespace be {

///////////////////////////////////////////////////////////////////////////////
template <>
struct EnumTraits<::be::sqlite::ResultCode> {
   using type = ::be::sqlite::ResultCode;
   using underlying_type = typename std::underlying_type<type>::type;

   static constexpr std::size_t count = 31;

   static bool is_valid(type value) {
      return ::be::sqlite::is_valid(value);
   }

   static const char* name(type value) {
      return ::be::sqlite::result_code_name(value);
   }

   template <typename C = std::array<const type, count>>
   static C values() {
      return {
         ::be::sqlite::ResultCode::ok,
         ::be::sqlite::ResultCode::error,
         ::be::sqlite::ResultCode::internal_error,
         ::be::sqlite::ResultCode::permission_denied,
         ::be::sqlite::ResultCode::aborted,
         ::be::sqlite::ResultCode::database_locked,
         ::be::sqlite::ResultCode::table_locked,
         ::be::sqlite::ResultCode::not_enough_memory,
         ::be::sqlite::ResultCode::read_only_database,
         ::be::sqlite::ResultCode::interrupted,
         ::be::sqlite::ResultCode::io_error,
         ::be::sqlite::ResultCode::database_corrupt,
         ::be::sqlite::ResultCode::opcode_not_found,
         ::be::sqlite::ResultCode::no_space_on_device,
         ::be::sqlite::ResultCode::cant_open_file,
         ::be::sqlite::ResultCode::lock_protocol_error,
         ::be::sqlite::ResultCode::database_empty,
         ::be::sqlite::ResultCode::schema_changed,
         ::be::sqlite::ResultCode::field_length_error,
         ::be::sqlite::ResultCode::constraint_error,
         ::be::sqlite::ResultCode::data_type_mismatch,
         ::be::sqlite::ResultCode::api_misuse,
         ::be::sqlite::ResultCode::no_large_file_support,
         ::be::sqlite::ResultCode::authorization_denied,
         ::be::sqlite::ResultCode::format_error,
         ::be::sqlite::ResultCode::out_of_range,
         ::be::sqlite::ResultCode::not_a_database,
         ::be::sqlite::ResultCode::notice,
         ::be::sqlite::ResultCode::warning,
         ::be::sqlite::ResultCode::row_available,
         ::be::sqlite::ResultCode::done,
      };
   }
};

} // be

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
enum class ExtendedResultCode : U16 {
   ok = SQLITE_OK,
   error = SQLITE_ERROR,
   internal_error = SQLITE_INTERNAL,
   permission_denied = SQLITE_PERM,
   aborted = SQLITE_ABORT,
   database_locked = SQLITE_BUSY,
   table_locked = SQLITE_LOCKED,
   not_enough_memory = SQLITE_NOMEM,
   read_only_database = SQLITE_READONLY,
   interrupted = SQLITE_INTERRUPT,
   io_error = SQLITE_IOERR,
   database_corrupt = SQLITE_CORRUPT,
   opcode_not_found = SQLITE_NOTFOUND,
   no_space_on_device = SQLITE_FULL,
   cant_open_file = SQLITE_CANTOPEN,
   lock_protocol_error = SQLITE_PROTOCOL,
   database_empty = SQLITE_EMPTY,
   schema_changed = SQLITE_SCHEMA,
   field_length_error = SQLITE_TOOBIG,
   constraint_error = SQLITE_CONSTRAINT,
   data_type_mismatch = SQLITE_MISMATCH,
   api_misuse = SQLITE_MISUSE,
   no_large_file_support = SQLITE_NOLFS,
   authorization_denied = SQLITE_AUTH,
   format_error = SQLITE_FORMAT,
   out_of_range = SQLITE_RANGE,
   not_a_database = SQLITE_NOTADB,
   notice = SQLITE_NOTICE,
   warning = SQLITE_WARNING,
   row_available = SQLITE_ROW,
   done = SQLITE_DONE,
   io_error_read = SQLITE_IOERR_READ,
   io_error_short_read = SQLITE_IOERR_SHORT_READ,
   io_error_write = SQLITE_IOERR_WRITE,
   io_error_fsync = SQLITE_IOERR_FSYNC,
   io_error_dir_fsync = SQLITE_IOERR_DIR_FSYNC,
   io_error_truncate = SQLITE_IOERR_TRUNCATE,
   io_error_fstat = SQLITE_IOERR_FSTAT,
   io_error_unlock = SQLITE_IOERR_UNLOCK,
   io_error_rdlock = SQLITE_IOERR_RDLOCK,
   io_error_delete = SQLITE_IOERR_DELETE,
   io_error_blocked = SQLITE_IOERR_BLOCKED,
   io_error_not_enough_memory = SQLITE_IOERR_NOMEM,
   io_error_access = SQLITE_IOERR_ACCESS,
   io_error_check_reserved_lock = SQLITE_IOERR_CHECKRESERVEDLOCK,
   io_error_lock = SQLITE_IOERR_LOCK,
   io_error_close = SQLITE_IOERR_CLOSE,
   io_error_dir_close = SQLITE_IOERR_DIR_CLOSE,
   io_error_shm_open = SQLITE_IOERR_SHMOPEN,
   io_error_shm_size = SQLITE_IOERR_SHMSIZE,
   io_error_shm_lock = SQLITE_IOERR_SHMLOCK,
   io_error_shm_map = SQLITE_IOERR_SHMMAP,
   io_error_seek = SQLITE_IOERR_SEEK,
   io_error_delete_noent = SQLITE_IOERR_DELETE_NOENT,
   io_error_mmap = SQLITE_IOERR_MMAP,
   io_error_get_temp_path = SQLITE_IOERR_GETTEMPPATH,
   io_error_convert_path = SQLITE_IOERR_CONVPATH,
   io_error_vnode = SQLITE_IOERR_VNODE,
   io_error_auth = SQLITE_IOERR_AUTH,
   table_locked_shared_cache = SQLITE_LOCKED_SHAREDCACHE,
   database_locked_recovery = SQLITE_BUSY_RECOVERY,
   database_locked_snapshot = SQLITE_BUSY_SNAPSHOT,
   cant_open_file_no_temp_dir = SQLITE_CANTOPEN_NOTEMPDIR,
   cant_open_file_is_dir = SQLITE_CANTOPEN_ISDIR,
   cant_open_file_full_path = SQLITE_CANTOPEN_FULLPATH,
   cant_open_file_conv_path = SQLITE_CANTOPEN_CONVPATH,
   database_corrupt_vtab = SQLITE_CORRUPT_VTAB,
   read_only_database_recovery = SQLITE_READONLY_RECOVERY,
   read_only_database_cant_lock = SQLITE_READONLY_CANTLOCK,
   read_only_database_rollback = SQLITE_READONLY_ROLLBACK,
   read_only_database_moved = SQLITE_READONLY_DBMOVED,
   aborted_rollback = SQLITE_ABORT_ROLLBACK,
   constraint_error_check = SQLITE_CONSTRAINT_CHECK,
   constraint_error_commit_hook = SQLITE_CONSTRAINT_COMMITHOOK,
   constraint_error_foreign_key = SQLITE_CONSTRAINT_FOREIGNKEY,
   constraint_error_function = SQLITE_CONSTRAINT_FUNCTION,
   constraint_error_not_null = SQLITE_CONSTRAINT_NOTNULL,
   constraint_error_primary_key = SQLITE_CONSTRAINT_PRIMARYKEY,
   constraint_error_trigger = SQLITE_CONSTRAINT_TRIGGER,
   constraint_error_unique = SQLITE_CONSTRAINT_UNIQUE,
   constraint_error_vtab = SQLITE_CONSTRAINT_VTAB,
   constraint_error_rowid = SQLITE_CONSTRAINT_ROWID,
   notice_recover_wal = SQLITE_NOTICE_RECOVER_WAL,
   notice_recover_rollback = SQLITE_NOTICE_RECOVER_ROLLBACK,
   warning_autoindex = SQLITE_WARNING_AUTOINDEX,
   authorization_denied_user = SQLITE_AUTH_USER,
   ok_load_permanently = SQLITE_OK_LOAD_PERMANENTLY
};

bool is_valid(ExtendedResultCode constant) noexcept;
const char* extended_result_code_name(ExtendedResultCode constant) noexcept;
std::array<const ExtendedResultCode, 87> extended_result_code_values() noexcept;
std::ostream& operator<<(std::ostream& os, ExtendedResultCode constant);
int generic_error_condition(ExtendedResultCode constant) noexcept;

} // be::sqlite

namespace be {

///////////////////////////////////////////////////////////////////////////////
template <>
struct EnumTraits<::be::sqlite::ExtendedResultCode> {
   using type = ::be::sqlite::ExtendedResultCode;
   using underlying_type = typename std::underlying_type<type>::type;

   static constexpr std::size_t count = 87;

   static bool is_valid(type value) {
      return ::be::sqlite::is_valid(value);
   }

   static const char* name(type value) {
      return ::be::sqlite::extended_result_code_name(value);
   }

   template <typename C = std::array<const type, count>>
   static C values() {
      return {
         ::be::sqlite::ExtendedResultCode::ok,
         ::be::sqlite::ExtendedResultCode::error,
         ::be::sqlite::ExtendedResultCode::internal_error,
         ::be::sqlite::ExtendedResultCode::permission_denied,
         ::be::sqlite::ExtendedResultCode::aborted,
         ::be::sqlite::ExtendedResultCode::database_locked,
         ::be::sqlite::ExtendedResultCode::table_locked,
         ::be::sqlite::ExtendedResultCode::not_enough_memory,
         ::be::sqlite::ExtendedResultCode::read_only_database,
         ::be::sqlite::ExtendedResultCode::interrupted,
         ::be::sqlite::ExtendedResultCode::io_error,
         ::be::sqlite::ExtendedResultCode::database_corrupt,
         ::be::sqlite::ExtendedResultCode::opcode_not_found,
         ::be::sqlite::ExtendedResultCode::no_space_on_device,
         ::be::sqlite::ExtendedResultCode::cant_open_file,
         ::be::sqlite::ExtendedResultCode::lock_protocol_error,
         ::be::sqlite::ExtendedResultCode::database_empty,
         ::be::sqlite::ExtendedResultCode::schema_changed,
         ::be::sqlite::ExtendedResultCode::field_length_error,
         ::be::sqlite::ExtendedResultCode::constraint_error,
         ::be::sqlite::ExtendedResultCode::data_type_mismatch,
         ::be::sqlite::ExtendedResultCode::api_misuse,
         ::be::sqlite::ExtendedResultCode::no_large_file_support,
         ::be::sqlite::ExtendedResultCode::authorization_denied,
         ::be::sqlite::ExtendedResultCode::format_error,
         ::be::sqlite::ExtendedResultCode::out_of_range,
         ::be::sqlite::ExtendedResultCode::not_a_database,
         ::be::sqlite::ExtendedResultCode::notice,
         ::be::sqlite::ExtendedResultCode::warning,
         ::be::sqlite::ExtendedResultCode::row_available,
         ::be::sqlite::ExtendedResultCode::done,
         ::be::sqlite::ExtendedResultCode::io_error_read,
         ::be::sqlite::ExtendedResultCode::io_error_short_read,
         ::be::sqlite::ExtendedResultCode::io_error_write,
         ::be::sqlite::ExtendedResultCode::io_error_fsync,
         ::be::sqlite::ExtendedResultCode::io_error_dir_fsync,
         ::be::sqlite::ExtendedResultCode::io_error_truncate,
         ::be::sqlite::ExtendedResultCode::io_error_fstat,
         ::be::sqlite::ExtendedResultCode::io_error_unlock,
         ::be::sqlite::ExtendedResultCode::io_error_rdlock,
         ::be::sqlite::ExtendedResultCode::io_error_delete,
         ::be::sqlite::ExtendedResultCode::io_error_blocked,
         ::be::sqlite::ExtendedResultCode::io_error_not_enough_memory,
         ::be::sqlite::ExtendedResultCode::io_error_access,
         ::be::sqlite::ExtendedResultCode::io_error_check_reserved_lock,
         ::be::sqlite::ExtendedResultCode::io_error_lock,
         ::be::sqlite::ExtendedResultCode::io_error_close,
         ::be::sqlite::ExtendedResultCode::io_error_dir_close,
         ::be::sqlite::ExtendedResultCode::io_error_shm_open,
         ::be::sqlite::ExtendedResultCode::io_error_shm_size,
         ::be::sqlite::ExtendedResultCode::io_error_shm_lock,
         ::be::sqlite::ExtendedResultCode::io_error_shm_map,
         ::be::sqlite::ExtendedResultCode::io_error_seek,
         ::be::sqlite::ExtendedResultCode::io_error_delete_noent,
         ::be::sqlite::ExtendedResultCode::io_error_mmap,
         ::be::sqlite::ExtendedResultCode::io_error_get_temp_path,
         ::be::sqlite::ExtendedResultCode::io_error_convert_path,
         ::be::sqlite::ExtendedResultCode::io_error_vnode,
         ::be::sqlite::ExtendedResultCode::io_error_auth,
         ::be::sqlite::ExtendedResultCode::table_locked_shared_cache,
         ::be::sqlite::ExtendedResultCode::database_locked_recovery,
         ::be::sqlite::ExtendedResultCode::database_locked_snapshot,
         ::be::sqlite::ExtendedResultCode::cant_open_file_no_temp_dir,
         ::be::sqlite::ExtendedResultCode::cant_open_file_is_dir,
         ::be::sqlite::ExtendedResultCode::cant_open_file_full_path,
         ::be::sqlite::ExtendedResultCode::cant_open_file_conv_path,
         ::be::sqlite::ExtendedResultCode::database_corrupt_vtab,
         ::be::sqlite::ExtendedResultCode::read_only_database_recovery,
         ::be::sqlite::ExtendedResultCode::read_only_database_cant_lock,
         ::be::sqlite::ExtendedResultCode::read_only_database_rollback,
         ::be::sqlite::ExtendedResultCode::read_only_database_moved,
         ::be::sqlite::ExtendedResultCode::aborted_rollback,
         ::be::sqlite::ExtendedResultCode::constraint_error_check,
         ::be::sqlite::ExtendedResultCode::constraint_error_commit_hook,
         ::be::sqlite::ExtendedResultCode::constraint_error_foreign_key,
         ::be::sqlite::ExtendedResultCode::constraint_error_function,
         ::be::sqlite::ExtendedResultCode::constraint_error_not_null,
         ::be::sqlite::ExtendedResultCode::constraint_error_primary_key,
         ::be::sqlite::ExtendedResultCode::constraint_error_trigger,
         ::be::sqlite::ExtendedResultCode::constraint_error_unique,
         ::be::sqlite::ExtendedResultCode::constraint_error_vtab,
         ::be::sqlite::ExtendedResultCode::constraint_error_rowid,
         ::be::sqlite::ExtendedResultCode::notice_recover_wal,
         ::be::sqlite::ExtendedResultCode::notice_recover_rollback,
         ::be::sqlite::ExtendedResultCode::warning_autoindex,
         ::be::sqlite::ExtendedResultCode::authorization_denied_user,
         ::be::sqlite::ExtendedResultCode::ok_load_permanently,
      };
   }
};

} // be

/* ######################### END OF GENERATED CODE ######################### */

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
class ResultCodeErrorCategory : public std::error_category {
public:
   virtual const char* name() const noexcept { return "SQLite Result Code"; }
   virtual S message(int condition) const;
   virtual bool equivalent(int code, const std::error_condition& condition) const noexcept;
};

const std::error_category& result_code_error_category();
std::error_code make_error_code(ResultCode e);
std::error_condition make_error_condition(ResultCode e);
std::error_code make_error_code(ExtendedResultCode e);
std::error_condition make_error_condition(ExtendedResultCode e);
ExtendedResultCode ext_result_code(int result);

} // be::sqlite

namespace std {

///////////////////////////////////////////////////////////////////////////////
template <>
struct is_error_code_enum<be::sqlite::ExtendedResultCode> : std::true_type { };

///////////////////////////////////////////////////////////////////////////////
template <>
struct is_error_condition_enum<be::sqlite::ResultCode> : std::true_type { };

} // std

#endif
