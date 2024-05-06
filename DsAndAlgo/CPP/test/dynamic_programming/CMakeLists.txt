enable_testing()
include_directories(${Coding_SOURCE_DIR})
include(GoogleTest)

add_executable(CoinChangeTest
        coins_change_test.cc
    )
gtest_discover_tests(CoinChangeTest)

target_link_libraries(
  CoinChangeTest 
  PRIVATE dp_library
  GTest::gtest_main
)
