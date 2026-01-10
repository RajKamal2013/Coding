package org.patterns;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.patterns.DynamicProgramming.coinChange;
import static org.patterns.DynamicProgramming.countPalindromicSubstrings;

public class DynamicProgrammingTest {

    @Test
    @DisplayName("Test countPalindromicSubstrings")
    public void testCountPalindromicSubstrings() {
        String str = "abab";
        int computedCount = countPalindromicSubstrings(str);
        int expectedCount = 6;
        Assertions.assertEquals(expectedCount, computedCount);


    }

    @Test
    @DisplayName("Test Coin Change")
    public void testCoinChange() {
        int[] coins = {1, 3, 4, 5};
        int total = 7;

        int expectedCount = 2;
        int computedCount = coinChange(coins, total);

        Assertions.assertEquals(expectedCount, computedCount);

        coins = new int[]{5};
        total = 4;
        expectedCount = -1;
        computedCount = coinChange(coins, total);

    }
}
