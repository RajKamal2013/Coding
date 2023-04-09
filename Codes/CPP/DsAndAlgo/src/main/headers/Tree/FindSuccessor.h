/* 
 * Find successor 
 *
 * 
 */

#pragma once 
#include "BinaryTree.h"
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;


BinaryTree* findSuccessor_int(BinaryTree *tree, BinaryTree *node) {
  stack<BinaryTree *> stk;
  stk.push(tree);

  BinaryTree *curr = nullptr;
  BinaryTree *prev = nullptr;
  BinaryTree *last = nullptr;
 
  while (!stk.empty()) {
    curr = stk.top();
    if ((curr->left != nullptr) && 
        ((prev == nullptr) || (prev->left == curr) || (prev->right == curr))) {
            stk.push(curr->left);
    } else if (curr->left == nullptr) {
      stk.pop();
      if (last == node) {
        break;
      } else {
        last = curr;
      }
      if (curr->right != nullptr) {
        stk.push(curr->right);
      }
    } else if (curr->left == prev) {
      stk.pop();
      if (last == node) {
        break;
      } else {
        last = curr;
      }
      if (curr->right != nullptr) {
        stk.push(curr->right);
      }
    } else {
      stk.pop();
      if (last == node) {
        break;
      } else {
        last = curr;
      }
      if (curr->right != nullptr) {
        stk.push(curr->right);
      }
    }
    prev = curr;
    curr = nullptr;
  }

  return curr;
}

BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
  
  if ((tree == nullptr) && (node == nullptr)) {
    return nullptr;
  }
  
  if ((tree == nullptr) && (node != nullptr)) {
    return nullptr;
  }

  if ((tree != nullptr) && (node == nullptr)) {
    return nullptr;
  }
  return findSuccessor_int(tree, node);
}