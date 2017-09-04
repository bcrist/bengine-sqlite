#include "pch.hpp"
#include "log_exception.hpp"
#include "result_code.hpp"
#include <be/core/logging.hpp>

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
void log_exception(const SqlTrace& e, v::Verbosity verbosity, Log& log, const char* source) {
   be_log(verbosity, source) << S(e.what())
      & attr(ids::log_attr_category) << e.code().category().name()
      & attr(ids::log_attr_error) << ext_result_code(e.code().value())
      & attr(ids::log_attr_error_code) << e.code().value()
      & attr(ids::log_attr_description) << e.code().message()
      & attr(ids::log_attr_query) << S(e.sql())
      & attr(ids::log_attr_trace) << StackTrace(e.trace())
      | log;
}

///////////////////////////////////////////////////////////////////////////////
void log_exception(const SqlError& e, v::Verbosity verbosity, Log& log, const char* source) {
   be_log(verbosity, source) << S(e.what())
      & attr(ids::log_attr_category) << e.code().category().name()
      & attr(ids::log_attr_error) << ext_result_code(e.code().value())
      & attr(ids::log_attr_error_code) << e.code().value()
      & attr(ids::log_attr_description) << e.code().message()
      & attr(ids::log_attr_query) << S(e.sql())
      | log;
}

} // be::sqlite
