//
// Created by raj on 14/6/25.
//

#ifndef TREEUTILS_H
#define TREEUTILS_H
#include <queue>

#include "TreeNode.h"


class TreeUtils {
    public:
    /**
     * Creates a binary tree from an array representation.
     * Uses level order traversal to construct the tree.
     * @param array Vector of integers where -1 represents null nodes
     * @return Root node of the created tree
     */
    static TreeNode *CreateTree(std::vector<int> array) {
        if (array.empty()) {
            return nullptr;
        }

        int i = 0;
        auto root = new TreeNode(array[i]);
        auto q = std::queue<TreeNode *>();
        q.push(root);
        i = i + 1;

        int arr_size = static_cast<int>(array.size());
        while (i < arr_size) {
            TreeNode* current = q.front();
            q.pop();
            if (array[i] != -1) {
                current->left = new TreeNode(array[i]);
                q.push(current->left);
            }
            i = i + 1;
            if (i < arr_size && array[i] != -1) {
                current->right = new TreeNode(array[i]);
                q.push(current->right);
            }
            i = i + 1;
        }
        return root;

    }

    static void FillMatrix(std::vector<std::vector<std::string> > &matrix, TreeNode *root, int row, int left,
                           int right) {
        if (root == nullptr) {
            return;
        }
        int mid = (left + right) / 2;
        matrix[row][mid] = std::to_string(root->val);
        FillMatrix(matrix, root->left, row + 1, left, mid - 1);
        FillMatrix(matrix, root->right, row + 1, mid + 1, right);
    }


    static std::vector<std::vector<std::string>> GetTreeMatrix(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        if (root->left == nullptr && root->right == nullptr) {
            return {{std::to_string(root->val)}};
        }

        int height = GetHeight(root);
        int cols = (1 << height) - 1; // 2^height - 1
        std::string default_value = "";
        std::vector<std::vector<std::string>> matrix(height, std::vector<std::string>(cols, default_value));
        FillMatrix(matrix, root, 0, 0, cols - 1);
        return matrix;
    }

    static void PrintTree(TreeNode *root) {
        auto matrix = GetTreeMatrix(root);
        for (const auto &row : matrix)
        {
            for (const auto &val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    static void PrintTreeLevelOrder(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        auto q = std::queue<TreeNode*>();
        q.push(root);
        int level_size = 0;
        while (!q.empty()) {
            level_size = q.size();
            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                std::cout << node->val << " ";
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
    }

    static void PrintTreeInOrder(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        auto q = std::queue<TreeNode *>();
        q.push(root);
        int level_size = 0;
        while (!q.empty()) {
            level_size = q.size();
            for (int i = 0; i < level_size; i++) {
                TreeNode *node = q.front();
                q.pop();
                std::cout << node->val << " ";
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
    }

   static void PrintTreePreOrder(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        std::cout << root->val << " ";
        PrintTreePreOrder(root->left);
        PrintTreeInOrder(root->right);
    }

    static void PrintTreePostOrder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        PrintTreePostOrder(root->left);
        PrintTreePostOrder(root->right);
        std::cout << root->val << " ";
    }

    static int GetHeight(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left_height = GetHeight(root->left);
        int right_height = GetHeight(root->right);
        return std::max(left_height, right_height) + 1;
    }
};
#endif //TREEUTILS_H
