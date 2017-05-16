#pragma once
#ifndef BE_SQLITE_RESULT_TYPE_HPP_
#define BE_SQLITE_RESULT_TYPE_HPP_

#include "sqlite_autolink.hpp"
#include <be/core/enum_traits.hpp>

/*!! include 'result_type' !! 56 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */

namespace be::sqlite {

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
std::array<const ResultType, 5> result_type_values() noexcept;
std::ostream& operator<<(std::ostream& os, ResultType constant);
int sqlite_result_type(ResultType constant) noexcept;
ResultType result_type(int value) noexcept;

} // be::sqlite

namespace be {

///////////////////////////////////////////////////////////////////////////////
template <>
struct EnumTraits<::be::sqlite::ResultType> {
   using type = ::be::sqlite::ResultType;
   using underlying_type = typename std::underlying_type<type>::type;

   static constexpr std::size_t count = 5;

   static bool is_valid(type value) {
      return ::be::sqlite::is_valid(value);
   }

   static const char* name(type value) {
      return ::be::sqlite::result_type_name(value);
   }

   template <typename C = std::array<const type, count>>
   static C values() {
      return {
         ::be::sqlite::ResultType::null,
         ::be::sqlite::ResultType::integer,
         ::be::sqlite::ResultType::real,
         ::be::sqlite::ResultType::text,
         ::be::sqlite::ResultType::blob,
      };
   }
};

} // be

/* ######################### END OF GENERATED CODE ######################### */

#endif
