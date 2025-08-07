//
// Created by raj on 14/6/25.
//

#ifndef LINKEDLISTINBINARYTREE_H
#define LINKEDLISTINBINARYTREE_H

#include "../../include/practice/TreeNode.h"
#include "../../include/practice/ListNode.h"

class LinkedListInBinaryTree {
public:
    static bool DfsVist(ListNode *head, TreeNode *root);
    static bool IsSubPath(ListNode *head, TreeNode *root);
};

inline auto LinkedListInBinaryTree::DfsVist(ListNode* head, TreeNode* root) -> bool
{
    if (head == nullptr) {
        return true; // An empty linked list is always a subpath
    }
    if (root == nullptr) {
        return false; // Reached the end of the tree without matching the linked list
    }
    if (root->val != head->val) {
        return false; // Current node doesn't match, continue searching in both subtrees
    }
    return DfsVist(head->next, root->left) ||
        DfsVist(head->next, root->right); // Check both left and right subtrees
}

inline bool LinkedListInBinaryTree::IsSubPath(ListNode* head, TreeNode* root)
{
    if (head == nullptr) {
        return true; // An empty linked list is always a subpath
    }
    if (root == nullptr) {
        return false; // Reached the end of the tree without matching the linked list
    }
    if (DfsVist(head, root)) {
        return true;
    }
    return IsSubPath(head, root->left) || IsSubPath(head, root->right); // Check both left and right subtrees
}


#endif //LINKEDLISTINBINARYTREE_H
