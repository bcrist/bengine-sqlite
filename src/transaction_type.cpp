#include "pch.hpp"
#include "transaction_type.hpp"

/*!! include 'transaction_type' !! 58 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

namespace be::sqlite {

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
std::array<const TransactionType, 3> transaction_type_values() noexcept {
   return ::be::EnumTraits<TransactionType>::values<>();
}

///////////////////////////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, TransactionType constant) {
   if (is_valid(constant)) {
      os << transaction_type_name(constant);
   } else {
      os << static_cast<I64>(static_cast<U8>(constant));
   }
   return os;
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

} // be::sqlite


/* ######################### END OF GENERATED CODE ######################### */
