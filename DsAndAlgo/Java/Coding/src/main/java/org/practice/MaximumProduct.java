package org.practice;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Given an integer, return the maximum product of any two digits in n.
 * example:
 *  31 -> 3
 *  124 -> 8 Max(1*2, 1*4, 2*4)
 */

public class MaximumProduct {

    /**
     * Split the number into digits and return the list of the digit.
     * Time Complexity => O(n)
     * Space Complexity => O(n)
     * @param n, number
     * @return List<Integer>, List containing digits
     * @throws IllegalArgumentException
     */
    List<Integer> splitNumberInDigits(int n) throws IllegalArgumentException {
        if (n < 0) {
            throw new IllegalArgumentException(String.format("Number %d is negative", n));
        }
        List<Integer> digits = new ArrayList<>();
        if (n < 10) {
            digits.add(n);
            return digits;
        }
        while (n > 0) {
            digits.add(n % 10);
            n /= 10;
        }
        //Collections.reverse(digits);
        return digits;
    }

    /**
     * Implementation of Radix Sort
     * Time Complexity -> O(n)
     * Space Complexity -> O(n)
     * @param digits, List of digits
     * @return List<Integer>,  List of sorted digits
     */
    private List<Integer> radixSort(List<Integer> digits) {
        Integer[] arr = new Integer[10];
        Arrays.fill(arr, 0);
        Integer[] aux = new Integer[digits.size()];
        for (Integer integer : digits) {
            arr[integer]++;
        }

        for (int i = 1; i < arr.length; i++) {
            arr[i] = arr[i] + arr[i - 1];
        }

        for (int i = digits.size() - 1; i >= 0; i--) {
            int digit = digits.get(i);
            aux[arr[digit] -1] = digit;
            arr[digit]--;
        }

        for (int i = 0; i < digits.size(); i++) {
            digits.set(i, aux[i]);
        }
        return digits;
    }

    /**
     * Method calculate maximum product of two digits from the number.
     * Time -> O(n) + O(n) + O(1) => O(n)
     * Space -> O(n)
     * @param n, number
     * @return integer, maximum product
     * @throws IllegalArgumentException
     */
    int maxProduct(int n) throws IllegalArgumentException {
        try {
            List<Integer> digits = splitNumberInDigits(n);
            if (digits.size() < 2) {
                return 0;
            }
            digits = radixSort(digits);
            return (digits.get(digits.size() - 1) * digits.get(digits.size() - 2));
        } catch (IllegalArgumentException e) {
            //e.printStackTrace();
            throw e;
        }
    }

    /** Optimal solution */
    int maxProduct2(int n) {
        int d1 = 0, d2 = 0, max = 0;
        d1 = n % 10;
        n =  n/10;
        d2 = n % 10;
        n = n/10;
        int temp;
        while(n > 0) {
            temp = n %10;
            if ((temp > d1) && (d1 < d2)) {
                d1 = temp;
                n = n/10;
                continue;
            }

            if (temp > d2) {
                d2 = temp;
            }
            n = n/10;
        }
        return d1 * d2;
    }
}
