module 'sqlite' {
   lib {
      src 'src/*.c',
      src {
         'src/*.cpp',
         pch_src 'src/pch.cpp'
      },
      define 'BE_SQLITE_IMPL',
      link_project 'core'
   },
   app '-test' {
      icon 'icon/bengine-test-perf.ico',
      link_project {
         'testing',
         'sqlite'
      }
   }
}
