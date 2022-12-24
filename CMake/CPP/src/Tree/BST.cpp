#include "BST.h"
#include "debug.h"
#include <iostream>
#include <exception>

using namespace std;

BST:: BST(int val) {
    this->value = val;
    this->left = nullptr;
    this->right = nullptr;
}

BST& BST :: insert(int val) {
    BST *newNode = new BST(val);
    BST *node = nullptr;
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

bool BST :: contains (int val) {
    if (this->value == val) {
        return true;
    } else if (this->value > val) {
        return this->left->contains(val);
    } else {
        return this->right->contains(val);
    }
}

int BST :: min() {
    BST *node = this;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node->value;
} 

int BST :: max() {
    BST *node = this;
    while (node->right != nullptr) {
        node = node->right;
    }
    return node->right->value;
}

BST* BST::findMin(BST *node) {
    BST *curr = node;
    if (curr == nullptr) {
        cout << " Node is null pointer" << endl;
       // assert(false);
    }
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;
}

BST* BST::findMax(BST *node) {
    BST *curr = node;
    if (curr == nullptr) {
        cout << __FILE__ << ":" << __LINE__ <<  "Node is null pointer" << endl;
       // assert(false);
    }
    while (curr->right != nullptr) {
        curr = curr->right;
    }
    return curr;
}

BST& BST:: remove(int val) {
    BST *curr = this;
    BST *tmp = nullptr;
    while (curr != nullptr) {
        if (curr->value > val) {
                curr = curr->left;
        } else if (curr->value < val) {
                curr = curr->right;
        } else {
            if ((curr->left == nullptr) && (curr->right == nullptr)) {
                tmp = curr;
                curr = nullptr;
                break;
            } else if ((curr->left == nullptr) || (curr->right == nullptr)) {
                    tmp = curr;   
                    curr = (curr->left != nullptr)? curr->left: curr->right;
                    break;
            } else {
                    BST* rtMin = findMin(curr->right);
                    int tmpVal = curr->value;
                    curr->value = rtMin->value;
                    rtMin->value = tmpVal;
                    curr = curr->right;
            }
        }
    }
   // delete tmp;
    return *this;
}

void BST :: Inorder(BST *node, ostream &out) {
    if (node != nullptr) {
        Inorder(node->left, out); 
        out << node->value << " ";
        Inorder(node->right, out);
    }
}

void BST:: inorder(ostream &out) {
    Inorder(this, out);
    out << endl;
}
