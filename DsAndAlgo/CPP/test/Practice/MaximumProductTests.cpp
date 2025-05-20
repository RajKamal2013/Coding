#include <gtest/gtest.h>
//#include "../../include/practice/MaximumProduct.h"
#include "../../include/practice/MaximumProduct.h"

class MaximumProductTest : public ::testing::Test {
protected:
    // No need for member variables, all methods are static
};

TEST_F(MaximumProductTest, SplitNumberInDigits_SingleDigit) {
    auto result = MaximumProduct::SplitNumberInDigits(5);
    ASSERT_EQ(static_cast<unsigned long>(result.size()), 1);
    ASSERT_EQ(result[0], 5);
}

TEST_F(MaximumProductTest, SplitNumberInDigits_MultipleDigits) {
    auto result = MaximumProduct::SplitNumberInDigits(123);
    ASSERT_EQ(static_cast<unsigned long>(result.size()), 3);
    ASSERT_EQ(result[0], 3);
    ASSERT_EQ(result[1], 2);
    std::cout << "Yes";
    ASSERT_EQ(result[2], 1);
}

TEST_F(MaximumProductTest, SplitNumberInDigits_NegativeNumber) {
    ASSERT_THROW(MaximumProduct::SplitNumberInDigits(-123), std::invalid_argument);
}

TEST_F(MaximumProductTest, RadixSort_Basic) {
    std::vector<int> input = {3, 1, 4, 1, 5, 9};
    auto result = MaximumProduct::RadixSort(input);
    ASSERT_EQ(result, (std::vector<int>{1, 1, 3, 4, 5, 9}));
}

TEST_F(MaximumProductTest, MaxProduct_BasicCases) {
    ASSERT_EQ(MaximumProduct::MaxProduct(123), 6);  // 2 * 3 = 6
    ASSERT_EQ(MaximumProduct::MaxProduct(999), 81); // 9 * 9 = 81
    ASSERT_EQ(MaximumProduct::MaxProduct(5), 0);    // Single digit case
}

TEST_F(MaximumProductTest, MaxProductOptimal_BasicCases) {
    ASSERT_EQ(MaximumProduct::MaxProductOptimal(123), 6);  // 2 * 3 = 6
    ASSERT_EQ(MaximumProduct::MaxProductOptimal(999), 81); // 9 * 9 = 81
    ASSERT_EQ(MaximumProduct::MaxProductOptimal(1234), 12); // 3 * 4 = 12
}

TEST_F(MaximumProductTest, MaxProduct_NegativeNumber) {
    ASSERT_THROW(MaximumProduct::MaxProduct(-123), std::invalid_argument);
}