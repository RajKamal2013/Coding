# Google Test setup

# Enable testing
enable_testing()

# Download and configure Google Test
#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        GIT_REPOSITORY https://github.com/google/googletest.git
#        GIT_TAG        v1.17.0 # Replace with desired version
#)
#FetchContent_MakeAvailable(googletest)

find_package(GTest REQUIRED)
# Collect all test source files
file(GLOB_RECURSE TEST_SOURCES
        "*.cpp"
        "*.h"
)

# Create test executable
add_executable(unit_tests ${TEST_SOURCES})
add_executable(maximum_product_tests
        practice/MaximumProductTests.cpp
)
add_dependencies(unit_tests Practice)

# Link libraries
target_link_directories(unit_tests PRIVATE ${CMAKE_BINARY_DIR})
target_link_libraries(unit_tests
        PRIVATE
        #project_headers  # Our interface library for headers
        Practice        # Our main library being tested
        GTest::gtest_main
        GTest::gmock_main
)


# Link libraries
target_link_libraries(maximum_product_tests
        PRIVATE
        project_headers  # Our interface library for headers
        Practice        # Our main library being tested
        GTest::gtest_main
        GTest::gmock_main
)


#target_link_libraries(maximum_product_tests gtest_main gtest Practice)

# Set include directories
target_include_directories(unit_tests
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Practice
)

target_include_directories(maximum_product_tests
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)


# Discover tests
include(GoogleTest)
gtest_discover_tests(unit_tests)
gtest_discover_tests(maximum_product_tests)


# Optional: Set working directory for tests if needed
set_target_properties(unit_tests
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Add a custom target for running tests
add_custom_target(run_tests
        COMMAND ${CMAKE_BINARY_DIR}/bin/unit_tests
        DEPENDS unit_tests
)

#add_subdirectory(practice)