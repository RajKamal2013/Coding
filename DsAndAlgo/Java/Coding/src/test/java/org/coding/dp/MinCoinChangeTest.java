package org.coding.dp;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;


public class MinCoinChangeTest {

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
    @DisplayName("Minimum Coin change")
    public  void testMinimumCoinChange() {
        int[] denoms = {1, 5, 10};
        int n = 7;
        int expected, computed;

        displayBefore(n, denoms);
        computed = MinCoinChange.solution(n, denoms);
        expected = 3;
        displayAfter(expected, computed);
        assertEquals(expected, computed);
    }
}
