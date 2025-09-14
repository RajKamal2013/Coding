package org.patterns;

/*
    * This code is part of the "Two Pointer" pattern.
    * It sorts an array of integers representing colors (0, 1, 2) using a two-pointer technique.
    * The colors are sorted in-place, and the function returns the sorted array.
 */


public class TwoPointer {

    public static int[] sortColors (int[] colors) {

        int firstIdx, secondIdx;
        firstIdx = 0;
        secondIdx = colors.length - 1;

        firstIdx = pivotArray(colors, 0, firstIdx);

        if (firstIdx == colors.length - 1) {
            return colors;
        }

        firstIdx = pivotArray(colors, 1, firstIdx);
        return colors;
    }

    public static int pivotArray(int[] colors, int pivot, int firstIdx) {
        int secondIdx = colors.length - 1;
        while (firstIdx < secondIdx) {
            while  ((firstIdx < colors.length) && (colors[firstIdx] == pivot)) {
                firstIdx = firstIdx + 1;
            }
            while ((secondIdx > 0) && (colors[secondIdx] != pivot)) {
                secondIdx = secondIdx - 1;
            }
            if (firstIdx < secondIdx) {
                swap(colors, firstIdx, secondIdx);
            }
        }

        return firstIdx;
    }

    public static void swap(int[] colors, int idx1, int idx2) {
        int temp = colors[idx1];
        colors[idx1] = colors[idx2];
        colors[idx2] = temp;
    }
}