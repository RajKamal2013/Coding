# Create an interface library for headers
add_library(project_headers INTERFACE)

# Set include directories for the interface library
target_include_directories(project_headers
        INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# If you want to install the headers
install(
        DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h"
)
# To use this interface library in other targets, simply link against it:
# Example:
# add_executable(your_executable main.cpp)
# target_link_libraries(your_executable PRIVATE project_headers)
