cmake_minimum_required(VERSION 3.31)

project (Coding LANGUAGES CXX)

#project(
#  Coding
#  VERSION 1.0
#  DESCRIPTION "Practice "
#  LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_OSX_ARCHITECTURES "arm64")
#set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
#include_directories(/opt/homebrew/include)
#link_directories(/opt/homebrew/lib)


if(CMAKE_COMPILER_IS_GNUCXX)
  add_definitions(-std=gnu++0x)
endif()

# Set compiler and flags
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  # Brew install clang
  #set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/")
  # Default macos Clang
  #set(CMAKE_CXX_COMPILER "/usr/bin/clang++")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()



# Common compiler warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")


# Configuration-specific flags
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

# Enable testing
enable_testing()


# The compiled library code is here#
add_subdirectory(src)
add_subdirectory(include)
add_subdirectory(test)

