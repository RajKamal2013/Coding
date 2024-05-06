package org.coding.dp;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class CoinsChangeTest {

    void displayBefore(int n, int[] denoms) {
        System.out.println("---------------------------------");
        System.out.print("[");
        for (int data: denoms) {
            System.out.print(data + ", ");
        }
        System.out.println("]");
        System.out.println("Target Number: " + n);
    }

    void displayAfter(int expectedResult, int result) {
        System.out.println("Expected: " +  expectedResult);
        System.out.println("Result: " + result);
        System.out.println("---------------------------------");
    }

    @Test
    @DisplayName("Testing naive way for Coin Chang problem")
    void testNumberOfWaysToMakeChange() {
        CoinsChange coinsChange = new CoinsChange();
        int denoms[] = {1, 5};
        int n = 6;
        int result, expectedResult;
        /*------------- Test Case --------------------- */
        displayBefore(n, denoms);
        result = coinsChange.numberOfWaysToMakeChange(n, denoms);
        expectedResult = 2;
        displayAfter(expectedResult, result);
        assertEquals(expectedResult, result);

        /*------------- Test Case --------------------- */
        denoms = new int[]{2, 3, 5};
        n = 12;
        displayBefore(n, denoms);
        result = coinsChange.numberOfWaysToMakeChange(n, denoms);
        expectedResult = 5;
        displayAfter(expectedResult, result);
        assertEquals(expectedResult, result);

    }
}
