include 'common/enum'
include 'common/load_tsv'

local data = load_tsv(resolve_include_path('result_type.tsv'))
result_type = make_enum_class('be::sqlite::ResultType', 'U8', data)

local sqlite_map = { name = 'sqlite_result_type', enum = result_type, type = 'int', mapper = 'sqlite_symbol', default = 'SQLITE_NULL' }
local sqlite_rev_map = { name = 'result_type', enum = result_type, type = 'int', mapper = 'sqlite_symbol', default = 'ResultType::null' }

include('common/enum_std_begin', result_type)

if file_ext == '.hpp' then
   write_template('common/templates/enum_scalar_mapping_decl', sqlite_map)
   write_template('common/templates/scalar_enum_mapping_decl', sqlite_rev_map)
else
   write_template('common/templates/enum_scalar_mapping', sqlite_map)
   write_template('common/templates/scalar_enum_mapping', sqlite_rev_map)
end

include('common/enum_std_end', result_type)
