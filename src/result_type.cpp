#include "pch.hpp"
#include "result_type.hpp"
#include "sqlite.hpp"

namespace be {
namespace sqlite {

/*!! include 'result_type' !! 56 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

///////////////////////////////////////////////////////////////////////////////
bool is_valid(ResultType constant) noexcept {
   switch (constant) {
      case ResultType::null:
      case ResultType::integer:
      case ResultType::real:
      case ResultType::text:
      case ResultType::blob:
         return true;
      default:
         return false;
   }
}

///////////////////////////////////////////////////////////////////////////////
const char* result_type_name(ResultType constant) noexcept {
   switch (constant) {
      case ResultType::null:    return "null";
      case ResultType::integer: return "integer";
      case ResultType::real:    return "real";
      case ResultType::text:    return "text";
      case ResultType::blob:    return "blob";
      default:
         return "?";
   }
}

///////////////////////////////////////////////////////////////////////////////
int sqlite_result_type(ResultType constant) noexcept {
   switch (constant) {
      case ResultType::integer: return int(SQLITE_INTEGER);
      case ResultType::real:    return int(SQLITE_FLOAT);
      case ResultType::text:    return int(SQLITE_TEXT);
      case ResultType::blob:    return int(SQLITE_BLOB);
      default:
         return int(SQLITE_NULL);
   }
}

///////////////////////////////////////////////////////////////////////////////
ResultType result_type(int value) noexcept {
   switch (value) {
      case SQLITE_NULL: return ResultType::null;
      case SQLITE_INTEGER: return ResultType::integer;
      case SQLITE_FLOAT: return ResultType::real;
      case SQLITE_TEXT: return ResultType::text;
      case SQLITE_BLOB: return ResultType::blob;
      default:
         return ResultType::null;
   }
}

/* ######################### END OF GENERATED CODE ######################### */

} // be::sqlite
} // be
