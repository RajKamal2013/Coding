
#include "BinaryTree.h"
#include "FindSuccessor.h"
#include <iostream>
#include <cassert>
#include <vector>

using namespace std; 

void test_FindSucccessor() {
    BinaryTree *tree = new BinaryTree(1);
    vector<int> arr = {2, 3, 4, 5};
    for (auto data: arr) {
        tree->insert(data);
    }
    tree->inorder();
    
    BinaryTree *node = tree->getNode(5, 1);
    assert(node != nullptr);
    BinaryTree *successor = findSuccessor(tree, node);
    if (successor == nullptr) {
        cout << "Successor of the Node: " << tree->value << " is: " << "NULL" << endl;
    } else {
        cout << "Successor of the Node: " << node->value << " is: " << successor->value << endl;
    }
    
   arr = {3, 2, 5, 4, 9, 8, 18};
   BinaryTree *t1 = new BinaryTree(15);
   for (auto data: arr) {
        t1->insertBST(data);
    }
    t1->inorder();

    node = t1->getNode(5, 1);
    assert(node != nullptr);
    successor = findSuccessor(t1, node);
    if (successor == nullptr) {
        cout << "Successor of the Node: " << node->value << " is: " << "NULL" << endl;
    } else {
        cout << "Successor of the Node: " << node->value << " is: " << successor->value << endl;
    }
}

int main() {
    test_FindSucccessor();
}