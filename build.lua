module 'sqlite' {
   lib {
      limp { file = 'include/transaction_type.hpp', inputs = { 'meta/transaction_type.lua', 'meta/transaction_type_hpp.blt' } },
      limp { file = 'src/transaction_type.cpp', inputs = { 'meta/transaction_type.lua', 'meta/transaction_type_cpp.blt' } },
      limp { file = 'include/result_type.hpp', inputs = { 'meta/result_type.lua', 'meta/result_type_hpp.blt' } },
      limp { file = 'src/result_type.cpp', inputs = { 'meta/result_type.lua', 'meta/result_type_cpp.blt' } },
      src_no_pch 'src/*.c',
      src 'src/*.cpp',
      pch_src 'src/pch.cpp',
      define 'BE_SQLITE_IMPL'
   },
   app '-test' {
      icon 'icon/bengine-test-perf.ico',
      link_project {
         'testing',
         'core',
         'core-id',
         'sqlite'
      }
   }
}
