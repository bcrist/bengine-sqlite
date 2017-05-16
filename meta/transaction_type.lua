include 'common/enum'

transaction_type = make_enum_class('be::sqlite::TransactionType', 'U8', {
   'deferred', 'immediate', 'exclusive'
})

local sql_map = {
   name = 'create_transaction_sql',
   enum = transaction_type,
   type = 'const char*',
   no_cast = true,
   mapper = function (constant)
      return '"BEGIN ' .. constant.name:upper() .. '"'
   end,
   default = '"BEGIN"'
}

include('common/enum_std_begin', transaction_type)

if file_ext == '.hpp' then
   write_template('common/templates/enum_scalar_mapping_decl', sql_map)
else
   write_template('common/templates/enum_scalar_mapping', sql_map)
end

include('common/enum_std_end', transaction_type)
