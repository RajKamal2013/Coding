#pragma once 

#include "BinaryTree.h"
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


void invertBinaryTree_int(BinaryTree *node) {
   if (node == nullptr) {
        return; 
    }
    if ((node->left == nullptr) && (node->right == nullptr)) {
      return;
    } else if ((node->left != nullptr) && (node->right != nullptr)) {
        BinaryTree *tmp = node->left;
        node->left  = node->right;
        node->right = tmp;
        invertBinaryTree_int(node->left);
        invertBinaryTree_int(node->right);
        return;
    } else if ((node->left != nullptr) && (node->right == nullptr)) {
        node->right = node->left;
        node->left = nullptr;
        invertBinaryTree_int(node->right);
        return;
    } else if ((node->right != nullptr) && (node->left == nullptr)) {
        node->left = node->right;
        node->right = nullptr;
        invertBinaryTree_int(node->left);
        return;
    } else {
        assert(0);
    }
}

void invertBinaryTree(BinaryTree *tree) {
  invertBinaryTree_int(tree);
}
