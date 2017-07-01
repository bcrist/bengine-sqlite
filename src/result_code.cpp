#include "pch.hpp"
#include "result_code.hpp"
#include "sqlite.hpp"

/*!! include 'result_code' !! 372 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
bool is_valid(ResultCode constant) noexcept {
   switch (constant) {
      case ResultCode::ok:
      case ResultCode::error:
      case ResultCode::internal_error:
      case ResultCode::permission_denied:
      case ResultCode::aborted:
      case ResultCode::database_locked:
      case ResultCode::table_locked:
      case ResultCode::not_enough_memory:
      case ResultCode::read_only_database:
      case ResultCode::interrupted:
      case ResultCode::io_error:
      case ResultCode::database_corrupt:
      case ResultCode::opcode_not_found:
      case ResultCode::no_space_on_device:
      case ResultCode::cant_open_file:
      case ResultCode::lock_protocol_error:
      case ResultCode::database_empty:
      case ResultCode::schema_changed:
      case ResultCode::field_length_error:
      case ResultCode::constraint_error:
      case ResultCode::data_type_mismatch:
      case ResultCode::api_misuse:
      case ResultCode::no_large_file_support:
      case ResultCode::authorization_denied:
      case ResultCode::format_error:
      case ResultCode::out_of_range:
      case ResultCode::not_a_database:
      case ResultCode::notice:
      case ResultCode::warning:
      case ResultCode::row_available:
      case ResultCode::done:
         return true;
      default:
         return false;
   }
}

///////////////////////////////////////////////////////////////////////////////
const char* result_code_name(ResultCode constant) noexcept {
   switch (constant) {
      case ResultCode::ok:                    return "ok";
      case ResultCode::error:                 return "error";
      case ResultCode::internal_error:        return "internal_error";
      case ResultCode::permission_denied:     return "permission_denied";
      case ResultCode::aborted:               return "aborted";
      case ResultCode::database_locked:       return "database_locked";
      case ResultCode::table_locked:          return "table_locked";
      case ResultCode::not_enough_memory:     return "not_enough_memory";
      case ResultCode::read_only_database:    return "read_only_database";
      case ResultCode::interrupted:           return "interrupted";
      case ResultCode::io_error:              return "io_error";
      case ResultCode::database_corrupt:      return "database_corrupt";
      case ResultCode::opcode_not_found:      return "opcode_not_found";
      case ResultCode::no_space_on_device:    return "no_space_on_device";
      case ResultCode::cant_open_file:        return "cant_open_file";
      case ResultCode::lock_protocol_error:   return "lock_protocol_error";
      case ResultCode::database_empty:        return "database_empty";
      case ResultCode::schema_changed:        return "schema_changed";
      case ResultCode::field_length_error:    return "field_length_error";
      case ResultCode::constraint_error:      return "constraint_error";
      case ResultCode::data_type_mismatch:    return "data_type_mismatch";
      case ResultCode::api_misuse:            return "api_misuse";
      case ResultCode::no_large_file_support: return "no_large_file_support";
      case ResultCode::authorization_denied:  return "authorization_denied";
      case ResultCode::format_error:          return "format_error";
      case ResultCode::out_of_range:          return "out_of_range";
      case ResultCode::not_a_database:        return "not_a_database";
      case ResultCode::notice:                return "notice";
      case ResultCode::warning:               return "warning";
      case ResultCode::row_available:         return "row_available";
      case ResultCode::done:                  return "done";
      default:
         return "?";
   }
}

///////////////////////////////////////////////////////////////////////////////
std::array<const ResultCode, 31> result_code_values() noexcept {
   return ::be::EnumTraits<ResultCode>::values<>();
}

///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, ResultCode constant) {
   if (is_valid(constant)) {
      os << result_code_name(constant);
   } else {
      os << static_cast<I64>(static_cast<U8>(constant));
   }
   return os;
}

} // be::sqlite


namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
bool is_valid(ExtendedResultCode constant) noexcept {
   switch (constant) {
      case ExtendedResultCode::ok:
      case ExtendedResultCode::error:
      case ExtendedResultCode::internal_error:
      case ExtendedResultCode::permission_denied:
      case ExtendedResultCode::aborted:
      case ExtendedResultCode::database_locked:
      case ExtendedResultCode::table_locked:
      case ExtendedResultCode::not_enough_memory:
      case ExtendedResultCode::read_only_database:
      case ExtendedResultCode::interrupted:
      case ExtendedResultCode::io_error:
      case ExtendedResultCode::database_corrupt:
      case ExtendedResultCode::opcode_not_found:
      case ExtendedResultCode::no_space_on_device:
      case ExtendedResultCode::cant_open_file:
      case ExtendedResultCode::lock_protocol_error:
      case ExtendedResultCode::database_empty:
      case ExtendedResultCode::schema_changed:
      case ExtendedResultCode::field_length_error:
      case ExtendedResultCode::constraint_error:
      case ExtendedResultCode::data_type_mismatch:
      case ExtendedResultCode::api_misuse:
      case ExtendedResultCode::no_large_file_support:
      case ExtendedResultCode::authorization_denied:
      case ExtendedResultCode::format_error:
      case ExtendedResultCode::out_of_range:
      case ExtendedResultCode::not_a_database:
      case ExtendedResultCode::notice:
      case ExtendedResultCode::warning:
      case ExtendedResultCode::row_available:
      case ExtendedResultCode::done:
      case ExtendedResultCode::io_error_read:
      case ExtendedResultCode::io_error_short_read:
      case ExtendedResultCode::io_error_write:
      case ExtendedResultCode::io_error_fsync:
      case ExtendedResultCode::io_error_dir_fsync:
      case ExtendedResultCode::io_error_truncate:
      case ExtendedResultCode::io_error_fstat:
      case ExtendedResultCode::io_error_unlock:
      case ExtendedResultCode::io_error_rdlock:
      case ExtendedResultCode::io_error_delete:
      case ExtendedResultCode::io_error_blocked:
      case ExtendedResultCode::io_error_not_enough_memory:
      case ExtendedResultCode::io_error_access:
      case ExtendedResultCode::io_error_check_reserved_lock:
      case ExtendedResultCode::io_error_lock:
      case ExtendedResultCode::io_error_close:
      case ExtendedResultCode::io_error_dir_close:
      case ExtendedResultCode::io_error_shm_open:
      case ExtendedResultCode::io_error_shm_size:
      case ExtendedResultCode::io_error_shm_lock:
      case ExtendedResultCode::io_error_shm_map:
      case ExtendedResultCode::io_error_seek:
      case ExtendedResultCode::io_error_delete_noent:
      case ExtendedResultCode::io_error_mmap:
      case ExtendedResultCode::io_error_get_temp_path:
      case ExtendedResultCode::io_error_convert_path:
      case ExtendedResultCode::io_error_vnode:
      case ExtendedResultCode::io_error_auth:
      case ExtendedResultCode::table_locked_shared_cache:
      case ExtendedResultCode::database_locked_recovery:
      case ExtendedResultCode::database_locked_snapshot:
      case ExtendedResultCode::cant_open_file_no_temp_dir:
      case ExtendedResultCode::cant_open_file_is_dir:
      case ExtendedResultCode::cant_open_file_full_path:
      case ExtendedResultCode::cant_open_file_conv_path:
      case ExtendedResultCode::database_corrupt_vtab:
      case ExtendedResultCode::read_only_database_recovery:
      case ExtendedResultCode::read_only_database_cant_lock:
      case ExtendedResultCode::read_only_database_rollback:
      case ExtendedResultCode::read_only_database_moved:
      case ExtendedResultCode::aborted_rollback:
      case ExtendedResultCode::constraint_error_check:
      case ExtendedResultCode::constraint_error_commit_hook:
      case ExtendedResultCode::constraint_error_foreign_key:
      case ExtendedResultCode::constraint_error_function:
      case ExtendedResultCode::constraint_error_not_null:
      case ExtendedResultCode::constraint_error_primary_key:
      case ExtendedResultCode::constraint_error_trigger:
      case ExtendedResultCode::constraint_error_unique:
      case ExtendedResultCode::constraint_error_vtab:
      case ExtendedResultCode::constraint_error_rowid:
      case ExtendedResultCode::notice_recover_wal:
      case ExtendedResultCode::notice_recover_rollback:
      case ExtendedResultCode::warning_autoindex:
      case ExtendedResultCode::authorization_denied_user:
      case ExtendedResultCode::ok_load_permanently:
         return true;
      default:
         return false;
   }
}

///////////////////////////////////////////////////////////////////////////////
const char* extended_result_code_name(ExtendedResultCode constant) noexcept {
   switch (constant) {
      case ExtendedResultCode::ok:                           return "ok";
      case ExtendedResultCode::error:                        return "error";
      case ExtendedResultCode::internal_error:               return "internal_error";
      case ExtendedResultCode::permission_denied:            return "permission_denied";
      case ExtendedResultCode::aborted:                      return "aborted";
      case ExtendedResultCode::database_locked:              return "database_locked";
      case ExtendedResultCode::table_locked:                 return "table_locked";
      case ExtendedResultCode::not_enough_memory:            return "not_enough_memory";
      case ExtendedResultCode::read_only_database:           return "read_only_database";
      case ExtendedResultCode::interrupted:                  return "interrupted";
      case ExtendedResultCode::io_error:                     return "io_error";
      case ExtendedResultCode::database_corrupt:             return "database_corrupt";
      case ExtendedResultCode::opcode_not_found:             return "opcode_not_found";
      case ExtendedResultCode::no_space_on_device:           return "no_space_on_device";
      case ExtendedResultCode::cant_open_file:               return "cant_open_file";
      case ExtendedResultCode::lock_protocol_error:          return "lock_protocol_error";
      case ExtendedResultCode::database_empty:               return "database_empty";
      case ExtendedResultCode::schema_changed:               return "schema_changed";
      case ExtendedResultCode::field_length_error:           return "field_length_error";
      case ExtendedResultCode::constraint_error:             return "constraint_error";
      case ExtendedResultCode::data_type_mismatch:           return "data_type_mismatch";
      case ExtendedResultCode::api_misuse:                   return "api_misuse";
      case ExtendedResultCode::no_large_file_support:        return "no_large_file_support";
      case ExtendedResultCode::authorization_denied:         return "authorization_denied";
      case ExtendedResultCode::format_error:                 return "format_error";
      case ExtendedResultCode::out_of_range:                 return "out_of_range";
      case ExtendedResultCode::not_a_database:               return "not_a_database";
      case ExtendedResultCode::notice:                       return "notice";
      case ExtendedResultCode::warning:                      return "warning";
      case ExtendedResultCode::row_available:                return "row_available";
      case ExtendedResultCode::done:                         return "done";
      case ExtendedResultCode::io_error_read:                return "io_error_read";
      case ExtendedResultCode::io_error_short_read:          return "io_error_short_read";
      case ExtendedResultCode::io_error_write:               return "io_error_write";
      case ExtendedResultCode::io_error_fsync:               return "io_error_fsync";
      case ExtendedResultCode::io_error_dir_fsync:           return "io_error_dir_fsync";
      case ExtendedResultCode::io_error_truncate:            return "io_error_truncate";
      case ExtendedResultCode::io_error_fstat:               return "io_error_fstat";
      case ExtendedResultCode::io_error_unlock:              return "io_error_unlock";
      case ExtendedResultCode::io_error_rdlock:              return "io_error_rdlock";
      case ExtendedResultCode::io_error_delete:              return "io_error_delete";
      case ExtendedResultCode::io_error_blocked:             return "io_error_blocked";
      case ExtendedResultCode::io_error_not_enough_memory:   return "io_error_not_enough_memory";
      case ExtendedResultCode::io_error_access:              return "io_error_access";
      case ExtendedResultCode::io_error_check_reserved_lock: return "io_error_check_reserved_lock";
      case ExtendedResultCode::io_error_lock:                return "io_error_lock";
      case ExtendedResultCode::io_error_close:               return "io_error_close";
      case ExtendedResultCode::io_error_dir_close:           return "io_error_dir_close";
      case ExtendedResultCode::io_error_shm_open:            return "io_error_shm_open";
      case ExtendedResultCode::io_error_shm_size:            return "io_error_shm_size";
      case ExtendedResultCode::io_error_shm_lock:            return "io_error_shm_lock";
      case ExtendedResultCode::io_error_shm_map:             return "io_error_shm_map";
      case ExtendedResultCode::io_error_seek:                return "io_error_seek";
      case ExtendedResultCode::io_error_delete_noent:        return "io_error_delete_noent";
      case ExtendedResultCode::io_error_mmap:                return "io_error_mmap";
      case ExtendedResultCode::io_error_get_temp_path:       return "io_error_get_temp_path";
      case ExtendedResultCode::io_error_convert_path:        return "io_error_convert_path";
      case ExtendedResultCode::io_error_vnode:               return "io_error_vnode";
      case ExtendedResultCode::io_error_auth:                return "io_error_auth";
      case ExtendedResultCode::table_locked_shared_cache:    return "table_locked_shared_cache";
      case ExtendedResultCode::database_locked_recovery:     return "database_locked_recovery";
      case ExtendedResultCode::database_locked_snapshot:     return "database_locked_snapshot";
      case ExtendedResultCode::cant_open_file_no_temp_dir:   return "cant_open_file_no_temp_dir";
      case ExtendedResultCode::cant_open_file_is_dir:        return "cant_open_file_is_dir";
      case ExtendedResultCode::cant_open_file_full_path:     return "cant_open_file_full_path";
      case ExtendedResultCode::cant_open_file_conv_path:     return "cant_open_file_conv_path";
      case ExtendedResultCode::database_corrupt_vtab:        return "database_corrupt_vtab";
      case ExtendedResultCode::read_only_database_recovery:  return "read_only_database_recovery";
      case ExtendedResultCode::read_only_database_cant_lock: return "read_only_database_cant_lock";
      case ExtendedResultCode::read_only_database_rollback:  return "read_only_database_rollback";
      case ExtendedResultCode::read_only_database_moved:     return "read_only_database_moved";
      case ExtendedResultCode::aborted_rollback:             return "aborted_rollback";
      case ExtendedResultCode::constraint_error_check:       return "constraint_error_check";
      case ExtendedResultCode::constraint_error_commit_hook: return "constraint_error_commit_hook";
      case ExtendedResultCode::constraint_error_foreign_key: return "constraint_error_foreign_key";
      case ExtendedResultCode::constraint_error_function:    return "constraint_error_function";
      case ExtendedResultCode::constraint_error_not_null:    return "constraint_error_not_null";
      case ExtendedResultCode::constraint_error_primary_key: return "constraint_error_primary_key";
      case ExtendedResultCode::constraint_error_trigger:     return "constraint_error_trigger";
      case ExtendedResultCode::constraint_error_unique:      return "constraint_error_unique";
      case ExtendedResultCode::constraint_error_vtab:        return "constraint_error_vtab";
      case ExtendedResultCode::constraint_error_rowid:       return "constraint_error_rowid";
      case ExtendedResultCode::notice_recover_wal:           return "notice_recover_wal";
      case ExtendedResultCode::notice_recover_rollback:      return "notice_recover_rollback";
      case ExtendedResultCode::warning_autoindex:            return "warning_autoindex";
      case ExtendedResultCode::authorization_denied_user:    return "authorization_denied_user";
      case ExtendedResultCode::ok_load_permanently:          return "ok_load_permanently";
      default:
         return "?";
   }
}

///////////////////////////////////////////////////////////////////////////////
std::array<const ExtendedResultCode, 87> extended_result_code_values() noexcept {
   return ::be::EnumTraits<ExtendedResultCode>::values<>();
}

///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, ExtendedResultCode constant) {
   if (is_valid(constant)) {
      os << extended_result_code_name(constant);
   } else {
      os << static_cast<I64>(static_cast<U16>(constant));
   }
   return os;
}

///////////////////////////////////////////////////////////////////////////////
int generic_error_condition(ExtendedResultCode constant) noexcept {
   switch (constant) {
      case ExtendedResultCode::permission_denied:            return static_cast<int>(std::errc::permission_denied);
      case ExtendedResultCode::database_locked:              return static_cast<int>(std::errc::device_or_resource_busy);
      case ExtendedResultCode::not_enough_memory:            return static_cast<int>(std::errc::not_enough_memory);
      case ExtendedResultCode::read_only_database:           return static_cast<int>(std::errc::read_only_file_system);
      case ExtendedResultCode::interrupted:                  return static_cast<int>(std::errc::interrupted);
      case ExtendedResultCode::io_error:                     return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::no_space_on_device:           return static_cast<int>(std::errc::no_space_on_device);
      case ExtendedResultCode::cant_open_file:               return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::field_length_error:           return static_cast<int>(std::errc::value_too_large);
      case ExtendedResultCode::authorization_denied:         return static_cast<int>(std::errc::permission_denied);
      case ExtendedResultCode::out_of_range:                 return static_cast<int>(std::errc::result_out_of_range);
      case ExtendedResultCode::io_error_read:                return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_short_read:          return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_write:               return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_fsync:               return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_dir_fsync:           return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_truncate:            return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_fstat:               return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_unlock:              return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_rdlock:              return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_delete:              return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_blocked:             return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_not_enough_memory:   return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_access:              return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_check_reserved_lock: return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_lock:                return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_close:               return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_dir_close:           return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_shm_open:            return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_shm_size:            return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_shm_lock:            return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_shm_map:             return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_seek:                return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_delete_noent:        return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_mmap:                return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_get_temp_path:       return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_convert_path:        return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_vnode:               return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::io_error_auth:                return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::database_locked_recovery:     return static_cast<int>(std::errc::device_or_resource_busy);
      case ExtendedResultCode::database_locked_snapshot:     return static_cast<int>(std::errc::device_or_resource_busy);
      case ExtendedResultCode::cant_open_file_no_temp_dir:   return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::cant_open_file_is_dir:        return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::cant_open_file_full_path:     return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::cant_open_file_conv_path:     return static_cast<int>(std::errc::io_error);
      case ExtendedResultCode::read_only_database_recovery:  return static_cast<int>(std::errc::read_only_file_system);
      case ExtendedResultCode::read_only_database_cant_lock: return static_cast<int>(std::errc::read_only_file_system);
      case ExtendedResultCode::read_only_database_rollback:  return static_cast<int>(std::errc::read_only_file_system);
      case ExtendedResultCode::read_only_database_moved:     return static_cast<int>(std::errc::read_only_file_system);
      case ExtendedResultCode::authorization_denied_user:    return static_cast<int>(std::errc::permission_denied);
      default:
         return 0;
   }
}

} // be::sqlite


/* ######################### END OF GENERATED CODE ######################### */

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
S ResultCodeErrorCategory::message(int condition) const {
   S msg;
   const char* cmsg = sqlite3_errstr(condition);
   msg.assign(cmsg ? cmsg : "Internal error");
   msg.reserve(msg.size() + 40);
   msg.append(" (");
   msg.append(extended_result_code_name(static_cast<ExtendedResultCode>(condition)));
   msg.append(1, ')');
   return msg;
}

