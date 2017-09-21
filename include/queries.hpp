#pragma once
#ifndef BE_SQLITE_QUERIES_HPP_
#define BE_SQLITE_QUERIES_HPP_

#include "sqlite_autolink.hpp"
#include <be/core/be.hpp>

namespace be::sqlite {

class Db;

void vacuum(Db& db);
void analyze(Db& db);

void exec(Db& db, const S& sql);
void exec(Db& db, const char* sql);

} // be::sqlite

#endif
