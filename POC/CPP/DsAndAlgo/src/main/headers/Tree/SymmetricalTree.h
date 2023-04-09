/* 
 * A Binary tree is symmetrical if left and right subtree are mirror 
 * images of each other. 
 */

#pragma once
#include "BinaryTree.h"
#include <iostream>

using namespace std;

bool symmetricalTree_int(BinaryTree *t1, BinaryTree *t2) {
  if ((t1 == nullptr) && (t2 == nullptr)) {
    return true;
  }
  if (((t1 == nullptr) && (t2 != nullptr)) ||
      ((t1 != nullptr) && (t2 == nullptr))) {
    return false;
  }
  
  if (t1->value != t2->value) {
    return false;
  }
  bool left = symmetricalTree_int(t1->left, t2->right);
  bool right = symmetricalTree_int(t1->right, t2->left);
  return left && right;
}
bool symmetricalTree(BinaryTree* tree) {
  if (tree == nullptr) {
    return true;
  }
  return symmetricalTree_int(tree->left, tree->right);
}

/* Command 
 * clang++ -g -std=c++11 src/Tree/BinaryTree.cpp src/Tree/SymmetricalTreeTest.cpp -o bin/testTree && ./bin/testTree
 */