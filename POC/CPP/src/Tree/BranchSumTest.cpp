#include "BranchSum.h"
#include "BST.h"
#include <iostream>
#include <vector>

using namespace std; 

void test_BranchSum() {
    BST *root = new BST(10);
    vector<int> list = {5, 3, 8, 12, 11, 15};
    for (auto &data:list) {
        //cout << "Entering data: " << data << endl;
        root->insert(data);
    }
    root->inorder();

    vector<int> branchsum = branchSums(root);
    for (auto &data: branchsum) {
        cout << data << " " ;
    }
    cout << endl;
}

int main() {
    test_BranchSum();
    return 0;
}

/* 
 * clang++ -std=c++11 src/Tree/BST.cpp src/Tree/BranchSumTest.cpp -o bin/testTree && ./bin/testTree
 */