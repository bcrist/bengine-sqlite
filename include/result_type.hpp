#pragma once
#ifndef BE_SQLITE_RESULT_TYPE_HPP_
#define BE_SQLITE_RESULT_TYPE_HPP_

#include "sqlite_autolink.hpp"

namespace be {
namespace sqlite {

/*!! include('result_type', 'hpp') !! 16 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

///////////////////////////////////////////////////////////////////////////////
enum class ResultType {
   null,
   integer,
   real,
   text,
   blob
};

const char* get_name(ResultType type);
ResultType get_result_type(int type);

/* ######################### END OF GENERATED CODE ######################### */

} // be::sqlite
} // be

#endif
