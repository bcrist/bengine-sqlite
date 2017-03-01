#include "pch.hpp"
#include "transaction_type.hpp"

namespace be {
namespace sqlite {

/*!! include('transaction_type', 'cpp') !! 24 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

///////////////////////////////////////////////////////////////////////////////
const char* get_name(TransactionType type) {
   switch (type) {
      case TransactionType::deferred: return "deferred";
      case TransactionType::immediate: return "immediate";
      case TransactionType::exclusive: return "exclusive";
      default: return "?";
   }
}

///////////////////////////////////////////////////////////////////////////////
const char* get_create_transaction_sql(TransactionType type) {
   switch (type) {
      case TransactionType::deferred: return "BEGIN DEFERRED";
      case TransactionType::immediate: return "BEGIN IMMEDIATE";
      case TransactionType::exclusive: return "BEGIN EXCLUSIVE";
      default: return "BEGIN";
   }
}

/* ######################### END OF GENERATED CODE ######################### */

} // be::sqlite
} // be
