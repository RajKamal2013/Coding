/* 
 * Given 2 arrays. 
 * Output -> True if both the array represent same BST ow False
 */

#ifndef SameBSTs_H
#define SameBSTs_H

#include "BST.h"
#include <iostream>
#include <vector>
using namespace std; 


vector<int> getLeftSubArray(const vector<int>& arr) {
    vector<int> smaller = {};
    for (size_t idx = 1; idx < arr.size(); idx++){
        if (arr[idx] < arr[0]) {
            smaller.push_back(arr[idx]);
        }
    }
    return smaller;
}

vector<int> getRightSubArray(const vector<int>& arr) {
    vector<int> larger = {};
    for (size_t idx = 1; idx < arr.size(); idx++) {
          if (arr[idx] >= arr[0]) {
            larger.push_back(arr[idx]);
        }
    }
    return larger;
}

bool sameBsts(const vector<int>& arrayOne, const vector<int>& arrayTwo) {
  
  if (arrayOne.size() != arrayTwo.size()) {
    return false;
  }

  if ((arrayOne.size() == 0) && (arrayTwo.size() == 0)) {
    return true;
  }

  if (arrayOne[0] != arrayTwo[0]) {
    return false;
  }

  vector<int> leftSubArrayOne;
  vector<int> rightSubArrayOne;
  vector<int> leftSubArrayTwo;
  vector<int> rightSubArrayTwo;
  leftSubArrayOne =  getLeftSubArray(arrayOne);
  rightSubArrayOne = getRightSubArray(arrayOne);
  leftSubArrayTwo = getLeftSubArray(arrayTwo);
  rightSubArrayTwo = getRightSubArray(arrayTwo);

  return sameBsts(leftSubArrayOne, leftSubArrayTwo) && sameBsts(rightSubArrayOne, rightSubArrayTwo);
}





#endif


/* 
 * Command 
 * clang++ -std=c++11 src/Tree/BST.cpp src/Tree/SameBSTsTest.cpp -o bin/testTree && ./bin/testTree 
 */