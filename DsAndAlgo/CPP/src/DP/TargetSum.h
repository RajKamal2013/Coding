/*
Given an array of positive integers arr and a target T, build an expression using these numbers by 
inserting a + or a − before each integer, and evaluating this expression. Find the total number of 
different expressions that evaluate to T.
Constraints:
    1 <= arr.length <= 40
    0 <= arr[i] <= 1000
    0 <= sum(arr[i])  <= 1000
    −1000 <= T <=  1000

Example: [1, 1] -> 
    Sum -> -1 - 1   => 2
    Sum -> -1 + 1   => 0
    Sum -> +1 - 1   => 0
    Sum -> +1 + 1   => 2
    
    Target Sum -> 0 
    Answer: 2  (2 expressions )
        -1 + 1. 1 -1 

Solution:
    0 element 
    1 element
    2 element 
    3 element
    4 element 
    Previous element -> Add (-1 * arr[i])
                     -> Add (arr[i])
    ----------------
    a b c
    ----------------
    a              a            -a
    a b            a + b        a - b          -a + b          -a -b
    a b c          a + b + c    a + b - c       a - b + a       a -b -a  
                  -a + b + c   - a + b -c      -a - b + c      -a - b - c
    ----------------
    totalExpression = 0;
    vector<<vector<int>> dp;
    vector<int> row = {arr[0], -arr[1]}
   
    for (int idx = 1; idx <= arr.size(); idx++) {
        row.clear();
        row = new vector<int>(dp[idx-1].size() * 2);
        for (num: dp[idx-1]){
            val = arr[idx] + num;
            row.push_back(val);
        
            val = (-1 * arr[idx]) + num;
           
            row.push_back(val);
        }
    }
    for (int data: dp[arr.size()-1]) {
        if (data == targetSum) {
            totalExpression = totalExpression + 1;
        }
    }
    return totalExpression


*/
//#pragma once 
#include <vector>

void displayDp(std::vector<std::vector<int>> dp) {
    for (std::vector<int> row:dp) {
        std::cout << " Size: " << row.size() << "-> [ ";
        for (int num: row) {
            std::cout << num <<  " ";
        }
        std::cout << "] \n";
    }
}
int FindTargetSumWays(std::vector<int> &arr, int T) {
    if (arr.size() == 0) {
        return -1;
    }
    int totalExpressionCount = 0;
    int currVal;
    std::vector<std::vector<int>> dp;
    std::vector<int> row;
    row.push_back(arr[0]);
    row.push_back(-1 * arr[0]);
    dp.push_back(row);

    for (int idx = 1; idx < arr.size(); idx++) {
        row.clear();
        for (int prevSum: dp[idx-1]){
            currVal = arr[idx] + prevSum;
            row.push_back(currVal);
            currVal = (-1 * arr[idx]) + prevSum;
            row.push_back(currVal);
        }
        dp.push_back(row);
    }
    for (int val: dp[arr.size()-1]) {
        if (val == T) {
            totalExpressionCount = totalExpressionCount +  1;
        }
    }
    return totalExpressionCount;
}



