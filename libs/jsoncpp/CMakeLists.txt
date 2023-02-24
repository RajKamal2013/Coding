cmake_minimum_required(VERSION 3.15)
project (Coding LANGUAGES CXX)

project(
  JsonCPP
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

find_package(jsoncpp REQUIRED)
message("FOUND CONFIG: ${jsoncpp_CONFIG}")
message("INCLUDE DIRS: ${jsoncpp_INCLUDE_DIRS}")
message("LIBRARIES: ${jsoncpp_LIBRARIES}")
include_directories("${JSONCPP_INCLUDE_DIRS}")
link_libraries(${JSONCPP_LIBRARIES})

#target_link_libraries(${PROJECT_NAME} ${JSONCPP_LIBRARIES})
#target_compile_options(parse PRIVATE -Wall -Werror)

  # The compiled library code is here
add_subdirectory(src)

#get_target_property(JSON_INC_PATH jsoncpp_lib INTERFACE_INCLUDE_DIRECTORIES)
#include_directories(${JSON_INC_PATH})

#target_link_libraries(${PROJECT_NAME} jsoncpp_lib)