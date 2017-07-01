include 'common/enum'
include 'common/load_tsv'

local data = load_tsv(resolve_include_path('result_code.tsv'))
local ext_data = load_tsv(resolve_include_path('extended_result_code.tsv'))

result_code = make_enum_class('be::sqlite::ResultCode', 'U8', data)
ext_result_code = make_enum_class('be::sqlite::ExtendedResultCode', 'U16', ext_data)

local errc_map = {
   name = 'generic_error_condition',
   enum = ext_result_code,
   type = 'int',
   no_cast = true,
   mapper = function (constant)
      if constant.errc and #constant.errc > 0 then
         return 'static_cast<int>(std::errc::' .. constant.errc .. ')'
      else
         return '0'
      end
   end,
   default = '0'
}

include('common/enum_std_begin', result_code)
include('common/enum_std_end', result_code)

include('common/enum_std_begin', ext_result_code)
if file_ext == '.hpp' then
   write_template('common/templates/enum_scalar_mapping_decl', errc_map)
else
   write_template('common/templates/enum_scalar_mapping', errc_map)
end
include('common/enum_std_end', ext_result_code)
