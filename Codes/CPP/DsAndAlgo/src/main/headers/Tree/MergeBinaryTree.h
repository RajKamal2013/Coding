/* 
 * Given 2 binary Tree, Merge the binary tree
 */

#include "BinaryTree.h"
#include <iostream>
#include <vector>

using namespace std;


BinaryTree* mergeBinaryTrees_int(BinaryTree *tree1, BinaryTree *tree2) {
  if ((tree1 == nullptr) && (tree2 == nullptr)) {
    return nullptr;
  }

  if (tree1 == nullptr) {
    return tree2;
  }

  if (tree2 == nullptr) {
    return tree1;
  }

  BinaryTree *newNode = new BinaryTree(tree1->value + tree2->value);
  newNode->left = mergeBinaryTrees_int(tree1->left, tree2->left);
  newNode->right = mergeBinaryTrees_int(tree1->right, tree2->right);

  return newNode;
}


BinaryTree* mergeBinaryTrees(BinaryTree* tree1, BinaryTree* tree2) { 
  return mergeBinaryTrees_int(tree1, tree2);
}