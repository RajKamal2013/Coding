/*
 * Given an integer and a BST, find the closest Value to the integer in the BST. 
 * Example:
 * Input
 *  BST: 
 *             10 
 *          /       \
 *         /         \ 
 *        5           15 
 *      /  \       /    \
 *     2     5    13       22
 *    /             \
 *  1                 14
 * 
 *  target : 12
 * Output : 13 
 * 
 * 
 */

/* ------------------------ Algorithm ------------------------
 * use Inorder iterator 
 * Corner Case 
 *  Tree == nullptr 
 *    return -1 
 *  All are greater than target -> smallest in the tree
 *  All are smaller than target -> largest in the tree 
 *  Target exist -> return target
 * 
 * Complexity -> O(n)
 *  
 * -------------------------------------------------------------
*/
#ifndef FindClosestValue_H
#define FindClosestValue_H
#include<iostream>
#include<vector>
#include "BST.h"
using namespace std;


int findClosestValueInBst_int(BST *tree, int target, int closest)
{
  if (abs(target - closest) > abs(target - tree->value)) {
    closest = tree->value;
  }
  if ((tree->left != nullptr) && (tree->value > target)) {
    return findClosestValueInBst_int(tree->left, target, closest);
  } else if ((tree->right != nullptr) && (tree->value < target)) {
    return findClosestValueInBst_int(tree->right, target, closest);
  } else {
    return closest;
  }
}
int findClosestValueInBst(BST *tree, int target) {
  /* Null Tree */
  if (tree == nullptr) {
    return -1;
  }
  /* One Node */
  if ((tree->left == nullptr) && (tree->right == nullptr)) {
    return tree->value;
  }
  
  int closest = tree->value;
  int closer = findClosestValueInBst_int(tree, target, closest);
  return closer;
}

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


#endif


