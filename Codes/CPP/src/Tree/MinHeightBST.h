/* 
 * Link: https://www.algoexpert.io/questions/min-height-bst
 * Given a sorted array of integer, create a min height BST. 
 * Input: 1, 2, 5, 7, 10, 13, 14, 15, 22 
 * Output: 
 *             10 
 *          /       \
 *         /         \ 
 *        5           15 
 *      /  \       /      \
 *     2     5    13       22
 *    /             \     /  \
 *  1                14  20  25
 *  There can be multiple BST possible but height will  remain constant in every case. 
 *  
 */
#ifndef MinHeightBST_H
#define MinHeightBST_H

#include <iostream>
#include <vector>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }

  int height_int(BST *node) {
    int rtHeight, ltHeight;
    if (node == nullptr){
        return 0;
    }
    rtHeight = height_int(node->right);
    ltHeight = height_int(node->left);
    return (ltHeight >= rtHeight) ? (ltHeight + 1) : (rtHeight + 1);
  }

  int height() {
    return height_int(this);
  }

  void inorder_int(BST *node, ostream &out) {
    if (node != nullptr) {
        inorder_int(node->left, out);
        out << node->value << " ";
        inorder_int(node->right, out);
    }
  }
  void inorder(ostream &out = cout) {
    inorder_int(this, out);
    out << endl;
  }
};

BST *minHeightBst_int(vector<int> array, int startIdx, int endIdx) {
    if (startIdx > endIdx) {
        return nullptr;
    }
    int mid = (startIdx + endIdx )/2;
    BST *node = new BST(array[mid]);
    node->left = minHeightBst_int(array, startIdx, mid - 1);
    node->right = minHeightBst_int(array, mid + 1, endIdx);
    return node;
}

BST *minHeightBst(vector<int> array) {
  if (array.size() == 0) {
    return nullptr;
  }
  BST *root = nullptr;
  if (array.size() == 1) {
    root = new BST(array[0]);
    return root;
  }

  int startIdx = 0;
  int endIdx = array.size() - 1;
  root = minHeightBst_int(array, startIdx, endIdx);
  return root;
}

#endif
