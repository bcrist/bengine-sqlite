#pragma once
#ifndef BE_SQLITE_VERSION_HPP_
#define BE_SQLITE_VERSION_HPP_

#include <be/core/macros.hpp>

#define BE_SQLITE_VERSION_MAJOR 0
#define BE_SQLITE_VERSION_MINOR 1
#define BE_SQLITE_VERSION_REV 3

/*!! include('common/version', 'be::sqlite') !! 6 */
/* ################# !! GENERATED CODE -- DO NOT MODIFY !! ################# */
#define BE_SQLITE_VERSION (BE_SQLITE_VERSION_MAJOR * 100000 + BE_SQLITE_VERSION_MINOR * 1000 + BE_SQLITE_VERSION_REV)
#define BE_SQLITE_VERSION_STRING "be::sqlite " BE_STRINGIFY(BE_SQLITE_VERSION_MAJOR) "." BE_STRINGIFY(BE_SQLITE_VERSION_MINOR) "." BE_STRINGIFY(BE_SQLITE_VERSION_REV)

/* ######################### END OF GENERATED CODE ######################### */

#endif
