package org.DsAndAlgo.DP;

import java.util.Arrays;

public class Knapsack {

    public int Findknapsack(int capacity, int[] weights, int[] values, int n) {
        int[][] dp = new int[n + 1][capacity + 1];

        for (int[] row: dp) {
            Arrays.fill(row, 0);
        }

        for (int idx = 0; idx < dp.length; ++idx) {
            for (int weight = 0; weight < dp[0].length; ++weight) {
                if ((idx == 0) || (weight == 0)) {
                    dp[idx][weight] = 0;
                } else if (weights[idx - 1]  <= weight) {
                    dp[idx][weight] = Math.max(values[idx-1] + dp[idx - 1][weight - weights[idx -1]],
                            dp[idx-1][weight]);
                } else {
                    dp[idx][weight] = dp[idx-1][weight];
                }
            }
        }
        return dp[n][capacity];
    }

    public  void display(int capacity, int[] weights, int[] values, int n, int maxValue, int expectedValue) {
        System.out.println("------------------------------------------------------------------------------------------");
        System.out.println("                                   Input                                                  ");
        System.out.println("------------------------------------------------------------------------------------------");
        System.out.println("capacity = " + capacity + ", weights = " + Arrays.toString(weights) + ", values = " + Arrays.toString(values) + ", n = " + n );
        System.out.println("------------------------------------------------------------------------------------------");
        System.out.println("                                   Output                                                  ");
        System.out.println("------------------------------------------------------------------------------------------");
        System.out.println(" maxValue = " + maxValue + ", expectedValue = " + expectedValue);
        System.out.println("------------------------------------------------------------------------------------------");
    }
    public void testKnapsack() {
        int[] weights = {1, 2, 3, 5};
        int[] values = {1, 5, 4, 8};
        int capacity = 6;
        int n  = 4;
        int maxValues;
        int expectedValue;

        maxValues = Findknapsack(capacity, weights, values, n);
        System.out.println("Maximum Value: " + maxValues);
        expectedValue = 10;
        display(capacity, weights, values, n, maxValues, expectedValue);
    }

}
