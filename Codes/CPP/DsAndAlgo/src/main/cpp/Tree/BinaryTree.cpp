
#include <iostream>
#include <vector>
#include <queue>
#include "Tree/BinaryTree.h"
using namespace std;


BinaryTree:: BinaryTree(int val) {
    this->value = val;
    this->left = nullptr;
    this->right = nullptr;
}

BinaryTree& BinaryTree :: insertBST(int val) {
    BinaryTree *newNode = new BinaryTree(val);
    BinaryTree *node = nullptr;
    node = this;

    while (node != nullptr) {
        if (node->value > val) {
            if (node->left == nullptr) {
                node->left = newNode;
                break;
            } else {
                node = node->left;
            }
        } else if (node->value <= val) {
            if (node->right == nullptr ) {
                node->right = newNode;
                break;
            } else {
                node = node->right;
            }
        }
    }
    return *this;
}

BinaryTree &BinaryTree :: insert_int(BinaryTree *node, int val) {
    BinaryTree *newNode  = new BinaryTree(val);
    queue<BinaryTree *> Q;
    Q.push(node);
    Q.push(nullptr);
    BinaryTree *curr = nullptr;
    while (!Q.empty()) {
        curr = Q.front();
        Q.pop();
        if (curr != nullptr) {
            if (curr->left != nullptr) {
                Q.push(curr->left);
            }else {
                curr->left = newNode;
                break;
            }
            if (curr->right != nullptr) {
                Q.push(curr->right);
            } else {
                curr->right = newNode;
                break;
            }
        } else {
            if (!Q.empty()) {
                Q.push(nullptr);
            }
        }
    }
    return *node;
}

BinaryTree &BinaryTree :: insert(int val) {
    return insert_int(this, val);
}

void BinaryTree :: inorder_int(BinaryTree *node, ostream &out) {
    if (node != nullptr) {
        inorder_int(node->left, out); 
        out << node->value << " ";
        inorder_int(node->right, out);
    }
}

void BinaryTree :: inorder(ostream &out) {
    inorder_int(this, out);
    out << endl;
}

void BinaryTree::levelOrder_int(BinaryTree *node, ostream &out) {
    queue<BinaryTree *> Q;
    Q.push(node);
    Q.push(nullptr);
    BinaryTree *curr = nullptr;
    while (!Q.empty()) {
        curr = Q.front();
        Q.pop();
        if (curr != nullptr) {
            out << curr->value << " ";
            if (curr->left != nullptr) {
                Q.push(curr->left);
            }
            if (curr->right != nullptr) {
                Q.push(curr->right);
            } 
        } else {
            if (!Q.empty()) {
                Q.push(nullptr);
            }
        }
    }
}

void BinaryTree::levelOrder(ostream &out) {
    levelOrder_int(this, out);
    out << endl;
}

BinaryTree* BinaryTree :: getNode_int(BinaryTree *node, int value, int occurance) {
    queue<BinaryTree *> Q;
    Q.push(node);
    int count = 0;
    BinaryTree *curr = nullptr;
    while (!Q.empty()) {
        curr = Q.front();
        Q.pop();
        if (curr != nullptr) {
            if (curr->value == value) {
                count = count + 1;
                if (count == occurance) {
                    break;
                }
            }
            if (curr->left != nullptr) {
                Q.push(curr->left);
            } 
            if (curr->right != nullptr) {
                Q.push(curr->right);
            }
        }
        curr = nullptr;
    }
    return curr;
}

BinaryTree* BinaryTree :: getNode(int value, int occurance) {
    return getNode_int(this, value, occurance);
    
}


int BinaryTree :: heightBalancedBinaryTree_int(BinaryTree *tree, bool &isBalanced) {
    if (isBalanced == false) {
      return 0;
    }
    if (tree == nullptr) {
      return 0;
    }
    int ltHeight, rtHeight;
    ltHeight = rtHeight = 0;
    ltHeight = heightBalancedBinaryTree_int(tree->left, isBalanced);
    rtHeight = heightBalancedBinaryTree_int(tree->right, isBalanced);
    if (abs(ltHeight - rtHeight) > 1) {
      //cout << "Balanced failed:" << tree->value << endl;
      isBalanced = false;
    }
    return (ltHeight > rtHeight) ? (ltHeight + 1) : (rtHeight + 1);
}

bool BinaryTree::heightBalancedBinaryTree() {
 
  bool isBalanced = true;
  (void)heightBalancedBinaryTree_int(this, isBalanced);
  return isBalanced;
}