
/* 
 * Given array of denominations and target. Find number of ways target can be 
 * made using denominations. 
 * denoms = {1, 5} Target: 6
 * Ans: 2 (1*6) and (1*1 + 5 * 1)
 */
#pragma once 

#include <iostream>
#include <vector>

using namespace std;

int numberOfWaysToMakeChange_int(int n, vector<int> denoms) {
    vector<int> coins(denoms.size() + 1, 0);
    coins[0] = 1;

    for (auto denom: denoms) {
        for (int i = 1; i <= n; i++) {
            if (i >= denom)
            coins[i] = coins[i] + coins[i - denom];
        }
    }
    return coins[n];

} 

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  if (denoms.size() == 0) {
    return -1;
  }

  if (n <= 0) {
    return -1;
  }

  return numberOfWaysToMakeChange_int(n, denoms);

}

/* 
 * Command 
 *  clang++ -g -std=c++11 src/DP/CoinDenominationsTest.cpp  -o bin/testDP && ./bin/testDP
 */