package org.coding.dp;

import java.util.Arrays;

/*
 * Given the number and coin denominations, find the number of ways to
 * achieve n. Given there are unlimited number of coin denominations.
 * Number: n
 * Denominators: denoms
 * Example
 *  n: 6
 *  denoms:  {1, 5}
 *  output : 2
 *      {1, 1, 1, 1, 1, 1} and {1, 5}
 */
public class CoinsChange {
    public int numberOfWaysToMakeChange(int n, int[] denoms) {
        /* Base cases */
        if (denoms.length == 0) {
            return -1;
        }
        if (n == 0) {
            return 1;
        }

        if (n < 0) {
            return 0;
        }

        Arrays.sort(denoms);
        int numberOfWays = 0;
        // Naive Recursive Way

        /*
        numberOfWays =  numberOfWaysToMakeChangeNaive(n, denoms);
        System.out.println("Recursive: Number of ways to Make change: " + numberOfWays);

        // DP: Top-Down Approach (Memorisation)
        numberOfWays = numberOfWaysToMakeChangeDpTopDown(n, denoms);
        System.out.println("DP (Top-Down): Number of ways to Make change: " + numberOfWays);

        // DP: Bottoms-Up Approach (Tabulation)
        numberOfWays = numberOfWaysToMakeChangeBottomsUp(n, denoms);
        System.out.println("DP (Bottoms-Up): Number of ways to Make change: " + numberOfWays);
        */
         numberOfWays = numberOfWaysToMakeChangeNaive2(n, denoms);
        return numberOfWays;
    }

    /* Naive Way of making change. Its recursive way */
    public int numberOfWaysToMakeChangeNaive(int n, int[] denoms) {
        int numberOfWays = 0;
        numberOfWays =  numberOfWaysToMakeChangeNaiveInt(n, denoms, denoms[denoms.length - 1]);
        return numberOfWays;
    }

    public int numberOfWaysToMakeChangeNaive2(int n, int[] denoms) {
        int numberOfWays = 0;
        numberOfWays =  numberOfWaysToMakeChangeNaiveInt2(n, denoms, 0);
        return numberOfWays;
    }

    public int numberOfWaysToMakeChangeNaiveInt2(int n, int[] denoms, int idx) {
        if (n == 0) {
            return 1;
        }
        if (idx >= denoms.length) {
            return 0;
        }
        int incl = 0, excl = 0;
        if ( n >= denoms[idx]) {
            incl = numberOfWaysToMakeChangeNaiveInt2(n - denoms[idx], denoms, idx);
        }
        excl = numberOfWaysToMakeChangeNaiveInt2(n, denoms, idx + 1);
        return incl + excl;
    }

    /* Build on the naive way, DP top- down approach */
    public int numberOfWaysToMakeChangeDpTopDown(int n, int[] denoms) {
        int[][] dp = new int[denoms.length][n + 1];
        for (int i = 0;i < denoms.length; i++) {
            for (int j = 0; j <=n; j++) {
                dp[i][j]= -1;
            }
        }

        int idx = denoms.length - 1;
        int maximum = denoms[idx];
        dp[idx][n] = numberOfWaysToMakeChangeTopDownInt(n, denoms, idx, maximum, dp);
        return dp[idx][n];
    }

    public int numberOfWaysToMakeChangeBottomsUp(int n, int[] denoms) {
        int [][] dp = new int[n + 1][denoms.length];
        for (int i = 0; i < denoms.length; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = 0;
            }
        }

        for (int i = 0; i < denoms.length; i++) {
            dp[0][i] = 1;
        }

        int incl, excl = 0;
        for (int i = 1; i <= n ; i++) {
            for (int j = 0; j < denoms.length; j++) {
                incl = excl = 0;
                if (i >= denoms[j]) {
                    incl = dp[i - denoms[j]][j];
                }
                if (j - 1 >=0) {
                    excl = dp[i][j-1];
                }
                dp[i][j] = incl + excl;
            }
        }

        return dp[n][denoms.length -1];
    }
    

    /**
     * Recurssive or naive way to solve the problem
     * @param n
     * @param denoms
     * @return
     */
    public int numberOfWaysToMakeChangeNaiveInt(int n, int[] denoms, int maximum) {

        if (n < 0) {
            return 0;
        }

        if (n == 0) {
            return 1;
        }

        int numberOfWays = 0;
        for (int i = 0; i < denoms.length; i++) {
            if ((denoms[i] <= maximum) && ((n - denoms[i]) >=0)) {
                numberOfWays = numberOfWays + numberOfWaysToMakeChangeNaiveInt(n - denoms[i], denoms, denoms[i]);
            }
        }
        return numberOfWays;
    }

    public int numberOfWaysToMakeChangeTopDownInt(int n, int[] denoms, int idx, int maximum, int[][]dp) {
        if (n < 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }

        if (dp[idx][n] != -1) {
            return dp[idx][n];
        }
        int numberOfways = 0;
        for (int i = 0; i < denoms.length; i++) {
            if (denoms[i] <= maximum) {
                numberOfways = numberOfways +
                        numberOfWaysToMakeChangeTopDownInt(n - denoms[i], denoms, i, denoms[i], dp );
           }
        }

        dp[idx][n] = numberOfways;
        return dp[idx][n];
    }
}
