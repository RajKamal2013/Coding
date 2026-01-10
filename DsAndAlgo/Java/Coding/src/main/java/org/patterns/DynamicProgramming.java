package org.patterns;

public class DynamicProgramming {

    public static int countPalindromicSubstrings(String s) {
        if (s== null || s.isEmpty()) { return 0; }
        if (s.length() == 1) { return 1;}
        if (s.length() == 2) {
            if (s.charAt(0) == s.charAt(1)) { return 3; }
            else { return 2; }
        }

        int count = 0;
        int strLen = s.length();
        boolean[][] dp = new boolean[strLen][strLen];

        for (int i = 0; i < strLen; i++) {
            dp[i][i] = true;
            count = count + 1;
        }

        for (int i = 0; i < strLen - 1; i++) {
            dp[i][i+1] = s.charAt(i) == s.charAt(i + 1);
            count = count + (dp[i][i+1] ? 1: 0);
        }

        for (int len = 3; len <= strLen; len++) {
            for (int i = 0, j = len - 1; j < strLen; i++, j++) {
                dp[i][j] = (s.charAt(i) == s.charAt(j)) && dp[i+1][j-1];
                count = count + (dp[i][j] ? 1: 0);
            }
        }
        return count;
    }

    public static int coinChange(int [] coins, int total) {

       if (total == 0) { return 0; }
       if (coins.length == 0) { return -1; }

       int[] dp = new int[total + 1];

       dp[0] = 0;

       int min, count;

       for (int i = 1; i <= total; i++) {
           min = count = Integer.MAX_VALUE;
           for (int j = 0; j < coins.length; j++) {
               if ((i - coins[j] >= 0) && (dp[i-coins[j]] != -1)) {
                   count = dp[i - coins[j]] + 1;
                   if (min > count) min = count;
               }
           }
           if (min == Integer.MAX_VALUE) dp[i] = -1;
           else dp[i] = min;
       }

        return  dp[total];
    }

    public static boolean canPartitionArray(int[] arr) {
        if (arr == null || arr.length == 0 || arr.length == 1) { return false; }

        int arrSum = 0;
        for (int num: arr) {
            arrSum = arrSum + num;
        }

        if (arrSum % 2 != 0) return false;

        int targetSum = arrSum/2;

        boolean[][] dp = new boolean[arr.length + 1][targetSum + 1];

        for (int i = 0; i <= arr.length; i++) {
            dp[i][0] = true;
        }

        for (int idx = 1; idx <= arr.length; idx++) {
            for (int sum = 1; sum <= targetSum; sum++) {

                dp[idx][sum] = dp[idx - 1][sum];
                if (sum >= arr[idx - 1]) {
                    dp[idx][sum] = dp[idx][sum] || dp[idx -1][sum-arr[idx-1]];
                }
            }
        }
        return dp[arr.length][targetSum];
    }

    public static boolean canPartitionArray1D(int[] arr) {
        if (arr == null || arr.length == 0 || arr.length == 1) { return false; }

        int arrSum = 0;
        for (int num: arr) {
            arrSum = arrSum + num;
        }

        if (arrSum % 2 != 0) return false;

        int targetSum = arrSum/2;

        boolean[] dp = new boolean[targetSum + 1];
        dp[0] = true;

        for (int num: arr) {
            for (int sum = targetSum; sum >= num; sum--) {
                dp[sum] = dp[sum] || dp[sum-num];
            }
        }
        return dp[targetSum];
    }


}
