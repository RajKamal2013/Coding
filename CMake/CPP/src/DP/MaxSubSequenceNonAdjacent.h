/* 
 * Given a array, find maxsub sequence sum 
 * 75, 105, 120, 75, 90, 135 
 * Ans: 75 + 120 + 135 --> 330
 */

#pragma once

#include <iostream>
#include <vector>

using namespace std; 

int maxSubsetSumNoAdjacent(vector<int> array) {
  bool debug = false;
  if (array.size() == 0) {
    return 0;
  }

  if (array.size() == 1) {
    return array[0];
  }

  if (array.size() == 2) {
    return max(array[0], array[1]);
  } 

  if (array.size() == 3) {
    return max (array[0] + array[2], array[1]);
  }

  vector<int> sumArray(array.size(), 0);
 
  sumArray[0] = array[0];
  sumArray[1] = max(array[0], array[1]);
  sumArray[2] = max (array[0] + array[2], array[1]);

  for (int i = 3; i < sumArray.size(); i++) {
    sumArray[i] = max((sumArray[i-2] + array[i]),
                       sumArray[i-1]);
  }

  if (debug) {
    for (auto data: sumArray) {
        cout << data << " ";
    }
    cout << endl;
  }



  return sumArray[sumArray.size() - 1];
}

