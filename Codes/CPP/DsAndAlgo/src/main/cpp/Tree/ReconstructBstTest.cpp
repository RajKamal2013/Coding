#include "Tree/ReconstructBST.h"
#include <iostream>
using namespace std;

void test_ReconstructBst() {
    vector<int> arr = {10, 4, 2, 1, 5, 17, 19, 18};
    cout << "Input: ";
    for (auto data:arr) {
        cout << data << " ";
    }
    cout << endl;
    BST *root = reconstructBst(arr);
    cout << "Output: ";
    root->inorder();
    return;
}

