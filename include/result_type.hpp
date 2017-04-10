#pragma once
#ifndef BE_SQLITE_RESULT_TYPE_HPP_
#define BE_SQLITE_RESULT_TYPE_HPP_

#include "sqlite_autolink.hpp"
#include <be/core/be.hpp>

namespace be {
namespace sqlite {

/*!! include 'result_type' !! 17 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

///////////////////////////////////////////////////////////////////////////////
enum class ResultType : U8 {
   null = 0,
   integer,
   real,
   text,
   blob
};

bool is_valid(ResultType constant) noexcept;
const char* result_type_name(ResultType constant) noexcept;
int sqlite_result_type(ResultType constant) noexcept;
ResultType result_type(int value) noexcept;
/* ######################### END OF GENERATED CODE ######################### */

} // be::sqlite
} // be

#endif
