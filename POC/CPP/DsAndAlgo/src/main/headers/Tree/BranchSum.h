/* 
 * Given a Binary Tree, output list consisting of all branch sums.
 * Branchg sum is sum of all the element from root to leaf in the branch
 */


#include<iostream>
#include<vector>
#include "BST.h"
using namespace std; 


void branchSums_int(BST *node, int sum, vector<int> &arr) {
    if ((node->left == nullptr) && (node->right == nullptr)) {
        sum = sum + node->value;
        arr.push_back(sum);
        return;
    }
    sum = sum + node->value;
    if (node->left != nullptr) {
        branchSums_int(node->left, sum, arr);
    }
    if (node->right != nullptr) {
        branchSums_int(node->right, sum, arr);
    }
}
vector<int> branchSums(BST *root) {
  int sum = 0;
  vector<int> arr = {};
  
  if (root == nullptr) {
    return arr;
  }

  branchSums_int(root, sum, arr);
  
  return arr;
}

/* 
 * clang++ -std=c++11 src/Tree/BST.cpp src/Tree/BranchSumTest.cpp -o bin/testTree && ./bin/testTree
 */