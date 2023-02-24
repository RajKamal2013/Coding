/*
 * Reconstruct BST from given preorder
 *
 */

#include "BST.h"
#include <iostream>
using namespace std;

int debug = false;

BST *reconstructBst_int(vector<int> arr, int &startIdx, int endIdx, int upperBound, int lowerBound)
{
    if (startIdx > endIdx)
    {
        if (debug)
        {
            cout << __FILE__ << ":" << __LINE__ << "reconstructBst_int(): Return Iteration completed" << endl;
        }
        return nullptr;
    }
    if (debug)
    {
        cout << __FILE__ << ":" << __LINE__ << "reconstructBst_int(): Next Element to enter:" << arr[startIdx] << endl;
    }

    BST *node = new BST(arr[startIdx]);
    cout << "Creating Node with " << arr[startIdx] << endl;
    startIdx = startIdx + 1;
    if (debug)
    {
        cout << "Node Created:" << node->value << endl;
    }

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
    
    if (debug)
    {
        cout << "Node Entering Complete:" << node->value << endl;
    }
    return node;
}

BST *reconstructBst(vector<int> preOrderTraversalValues)
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
