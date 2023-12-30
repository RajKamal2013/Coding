/* 
 Given a set of positive numbers nums and a value target_sum, count the total number of subsets of the 
 given set whose sum is equal to the target_sum.

 Example: 
    Numbers: {1, 2, 3, 4}
    Target Sum: 4 
    Answer: 2 
        {1, 3}, {4}
    
    1 <= array size <= 1000
    0 <= target sum <= 25 0000
    1 <= array[i] <= 10000

    Test 
    {1, 2, 7, 4, 5} , 9 ->  2 
    {1, 2, 3, 7}, 6     ->  1

    Input 
        Array of numbers -> arr 
        TargetSum -> T 
    Ouput
        Number of subsets whose sum is T 
    
    Approach:
        rows = 0 to (arr.size() + 1)
        cols = 0 to (targetSum + 1)
        dp[0][0...cols] = 0
        dp[cols][0] = 1
        dp[rows][colums] 
            
        for (i = 1; i <= rows; i++) {
            for (j = 1; j <= cols; j++) {
                    sumExclude =  dp[i-1][j]
                    sumInclude = 0
                    if (j > arr[i-1]) {
                        sumInclude =  dp[i-1][j-arr[i-1]]
                    }
                    dp[i][j] = sumInclude + sumExclude;
                }
            }
        }
 */
//#pragma once 

#include <vector>

long CountSubsetSum(std::vector<int> nums, int target_sum) {
    int n = nums.size();
    std::vector<std::vector<int>>dp(n, std::vector<int>(target_sum + 1, 0));
    if (nums[0] == 0) {
        dp[0][0] = 2;
    } else {
        dp[0][0] = 1;
    }

    return -1;
}