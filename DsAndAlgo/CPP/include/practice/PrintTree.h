//
// Created by rk015348 on 25/05/25.
//

#ifndef PRINTTREE_H
#define PRINTTREE_H

#include <vector>
#include <string>

#include "TreeNode.h"


class PrintTree {
public:
    static TreeNode* CreateTree(std::vector<int> array);
    static void PrintLevelOrder(TreeNode* root);
    static void PrintInOrder(TreeNode* root);
    static void PrintPreOrder(TreeNode* root);
    static void PrintPostOrder(TreeNode* root);
    static int GetHeight(TreeNode* root);
    static void FillMatrix(std::vector<std::vector<std::string>> matrix, TreeNode* root, int row, int left, int right);
    static std::vector<std::vector<std::string>> Solution(TreeNode* root);
};



#endif //PRINTTREE_H
