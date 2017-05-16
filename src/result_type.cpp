#include "pch.hpp"
#include "result_type.hpp"
#include "sqlite.hpp"

/*!! include 'result_type' !! 76 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

namespace be::sqlite {

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
std::array<const ResultType, 5> result_type_values() noexcept {
   return ::be::EnumTraits<ResultType>::values<>();
}

///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, ResultType constant) {
   if (is_valid(constant)) {
      os << result_type_name(constant);
   } else {
      os << static_cast<I64>(static_cast<U8>(constant));
   }
   return os;
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

} // be::sqlite


/* ######################### END OF GENERATED CODE ######################### */
