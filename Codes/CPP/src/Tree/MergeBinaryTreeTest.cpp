
#include "BinaryTree.h"
#include "MergeBinaryTree.h"
#include <iostream>
#include <vector>

using namespace std;

void test_MergeBinaryTree() {
    cout << "Testing merging of Binary Tree" << endl;
    BinaryTree *tree1 = new BinaryTree(1);
    vector<int> arr = {2, 3, 4, 5, 6};
    for (auto data: arr) {
        tree1->insert(data);
    }
    BinaryTree *tree2 = new BinaryTree(1);
    arr = {2, 3, 4, 5};
    for (auto data: arr) {
        tree2->insert(data);
    }
    cout << "Tree1" << endl;
    tree1->inorder();
    tree1->levelOrder();

    cout << "Tree2" << endl;
    tree2->inorder();
    tree2->levelOrder();

    BinaryTree *mergedTree = mergeBinaryTrees(tree1, tree2);
    cout << "Merged Binary Tree: " << endl;
    mergedTree->inorder();
    mergedTree->levelOrder();
}

int main() {
    test_MergeBinaryTree();
}