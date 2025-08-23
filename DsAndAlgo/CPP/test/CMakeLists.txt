
# Discover test
include(GoogleTest)


# Download and configure Google Test
#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        GIT_REPOSITORY https://github.com/google/googletest.git
#        GIT_TAG        v1.17.0 # Replace with desired version
#)
#FetchContent_MakeAvailable(googletest)
#include_directories(/opt/homebrew/include/gtest)
#include_directories(
#        /opt/homebrew/include/gtest/
  #      /Library/Developer/CommandLineTools/SDKs/MacOSX15.4.sdk/usr/include/c++/
#)

find_package(GTest REQUIRED)
# Collect all test source files
file(GLOB_RECURSE TEST_SOURCES
        "*.cpp"
        "*.h"
)

# Add this line at the top, before you add test executables
#add_subdirectory(../src/Practice Practice_build)

# Add this before your test executable
# Create test executable
add_executable(unit_tests ${TEST_SOURCES}
        ../src/Patterns/TwoPointer/TwoPointers.h
        Practice/TwoPointerTest.cpp)

target_link_libraries(unit_tests
        PRIVATE
        GTest::GTest
        GTest::Main
        Practice
        Patterns
        Threads::Threads
)
#set_target_properties(unit_tests
#    PROPERTIES
#    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
#)
add_executable(maximum_product_tests
        Practice/MaximumProductTests.cpp
        ../include/practice/ListNode.h
        ../include/practice/TreeUtils.h
)
target_link_libraries(maximum_product_tests
        PRIVATE
        GTest::gtest
        GTest::gtest_main
        Practice
)

target_include_directories(maximum_product_tests
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

add_executable(PrintTreeTests
        Practice/PrintTreeTest.cpp
)

target_link_libraries(PrintTreeTests
        PRIVATE
        GTest::gtest
        GTest::gtest_main
        Practice
)

target_include_directories(PrintTreeTests
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

add_executable(LinkedListInBinaryTreeTests
        Practice/LinkedListInBinaryTreeTest.cpp
)

target_link_libraries(LinkedListInBinaryTreeTests
        PRIVATE
        GTest::gtest
        GTest::gtest_main
        Practice
)

target_include_directories(LinkedListInBinaryTreeTests
        PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)


add_executable(TwoPointerTest Practice/TwoPointerTest.cpp)
target_link_libraries(TwoPointerTest PRIVATE
        GTest::gtest
        GTest::gtest_main
        Patterns)
target_include_directories(TwoPointerTest PRIVATE
        ${CMAKE_SOURCE_DIR}/src
)

# Link libraries
#target_link_libraries(unit_tests
#        PRIVATE
#        project_headers  # Our interface library for headers
#        Practice        # Our main library being tested
#        GTest::gtest_main
#        GTest::gmock_main
#)


# Link libraries
#target_link_libraries(maximum_product_tests
#        PRIVATE
#        project_headers  # Our interface library for headers
#        Practice        # Our main library being tested
#        GTest::gtest_main
#        GTest::gmock_main
#)

#target_link_libraries(maximum_product_tests gtest_main gtest Practice)

# Set include directories
#target_include_directories(unit_tests
#        PRIVATE
#        ${CMAKE_CURRENT_SOURCE_DIR}
#)




# add_test(NAME unit_tests COMMAND unit_tests)
add_test(NAME maximum_product_tests COMMAND maximum_product_tests)

# Optional: Set working directory for test if needed

# Add a custom target for running test
#add_custom_target(run_tests
#        COMMAND ${CMAKE_BINARY_DIR}/bin/unit_tests
#        DEPENDS unit_tests
#)

#gtest_discover_tests(unit_tests)
#add_subdirectory(practice)

