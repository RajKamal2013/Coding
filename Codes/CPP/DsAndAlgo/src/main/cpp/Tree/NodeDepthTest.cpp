
#include "Tree/NodeDepth.h"
#include <iostream>
#include <vector>
using namespace std;

void test_NodeDepth() {
    cout << "--------Testing Sum of Node Depth of a Binary Tree ----------" << endl;
    BST *root = new BST(10);
    vector<int> list = {5, 3, 8, 12, 11, 15, 2, 4};
    for (auto &data:list) {
        //cout << "Entering data: " << data << endl;
        root->insert(data);
    }
    cout << "Inorder" << endl;
    root->inorder();
    int nodedepth = nodeDepths(root);
    cout << "Node Depth Sum: " << nodedepth << endl;
}



/*
 * Command:
 * 
 */