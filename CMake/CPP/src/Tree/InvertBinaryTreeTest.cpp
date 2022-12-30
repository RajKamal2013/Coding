
#include "BinaryTree.h"
#include "InvertBinaryTree.h"
#include <iostream>
#include <vector>
using namespace std;


void test_InvertBinaryTree() {
    BinaryTree *root = new BinaryTree(1);
    vector<int> values = {2, 3, 4, 5, 6, 7, 8, 9};
    for (auto data: values) {
        root->insert(data);
    }
    cout << "InOder " << endl;
    root->inorder();
    cout << "Level Order" << endl;
    root->levelOrder();

    invertBinaryTree(root);
    cout << "Inverted Binary Tree" << endl;
    cout << "InOder " << endl;
    root->inorder();
    cout << "Level Order" << endl;
    root->levelOrder();

}


int main() {
    cout << " ----------- Testing Invert Binary Tree -------------" << endl;
    test_InvertBinaryTree();
}