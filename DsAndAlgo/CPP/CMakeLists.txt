cmake_minimum_required(VERSION 3.15)

# Add these lines
if(APPLE)
  execute_process(
          COMMAND xcrun --show-sdk-path
          OUTPUT_VARIABLE CMAKE_OSX_SYSROOT
          OUTPUT_STRIP_TRAILING_WHITESPACE
  )
endif()


project(Coding)

#project(Coding
#        VERSION 1.0
#        LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


if(CMAKE_COMPILER_IS_GNUCXX)
  add_definitions(-std=gnu++0x)
endif()

# Build type configuration
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

# Compiler warnings
if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


#SET (CMAKE_CXX_COMPILER             "/usr/local/opt/llvm/bin/clang++")
SET (CMAKE_CXX_FLAGS                "-Wall")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
set (CMAKE_CXX_STANDARD 11)
#set(CMAKE_TOOLCHAIN_FILE /Users/rk015348/vcpkg/scripts/buildsystems/vcpkg.cmake)
#"-DCMAKE_TOOLCHAIN_FILE=/Users/rk015348/vcpkg/scripts/buildsystems/vcpkg.cmake"


#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        GIT_REPOSITORY https://github.com/google/googletest.git
#        GIT_TAG release-1.12.1
#)

# For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)

# Create the interface library for headers
add_library(project_headers INTERFACE)

# Set include directories for the interface library
target_include_directories(project_headers
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include  # Main include directory
        ${CMAKE_CURRENT_SOURCE_DIR}/src      # Source directory for internal headers
)


# The compiled library code is here#
add_subdirectory(src)
add_subdirectory(test)
#add_subdirectory(include)


# Install headers
install(DIRECTORY include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h"
)