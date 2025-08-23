//
// Created by raj on 19/8/25.
//
#include <gtest/gtest.h>
#include "../../src/Patterns/TwoPointer/TwoPointers.h"

TEST(TwoPointersTest, HandlesEmptyVector) {
    std::vector<int> input = {};
    std::vector<int> expected = {};
    EXPECT_EQ(TwoPointers::SortColors(input), expected);
}

TEST(TwoPointersTest, HandlesAllZeros) {
    std::vector<int> input = {0, 0, 0};
    std::vector<int> expected = {0, 0, 0};
    EXPECT_EQ(TwoPointers::SortColors(input), expected);
}

TEST(TwoPointersTest, HandlesAllOnes) {
    std::vector<int> input = {1, 1, 1};
    std::vector<int> expected = {1, 1, 1};
    EXPECT_EQ(TwoPointers::SortColors(input), expected);
}

TEST(TwoPointersTest, HandlesAllTwos) {
    std::vector<int> input = {2, 2, 2};
    std::vector<int> expected = {2, 2, 2};
    EXPECT_EQ(TwoPointers::SortColors(input), expected);
}

TEST(TwoPointersTest, HandlesSortedInput) {
    std::vector<int> input = {0, 0, 1, 1, 2, 2};
    std::vector<int> expected = {0, 0, 1, 1, 2, 2};
    EXPECT_EQ(TwoPointers::SortColors(input), expected);
}

TEST(TwoPointersTest, HandlesReverseSortedInput) {
    std::vector<int> input = {2, 2, 1, 1, 0, 0};
    std::vector<int> expected = {0, 0, 1, 1, 2, 2};
    EXPECT_EQ(TwoPointers::SortColors(input), expected);
}

TEST(TwoPointersTest, HandlesRandomInput) {
    std::vector<int> input = {2, 0, 2, 1, 1, 0};
    std::vector<int> expected = {0, 0, 1, 1, 2, 2};
    EXPECT_EQ(TwoPointers::SortColors(input), expected);
}

TEST(TwoPointersTest, HandlesSingleElement) {
    std::vector<int> input = {1};
    std::vector<int> expected = {1};
    EXPECT_EQ(TwoPointers::SortColors(input), expected);
}