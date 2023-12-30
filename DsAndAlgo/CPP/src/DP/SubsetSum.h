/*
Given a set of positive numbers arr and a value total, determine if there exists a subset in the 
given set whose sum is equal to total. A subset can be an empty set, or it can either consist of 
some elements of the set or all the elements of the set.
Example: 
    set = {1, 2, 3, 7}
    total = 6
    Answer = True  -> {1, 2, 3}
Constraints:
    1 <= arr.length <= 1000
    0 <= total <= 25 * 10000
    1 <= arr[i] <= 10000
Sample: 
    {1, 2, 3, 7}, 6 => True {1, 2, 3}
    {3, 4, 5, 2}, 9 => True {4, 5} or {3, 4, 2}
    {3, 5, 9}, 2 => False
-------
Solution 
dp = array of 

{1} {2} {3} {7}   -> size of arr 
{1, 2} {1, 3} {1, 7} {2, 3} {2, 7} {3, 7} -> 
{1, 2, 3} {1, 2, 7} {1, 3, 7} {2, 3, 7}  -> 
{1, 2, 3, 7}  -> 
Array : arr
Total : T
--> N -> length of array 
dp[N][] -> variable dp array. 

dp[N+1][T+1]
dp[m][n] => m -> size of set n -> sum => if the of set consisting of m elements from the array contribute
to the sum of n 
dp[0][0...total] -> T, F, ...F
dp[1][0...total]  -> Either of (dp[0][i] + arr[i], dp[0][i] - arr[i]) is equal to i -> T or F 

including i -> dp[i-1][j  - arr[i - 1]] 
excluding i -> dp[i-1][j]

*/

//#pragma once 
#include <vector>

// Botton Up Approach 
bool SubsetSum(std::vector<int>& arr, int total) { 
    int N = arr.size(); 
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(total + 1, false));
    
    dp[0][0] = true;
    // Empty set cannot lead to any sum greater than 0
    for (int idx = 1; idx <= total; idx++) {
        dp[0][idx] = false;
    }
    // Each set has empty set. 
    for (int idx = 1; idx <= N; idx++) {
        dp[idx][0] = true;
    }

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= total; col++) {
            if (col < arr[row - 1]) {
                dp[row][col] = dp[row-1][col];
            } else {
                // if including element is 0 ie arr[row] == col, then we can including the number
                // makes the sum. 
                dp[row][col] = dp[row - 1][col - arr[row - 1]] || dp[row-1][col];
            }
        }
    }
    return dp[N][total];
}

bool SubsetSumInt(std::vector<int> &arr, int n, int total, std::vector<std::vector<int>> &dp) {
    if (total == 0) {
        return true;
    }
    
    if (n == 0) {
        return true;
    }

    if (dp[n][total] != -1) {
        return dp[n][total];
    }

    if (arr[n -1] > total) {
        dp[n][total] = SubsetSumInt(arr, n - 1, total, dp);
    } else {
        dp[n][total] = SubsetSumInt(arr, n - 1, total - arr[n-1], dp) || SubsetSumInt(arr, n - 1, total, dp);
    }
    return dp[n][total];
}

// Top To Bottom Approach 
bool SubsetSumRec(std::vector<int> &arr, int total) {
    int N = arr.size();
    std::vector<std::vector<int>> dp(N + 1, std::vector<int>(total + 1, -1));
    return SubsetSumInt(arr, N, total, dp);
}