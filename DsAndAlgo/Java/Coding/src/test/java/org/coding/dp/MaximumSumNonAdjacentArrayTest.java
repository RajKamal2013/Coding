package org.coding.dp;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

public class MaximumSumNonAdjacentArrayTest {
    void displayBefore(int[] array) {
        System.out.println("---------------------------------");
        System.out.print("[");
        for (int data: array) {
            System.out.print(data + ", ");
        }
        System.out.println("]");
    }

    void displayAfter(int expectedResult, int result) {
        System.out.println("Expected: " +  expectedResult);
        System.out.println("Result: " + result);
        System.out.println("---------------------------------");
    }

    @Test
    @DisplayName("Testing maximum sum non adjacent in Array")
    void testMaximumSubArrayNonAdjacentArray() {
        int[] array = {75, 105, 120, 75, 90, 135};
        displayBefore(array);
        int expected = 330;
        int computed = MaximumSumNonAdjacentArray.solution(array);
        displayAfter(expected, computed);
    }
}
