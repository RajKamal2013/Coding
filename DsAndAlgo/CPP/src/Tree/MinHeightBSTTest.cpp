#include "MinHeightBST.h"
#include <iostream>
using namespace std;

void test_minHeightBST() 
{
    cout << "Testing Minimum Height BST <Creat min height BST from a sorted array>" << endl;
    vector<int> arr = {1, 2, 5, 7, 10, 13, 14, 15, 22};
    BST *root = nullptr;
    root = minHeightBst(arr);
    if (root == nullptr) {
        cout << "Root is null. Size: 0" << endl;
    } else {
        cout << "Height of BST Created: " << root->height() << endl;
        cout << "BST:" << endl;
        root->inorder();
    }
    arr = {};
    root = minHeightBst(arr);
    if (root == nullptr) {
        cout << "Root is null. Size: 0" << endl;
    } else {
        cout << "Height of BST Created: " << root->height() << endl;
        cout << "BST:" << endl;
        root->inorder();
    }
}

int main() {
    test_minHeightBST();
}

