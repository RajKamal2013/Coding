#include "src/dynamic_programming/coins_change.h"

#include <gtest/gtest.h>
#include <vector>
#include <iostream>

//#include <dp/coins_change.h>

TEST(DynamicProgrammingTest, CoinsChangeTest) {
    std::vector<int> denoms = {1, 5};
    int n = 6;
    int expected = 2;
    int computed = numberOfWaysToMakeChange(n, denoms);
    EXPECT_EQ(expected, computed);
}
