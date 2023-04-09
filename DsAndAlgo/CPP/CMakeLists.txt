cmake_minimum_required(VERSION 3.15)

project (Coding LANGUAGES CXX)

project(
  Coding
  VERSION 0.1
  DESCRIPTION "An example project with CMake"
  LANGUAGES CXX)

if(CMAKE_COMPILER_IS_GNUCXX)
  add_definitions(-std=gnu++0x)
endif()

SET (CMAKE_CXX_COMPILER             "/usr/local/opt/llvm/bin/clang++")
SET (CMAKE_CXX_FLAGS                "-Wall")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
set (CMAKE_CXX_STANDARD 11)

  # The compiled library code is here#
add_subdirectory(src)


