write_template('result_type_' .. (...), {
   typename = 'ResultType',
   param = 'type',
   constants = {
      { 'null', 'SQLITE_NULL' },
      { 'integer', 'SQLITE_INTEGER' },
      { 'real', 'SQLITE_FLOAT' },
      { 'text', 'SQLITE_TEXT' },
      { 'blob', 'SQLITE_BLOB' },
   }
})
