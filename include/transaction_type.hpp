#pragma once
#ifndef BE_SQLITE_TRANSACTION_TYPE_HPP_
#define BE_SQLITE_TRANSACTION_TYPE_HPP_

#include "sqlite_autolink.hpp"
#include <be/core/be.hpp>

namespace be {
namespace sqlite {

/*!! include 'transaction_type' !! 14 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

///////////////////////////////////////////////////////////////////////////////
enum class TransactionType : U8 {
   deferred = 0,
   immediate,
   exclusive
};

bool is_valid(TransactionType constant) noexcept;
const char* transaction_type_name(TransactionType constant) noexcept;
const char* create_transaction_sql(TransactionType constant) noexcept;
/* ######################### END OF GENERATED CODE ######################### */

} // be::sqlite
} // be

#endif
