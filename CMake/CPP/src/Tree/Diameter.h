/* 
 * Diamter of binary Tree: Length of longest path from one node to another. 
 * Find Diamter of the binary tree. 
 */

#pragma once
#include "BinaryTree.h"
#include <iostream>
using namespace std;

int height(BinaryTree *node, int &diameter) {
    if (node == nullptr) {
        return 0;
    }
    int lheight = 0;
    int rheight = 0;
    lheight = height(node->left, diameter);
    rheight = height(node->right, diameter);
    int height = lheight + rheight;
    if (height > diameter) {
        diameter = height;
    }
    return (lheight > rheight) ? (lheight + 1):(rheight + 1);
}

int binaryTreeDiameter(BinaryTree *tree) {
    if (tree == nullptr) {
        return -1;
    }
    int diameter = -1;
    (void)height(tree, diameter);
    return diameter;
}