///////////////////////////////////////////////////////////////////////////////
bool ResultCodeErrorCategory::equivalent(int code, const std::error_condition& condition) const noexcept {
   if (condition.category() == std::generic_category() &&
       condition.value() == generic_error_condition(static_cast<ExtendedResultCode>(code))) {
      return true;
   }

   if (condition.category() == result_code_error_category() &&
       condition.value() == (code & 0xFF)) {
      return true;
   }

   return false;
}

///////////////////////////////////////////////////////////////////////////////
const std::error_category& result_code_error_category() {
   static ResultCodeErrorCategory instance;
   return instance;
}

///////////////////////////////////////////////////////////////////////////////
std::error_code make_error_code(ResultCode e) {
   return std::error_code(static_cast<int>(e), result_code_error_category());
}

///////////////////////////////////////////////////////////////////////////////
std::error_condition make_error_condition(ResultCode e) {
   return std::error_condition(static_cast<int>(e), result_code_error_category());
}

///////////////////////////////////////////////////////////////////////////////
std::error_code make_error_code(ExtendedResultCode e) {
   return std::error_code(static_cast<int>(e), result_code_error_category());
}

///////////////////////////////////////////////////////////////////////////////
std::error_condition make_error_condition(ExtendedResultCode e) {
   return std::error_condition(static_cast<int>(e), result_code_error_category());
}

///////////////////////////////////////////////////////////////////////////////
ExtendedResultCode ext_result_code(int result) {
   return static_cast<ExtendedResultCode>(result);
}

} // be::sqlite
