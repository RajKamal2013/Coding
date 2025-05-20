cmake_minimum_required(VERSION 3.31)
#project (Practice1 LANGUAGES CXX)
# Create an interface library for headers
#add_library(project_headers INTERFACE
#        practice/MaximumProduct.h)

# Set include directories for the interface library
#target_include_directories(project_headers
#        INTERFACE
#        ${CMAKE_SOURCE_DIR}/include
#)

# If you want to install the headers
#install(
#        DIRECTORY ${CMAKE_SOURCE_DIR}/include/
#        DESTINATION include
#        FILES_MATCHING PATTERN "*.h"
#)
# To use this interface library in other targets, simply link against it:
# Example:
# add_executable(your_executable main.cpp)
# target_link_libraries(your_executable PRIVATE project_headers)
