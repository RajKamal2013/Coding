#include "Tree/FindClosestValue.h"
#include <iostream>
using namespace std;

void test_ClosestValueInBst() {
    vector<int> input;
    BST *tree = new BST(10);
    int target, closestValueToTarget;
    BST *curr;

    cout << "Testing Closest Value in BST Code" << endl;
    curr = tree;
    input = {5, 15, 2, 5, 13, 22, 1, 14};
    for (auto &data:input) {
        curr->insert(data);
    }
    target = 12;
    closestValueToTarget = findClosestValueInBst(tree, target);
    cout << "Input" << endl;
    cout << "Inorder: " << endl;
    curr->inorder();
    cout << "Target:" << target << endl;
    cout << "Output" << endl;
    cout << "Closest Value to Target:" << target << " is:" << closestValueToTarget << endl;


    target = 22;
    closestValueToTarget = findClosestValueInBst(tree, target);
    cout << "Input" << endl;
    cout << "Inorder: " << endl;
    curr->inorder();
    cout << "Target:" << target << endl;
    cout << "Output" << endl;
    cout << "Closest Value to Target:" << target << " is:" << closestValueToTarget << endl;


    BST *root = new BST(10);
    curr = root;
    input = {5, 3, 8, 12, 11, 15, 13, 14};
    for (auto &data:input) {
        curr->insert(data);
    }
    target = 20;
    closestValueToTarget = findClosestValueInBst(curr, target);
    cout << "Input" << endl;
    cout << "Inorder: " <<  endl;
    curr->inorder();
    cout << "Target:" << target << endl;
    cout << "Output" << endl;
    cout << "Closest Value to Target:" << target << " is:" << closestValueToTarget << endl;
}

