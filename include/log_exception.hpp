#pragma once
#ifndef BE_SQLITE_LOG_ERROR_HPP_
#define BE_SQLITE_LOG_ERROR_HPP_

#include "sql_error.hpp"
#include <be/core/log.hpp>

namespace be::sqlite {

void log_exception(const SqlTrace& e, Log& log, v::Verbosity verbosity = v::error, const char* source = nullptr);
void log_exception(const SqlError& e, Log& log, v::Verbosity verbosity = v::error, const char* source = nullptr);

} // be::sqlite

#endif
