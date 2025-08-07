//
// Created by rk015348 on 25/05/25.
//

#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *leftChild, TreeNode *rightChild)
        : val(x), left(leftChild), right(rightChild) {}
};

#endif //TREENODE_H

