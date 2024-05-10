package org.coding.dp;

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
