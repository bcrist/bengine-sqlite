#pragma once
#ifndef BE_SQLITE_TRANSACTION_TYPE_HPP_
#define BE_SQLITE_TRANSACTION_TYPE_HPP_

#include "sqlite_autolink.hpp"
#include <be/core/enum_traits.hpp>

/*!! include 'transaction_type' !! 51 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
enum class TransactionType : U8 {
   deferred = 0,
   immediate,
   exclusive
};

bool is_valid(TransactionType constant) noexcept;
const char* transaction_type_name(TransactionType constant) noexcept;
std::array<const TransactionType, 3> transaction_type_values() noexcept;
std::ostream& operator<<(std::ostream& os, TransactionType constant);
const char* create_transaction_sql(TransactionType constant) noexcept;

} // be::sqlite

namespace be {

///////////////////////////////////////////////////////////////////////////////
template <>
struct EnumTraits<::be::sqlite::TransactionType> {
   using type = ::be::sqlite::TransactionType;
   using underlying_type = typename std::underlying_type<type>::type;

   static constexpr std::size_t count = 3;

   static bool is_valid(type value) {
      return ::be::sqlite::is_valid(value);
   }

   static const char* name(type value) {
      return ::be::sqlite::transaction_type_name(value);
   }

   template <typename C = std::array<const type, count>>
   static C values() {
      return {
         ::be::sqlite::TransactionType::deferred,
         ::be::sqlite::TransactionType::immediate,
         ::be::sqlite::TransactionType::exclusive,
      };
   }
};

} // be

/* ######################### END OF GENERATED CODE ######################### */

#endif
