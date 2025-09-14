//
// Created by rk015348 on 13/09/25.
//


#include <gtest/gtest.h>
#include "../../src/Patterns/SlidingWindow.h"

TEST(SlidingWindowTest, HandleTest) {
    std::string str = "abcabcbb";
    int expected = 3;
    EXPECT_EQ(SlidingWindow::FindLongestSubstring(str), expected);
}