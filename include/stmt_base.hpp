#pragma once
#ifndef BE_SQLITE_STMT_BASE_HPP_
#define BE_SQLITE_STMT_BASE_HPP_

#include "result_type.hpp"
#include "sqlite_fwd.hpp"
#include <be/core/id.hpp>
#include <be/core/buf.hpp>

namespace be::sqlite {

///////////////////////////////////////////////////////////////////////////////
class StmtBase {
public:
   explicit operator bool() const;
   sqlite3* raw_owner();
   sqlite3_stmt* raw();
   Id id() const;
   const char* sql() const;

   int parameters();
   int parameter(const char* name);

   void bind();
   void bind(int parameter);
   void bind(int parameter, bool value);
   void bind(int parameter, I32 value);
   void bind(int parameter, U32 value);
   void bind(int parameter, I64 value);
   void bind(int parameter, U64 value);
   void bind(int parameter, F32 value);
   void bind(int parameter, F64 value);
   void bind(int parameter, const char* value);
   void bind_static(int parameter, const char* value);
   void bind(int parameter, SV value);
   void bind_static(int parameter, SV value);
   void bind(int parameter, const void* value, std::size_t length);
   void bind_static(int parameter, const void* value, std::size_t length);

   template <typename T>
   void bind(int parameter, Buf<T> data) {
      bind(parameter, data.get(), data.size() * sizeof(T));
   }

   template <typename T>
   void bind_static(int parameter, Buf<T> data) {
      bind_static(parameter, data.get(), data.size() * sizeof(T));
   }

   bool step();
   void reset();

   int columns();
   int column(const char* name);

   ResultType get_type(int column);

   bool get_bool(int column);
   I32 get_i32(int column);
   U32 get_u32(int column);
   I64 get_i64(int column);
   U64 get_u64(int column);
   F32 get_f32(int column);
   F64 get_f64(int column);
   SV get_text(int column);
   const void* get_blob(int column, std::size_t& length);

   template <typename T>
   Buf<const T> get_blob(int column) {
      std::size_t len;
      const void* ptr = get_blob(column, len);
      return Buf<T>(static_cast<const T*>(ptr), len / sizeof(T));
   }

protected:
   StmtBase();
   StmtBase(const StmtBase& other) = default;
   StmtBase(StmtBase&& other) = default;
   StmtBase& operator=(const StmtBase& other) = default;
   StmtBase& operator=(StmtBase&& other) = default;
   ~StmtBase() = default;

   sqlite3* con_;
   sqlite3_stmt* stmt_;
   Id id_;
};

} // be::sqlite

#endif
