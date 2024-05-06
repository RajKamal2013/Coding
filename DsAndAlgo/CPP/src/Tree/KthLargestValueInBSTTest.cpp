#include <iostream>
#include <vector>
#include "KthLargestValueInBST.h"
using namespace std;

void test_KthLargestValueInBst() {
    BST *root = new BST(10);
    vector<int> list = {5, 3, 8, 12, 11, 15, 13, 14, 22, 25};
    for (auto data:list) {
        //cout << "Entering data: " << data << endl;
        root->insert(data);
    }
    cout << "Inorder" << endl;
    root->inorder();
    int kth = 3;
    int KthLargest = findKthLargestValueInBst(root, kth);
    cout << kth << "st/nd/rd/th Largest Value is: " << KthLargest << endl;

}


int main() {
    test_KthLargestValueInBst();
    return 0;
}