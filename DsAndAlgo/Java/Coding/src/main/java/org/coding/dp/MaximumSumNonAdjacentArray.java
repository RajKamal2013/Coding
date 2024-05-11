package org.coding.dp;

/*
 * Given an array and find the maximum non-adjacent sum of array elements
 * Example: Array: [75, 105, 120, 75, 90, 135]
 *  Answer: 330 -> [105, 75, 135]
 *
 */

/**
 * Class contains static method that find the maximum non-adjacent sum
 * in an array.
 */
public class MaximumSumNonAdjacentArray {
    public static int solution(int[] array) {
        if (array.length == 0) {
            return 0;
        }
        if (array.length == 1) {
            return array[0];
        }
        int[] incl = new int[array.length];
        int[] excl = new int[array.length];

        incl[0] = array[0];
        excl[0] = 0;

        for (int i = 1; i < array.length; i++) {
            incl[i] = array[i] + excl[i - 1];
            excl[i] = Integer.max(excl[i-1], incl[i-1]);
        }
        return Integer.max(excl[array.length-1], incl[array.length -1]);
    }
}
