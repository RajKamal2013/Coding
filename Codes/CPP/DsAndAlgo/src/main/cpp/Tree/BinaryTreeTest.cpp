
#include "Tree/BinaryTree.h"
#include <iostream>
#include <vector>

using namespace std;

void test_BinaryTree() {
   vector<int> arr;
   arr = {3, 2, 5, 4, 9, 8, 18};
   BinaryTree *t1 = new BinaryTree(15);
   for (auto data: arr) {
        t1->insertBST(data);
    }
    t1->inorder();
    t1->levelOrder();

    cout << "Tree is Height Balanced: " << t1->heightBalancedBinaryTree() << endl; 
}

