#include "BST.h"
#include <iostream>
#include <vector>
using namespace std;

void testBST() {
    cout << "Testing BST" << endl;
    
    BST *btree = new BST(5);
    cout << "Inorder" << endl;
    btree->inorder();
    BST &temp = btree->remove(5);
    BST *t1 = &temp;
    if (t1 != nullptr) {
        cout << "Removed data:" << temp.value << endl;
    }
    delete &temp;

/*
    if (btree == nullptr) {
        cout << "btree is null";
    } else {
        cout << "Btree is not null: Inorder:" << endl;
        btree->inorder();
    }
*/

    BST *root = new BST(10);
    vector<int> list = {5, 3, 8, 12, 11, 15, 13, 14, 22, 25};
    for (auto &data:list) {
        //cout << "Entering data: " << data << endl;
        root->insert(data);
    }
    cout << "Inorder" << endl;
    root->inorder();
    cout << "Min: " << root->min() << endl;
    root->remove(12);
    cout << "Inorder" << endl;
    root->inorder();
    cout<< "Removing elements of BST" << endl;
    for (auto &data:list) {
        root->remove(data);
    }
    cout << "Inorder" << endl;
    root->inorder();
}

