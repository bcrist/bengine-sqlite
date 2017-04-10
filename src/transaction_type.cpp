#include "pch.hpp"
#include "transaction_type.hpp"

namespace be {
namespace sqlite {

/*!! include 'transaction_type' !! 38 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

///////////////////////////////////////////////////////////////////////////////
bool is_valid(TransactionType constant) noexcept {
   switch (constant) {
      case TransactionType::deferred:
      case TransactionType::immediate:
      case TransactionType::exclusive:
         return true;
      default:
         return false;
   }
}

///////////////////////////////////////////////////////////////////////////////
const char* transaction_type_name(TransactionType constant) noexcept {
   switch (constant) {
      case TransactionType::deferred:  return "deferred";
      case TransactionType::immediate: return "immediate";
      case TransactionType::exclusive: return "exclusive";
      default:
         return "?";
   }
}

///////////////////////////////////////////////////////////////////////////////
const char* create_transaction_sql(TransactionType constant) noexcept {
   switch (constant) {
      case TransactionType::deferred:  return "BEGIN DEFERRED";
      case TransactionType::immediate: return "BEGIN IMMEDIATE";
      case TransactionType::exclusive: return "BEGIN EXCLUSIVE";
      default:
         return "BEGIN";
   }
}

/* ######################### END OF GENERATED CODE ######################### */

} // be::sqlite
} // be
