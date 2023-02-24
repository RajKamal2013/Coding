
#include "BinaryTree.h"
#include "SymmetricalTree.h"
#include <iostream>
#include <vector>
using namespace std; 

void test_SymmetricalTree() {
    BinaryTree *tree = new BinaryTree(1);
    vector<int> arr = {2, 2, 3, 4, 4, 3};
    for (auto data:arr) {
        tree->insert(data);
    }
    tree->levelOrder();
    tree->inorder();

    bool isSymmetrical = symmetricalTree(tree);
    cout << "Tree is symmetrical: " << isSymmetrical << endl;
}

int main() {
    test_SymmetricalTree();
    return 0;
}

/* Command 
 * clang++ -g -std=c++11 src/Tree/BinaryTree.cpp src/Tree/SymmetricalTreeTest.cpp -o bin/testTree && ./bin/testTree
 */