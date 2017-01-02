module { name = 'sqlite',
   projects = {
      lib {
         limp = {
            { file = 'include/transaction_type.hpp', inputs = { 'meta/transaction_type.lua', 'meta/transaction_type_hpp.blt' } },
            { file = 'src/transaction_type.cpp', inputs = { 'meta/transaction_type.lua', 'meta/transaction_type_cpp.blt' } },
            { file = 'include/result_type.hpp', inputs = { 'meta/result_type.lua', 'meta/result_type_hpp.blt' } },
            { file = 'src/result_type.cpp', inputs = { 'meta/result_type.lua', 'meta/result_type_cpp.blt' } }
         },
         src = {
            'src/*.cpp',
            pch = 'src/pch.cpp',
            nopch = 'src/*.c'
         },
         preprocessor = {
            'BE_SQLITE_IMPL'
         }
      },
      app { suffix = 'test',
         icon = 'icon/bengine-test-perf.ico',
         src = {
            'test/*.cpp'
         },
         libs = {
            'testing',
            'core',
            'core-id',
            'sqlite'
         }
      }
   }
}
