/* 
 * Depth of a node: Distance from the root of the tree
 * Find the sum of Depth of all the node in the tree
 */

#ifndef NodeDepth_H
#define NodeDepth_H

#include "BST.h"

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

bool debug1= false;
int nodeDepths_int(BST *node) {
    map<int, int> nodesAtDepth; 
    int nodeCount = 0;
    queue<BST *> Q;
    BST *curr = nullptr;
    Q.push(node);
    Q.push(nullptr);
    nodeCount = 0;
    int depth = 1;
    while (!Q.empty()) {
        curr = Q.front();
        Q.pop();
        if (curr != nullptr) {
            if (curr->left != nullptr) {
                Q.push(curr->left);
                nodeCount = nodeCount + 1;
            } 
            if (curr->right != nullptr) {
                Q.push(curr->right);
                nodeCount = nodeCount + 1;
            }
        } else {
            if (debug1) {
                cout << "Inserting in Map: " << depth << " " << nodeCount << endl;
            }
            nodesAtDepth.insert(pair<int, int>(depth, nodeCount));
            nodeCount = 0;
            depth = depth + 1;
            if (!Q.empty()) {
                Q.push(nullptr);
            }
        }
    }

    int nodeDepth = 0;
    for (auto itr: nodesAtDepth) {
        nodeDepth = nodeDepth + (itr.first) * (itr.second);
    }
    return nodeDepth;
}

int nodeDepths(BST *root) {
    if (root == nullptr) {
        return -1;
    }

    if ((root->left == nullptr) && (root->right == nullptr)) {
        return 0;
    }

    return nodeDepths_int(root);
}

#endif 

