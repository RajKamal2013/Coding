#pragma once 

#include <vector>

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

int numberOfWaysToMakeChange(int n, std::vector<int> denoms);
/* Number of ways to make coin change: Naive way */
int numberOfWaysToMakeChangeNaive(int n, std::vector<int> denoms);
int numberOfWaysToMakeChangeNaiveInt(int n, std::vector<int> denoms, int maximum);
/* Number of ways to make coin change: DP-> Top Down Approach */
int numberOfWaysToMakeChangeTopDown(int n, std::vector<int> denoms);
int numberOfWaysToMakeChangeTopDownInt(int n, std::vector<int> denoms, 
    int maximum, std::vector<std::vector<int>> dp);
/* Number of ways to make coin change: DP-> Bottoms Up Approach */
int numberOfWaysToMakeChangeBottomsUp(int n, std::vector<int> denoms);




