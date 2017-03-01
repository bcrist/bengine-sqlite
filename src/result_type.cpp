#include "pch.hpp"
#include "result_type.hpp"
#include "sqlite.hpp"

namespace be {
namespace sqlite {

/*!! include('result_type', 'cpp') !! 28 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

///////////////////////////////////////////////////////////////////////////////
const char* get_name(ResultType type) {
   switch (type) {
      case ResultType::null: return "null";
      case ResultType::integer: return "integer";
      case ResultType::real: return "real";
      case ResultType::text: return "text";
      case ResultType::blob: return "blob";
      default: return "?";
   }
}

///////////////////////////////////////////////////////////////////////////////
ResultType get_result_type(int type) {
   switch (type) {
      case SQLITE_NULL: return ResultType::null;
      case SQLITE_INTEGER: return ResultType::integer;
      case SQLITE_FLOAT: return ResultType::real;
      case SQLITE_TEXT: return ResultType::text;
      case SQLITE_BLOB: return ResultType::blob;
      default: return ResultType::null;
   }
}

/* ######################### END OF GENERATED CODE ######################### */

} // be::sqlite
} // be
