#pragma once
#ifndef BE_SQLITE_TRANSACTION_TYPE_HPP_
#define BE_SQLITE_TRANSACTION_TYPE_HPP_

#include "sqlite_autolink.hpp"

namespace be {
namespace sqlite {

/*!! include('transaction_type', 'hpp') !! 14 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

///////////////////////////////////////////////////////////////////////////////
enum class TransactionType {
   deferred,
   immediate,
   exclusive
};

const char* get_name(TransactionType type);
const char* get_create_transaction_sql(TransactionType type);

/* ######################### END OF GENERATED CODE ######################### */

} // be::sqlite
} // be

#endif
