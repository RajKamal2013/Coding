package org.coding.dp;

import java.util.Arrays;
import java.util.logging.Logger;

/**
 * Minimum Coin Change: Given an array of coins and a target, find minimum of coins
 * required to reach the target. Each coin has unlimited supply.
 * Example: denons: [1, 5, 10], target: 7
 *  Solution -> 3 (2 * 1, 1 *5) -> 2 coins of 1 and 1 coin of 5
 */

public class MinCoinChange {
    Logger logger = Logger.getLogger(MinCoinChange.class.getName());
    public static int solution(int n, int[] denoms) {

        int minCount = solutionDPBottomsUp(n, denoms);
        System.out.println("(DP Top Down) Minimum number of coins required to complete target: " +
            n + " using denoms: " + Arrays.toString(denoms) + " is: " + minCount);
        minCount = solutionDPTopDown(n, denoms);
        System.out.println("(DP Bottoms Up) Minimum number of coins required to complete target: " +
                n + " using denoms: " + Arrays.toString(denoms) + " is: " + minCount);
        return minCount;
    }

    public static int solutionDPBottomsUpInt(int n, int[] denoms, int idx,
                                             int[][]dp) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return Integer.MAX_VALUE;
        }

        if (dp[n][idx] != -1) {
            return dp[n][idx];
        }

        int including = Integer.MAX_VALUE;
        int excluding = Integer.MAX_VALUE;

        if (n - denoms[idx] >= 0) {
            including = solutionDPBottomsUpInt(n - denoms[idx], denoms, idx, dp);
        }
        if (including != Integer.MAX_VALUE) {
            including = including + 1;
        }

        if ((idx + 1) <= denoms.length - 1) {
            excluding = solutionDPBottomsUpInt(n, denoms, idx + 1, dp);
        }
        dp[n][idx] = Integer.min(excluding, including);

        return dp[n][idx];

    }
    public static int solutionDPBottomsUp(int n, int[] denoms) {
        if (n == 0) {
            return 0;
        }

        if (denoms.length == 0) {
            return -1;
        }

        int[][] dp = new int[n + 1][denoms.length];
        for (int i = 1; i <= n ; i++) {
            Arrays.fill(dp[i], -1);
        }

        int idx = 0;
        int count = solutionDPBottomsUpInt(n, denoms, idx, dp);
        for (int i = 0; i <= n; i++) {
            System.out.println(Arrays.toString(dp[i]));
        }
        return count;
    }

    public static int solutionDPTopDown(int n, int[] denoms) {
        if (n == 0) {
            return 0;
        }

        if (denoms.length == 0) {
            return -1;
        }

        int[][] dp = new int[n + 1][denoms.length];
        for (int i = 0; i < denoms.length; i++) {
            if (denoms[i] <= n) {
                dp[denoms[i]][i] = 1;
            }
        }
        int including, excluding;
        for (int i = 1; i <= n; i++) {
            including = excluding = Integer.MAX_VALUE;
            for (int j = 0; j < denoms.length; j++) {
                if (i - denoms[j] >= 0) {
                    including = dp[i - denoms[j]][j];
                }
                if (j - 1 >= 0) {
                    excluding = dp[i][j-1];
                }
                dp[i][j] = Integer.min(including, excluding);
            }
        }
        return dp[n][denoms.length -1];
    }
}
