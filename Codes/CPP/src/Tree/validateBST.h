/* 
 * Validate BST 
*/

#ifndef ValidateBST_H
#define ValidateBST_H

#include "BST.h"
#include <vector>
#include <iostream>
using namespace std;


bool validateBst_int(BST *node, int min, int max) {
    bool ret, lRet, rRet;
    
    if ((node->value < min) || (node->value >= max)) {
        return false;
    }
    
    if (node->left != nullptr) {
        lRet = validateBst_int(node->left, min, node->value);
    } else {
        lRet = true;
    }
    if (node->right != nullptr) {
        rRet = validateBst_int(node->right, node->value, max);
    } else {
        rRet = true;
    }
    if (node->left != nullptr) {
        if (node->left->value < node->value) {
            ret = true;
        } else {
            ret = false;
        }
    } else {
        ret = true;
    }
    if (node->right != nullptr) {
        if (node->value <= node->right->value) {
            ret = ret && true;
        } else {
            ret = false;
        }
    } else {
        ret = ret && true;
    }



    return (lRet && rRet && ret);
}

bool validateBst(BST *tree) {
  if (tree == nullptr) {
    return true;
  }
  // only one node
  if ((tree->left == nullptr) && (tree->right == nullptr)) {
    return true;
  }

  return validateBst_int(tree, INT_MIN, INT_MAX);
}



#endif