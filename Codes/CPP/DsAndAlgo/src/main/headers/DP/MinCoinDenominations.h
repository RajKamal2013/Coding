/* 
 * Given array of denominations and target. Find minimum number of coins 
 *  using that target can be made using denominations. 
 * denoms = {1, 5, 10} Target: 7
 * Ans: 3 (1*5) , (2 * 1)
 */
#pragma once 
#include <iostream>
#include <vector>
using namespace std; 


int minNumberofCoinsForChange_int(int n, vector<int> denoms) {
  vector<int> coins(n+1, INT_MAX);
    sort(denoms.begin(), denoms.end());
    coins[0] = 0;
    int a = 0;
    for (auto denom:denoms) {
        for (int i = 1; i <= n; i++) {
            if (i >= denom) {
              if (coins[i - denom] == INT_MAX){
                a = coins[i - denom];
              } else {
                a = coins[i - denom] + 1;
              }
              coins[i] = min(coins[i], a);
            }
        }
    }
    if (coins[n] == INT_MAX) {
        return -1;
    } else {
        return coins[n];
    }
}
int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  if (n == 0) {
    return 0;
  }
  if (denoms.size() == 0) {
    return 0;
  }

  return minNumberofCoinsForChange_int(n, denoms);
}
