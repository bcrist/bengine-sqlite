include 'common/enum'

transaction_type = make_enum_class('TransactionType', 'U8', {
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

if file_ext == '.hpp' then
   write_template('common/enum_decl', transaction_type)
   write_template('common/enum_is_valid_decl', transaction_type)
   write_template('common/enum_name_decl', transaction_type)
   write_template('common/enum_scalar_mapping_decl', sql_map)
else
   write_template('common/enum_is_valid', transaction_type)
   write_template('common/enum_name', transaction_type)
   write_template('common/enum_scalar_mapping', sql_map)
end
