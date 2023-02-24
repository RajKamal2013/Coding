
#include "Diameter.h"
#include "BinaryTree.h"
#include <iostream>
#include <vector>

using namespace std;

void test_diameter() {
    BinaryTree *tree = new BinaryTree(30);
    vector<int> arr = {50, 20, 25, 26, 27, 18, 17, 16};
    for (auto data:arr) {
        tree->insertBST(data);
    }
    tree->inorder();
    tree->levelOrder();

    int diamter = binaryTreeDiameter(tree);
    cout << "Diameter of the Tree: " << diamter << endl;
    
}


int main() {
    test_diameter();
    return 0;
}

/* command 
 clang++ -g -std=c++11 src/Tree/BinaryTree.cpp src/Tree/DiameterTest.cpp -o bin/testTree && ./bin/testTree
*/