/*
 Suppose you are given an array, nums, containing positive numbers. You need to partition the array 
 into two arrays such that the absolute difference between their sums is minimized.
 Example: 
    Array: [2, 3, 1]
        -> [2, 1]  -> Sum = 3
        -> [3]     -> Sum = 3 
        Absolute Diff => 0 
    Answer -> [2, 1], [3]

    [5, 4, 4, 7, 2, 9 ] -> [5, 4, 7], [4, 9, 2]
    [3, 25, 4, 12, 2]   -> [25], [3, 4, 12, 2]
    [3, 7, 4, 12, 2]    -> [12, 2], [3, 7, 4]
    ---------------
    Create all subsets and check the feasibility 

    Total Sum -> Column size 
    rows = arr.size()
    cols = (Array Sum / 2) + 1
    dp[m][n] -> Using m elements, can sum of n be achieved. 
    dp[rows][cols] --> all -1 in the beginning  
    dp[0][0..cols] --> (arr[0] == cols) -> 1 
    dp[rows][0]    --> Getting sum 0 is possible if no element are selected -> 1 

    dp[m][n] -> Using m elements, can sum of n be achieved. 
    including -> dp[m][n] -> dp[m-1][n]
    excluding -> dp[m][n] -> dp[m-1][n - arr[m]]

    if (dp[m-1][n]) {
        dp[m][n] = dp[m-1][n]
    } else if (n >= nums[i]) {
        dp[m][n] = dp[m-1][n-nums[i]]
    } else {
        dp[m][n] = 0
    }

    Starting value -> -1 
    If sum can be achieved,  -> 1 
    If sum can't be achieved -> 0

    

*/
