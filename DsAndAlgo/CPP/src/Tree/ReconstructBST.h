/*
 * Reconstruct BST from given preorder
 *
 */

#include "BST.h"
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

BST *reconstructBst_int(const vector<int>& arr, int &startIdx, int endIdx, int upperBound, int lowerBound)
{
    if (startIdx > endIdx)
    {
        // Return nullptr when we've processed all nodes
        return nullptr;
    }

    BST *node = new BST(arr[startIdx]);
    cout << "Creating Node with " << arr[startIdx] << endl;
    startIdx = startIdx + 1;

    if (arr[startIdx] < node->value)
    {
        node->left = reconstructBst_int(arr, startIdx, endIdx, node->value, lowerBound);
    } 
    if (arr[startIdx] >= node->value)
    {
        if (arr[startIdx] >= upperBound) {
            //startIdx = startIdx - 1;
        } else {
            node->right = reconstructBst_int(arr, startIdx, endIdx, upperBound, node->value);
        }
    }
    
    return node;
}

BST *reconstructBst(const vector<int>& preOrderTraversalValues)
{
    if (preOrderTraversalValues.size() == 0)
    {
        return nullptr;
    }
    if (preOrderTraversalValues.size() == 1)
    {
        BST *root = new BST(preOrderTraversalValues[0]);
        return root;
    }
    BST *root = nullptr;
    int startIdx = 0;
    int endIdx = preOrderTraversalValues.size() - 1;
    root = reconstructBst_int(preOrderTraversalValues, startIdx, endIdx, INT_MAX, INT_MIN);
    return root;
}
