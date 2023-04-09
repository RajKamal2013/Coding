#include <iostream>
#include "Tree/ValidateBST.h"
using namespace std;

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

