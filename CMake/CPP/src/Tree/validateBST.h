/* 
 * Validate BST 
*/

#ifndef validateBST_H
#define validateBST_H
#include "debug.h"
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

void test_validateBST() {
    BST *root = new BST(10);
    vector<int> list = {5, 3, 8, 12, 11, 15, 13, 14, 22, 25};
    for (auto &data:list) {
        //cout << "Entering data: " << data << endl;
        root->insert(data);
    }
    cout << "Inorder" << endl;
    root->inorder();
    bool ret = validateBst(root);
    cout << "Validate BST:" << ret << endl;

    root->left->value = 20;
    cout << "Inorder" << endl;
    root->inorder();
    ret = validateBst(root);
    cout << "Validate BST:" << ret << endl;


}

#endif