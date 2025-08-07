//
// Created by raj on 14/6/25.
//

#include <gtest/gtest.h>

#include "../../src/Practice/LinkedListInBinaryTree.h"
#include "../../include/practice/TreeUtils.h"
#include "../../include/practice/ListUtils.h"

class LinkedListInBinaryTreeTest : public ::testing::Test {


};

TEST_F(LinkedListInBinaryTreeTest, IsSubPath_BasicCases) {
    // Create a binary tree
    std::vector<int> treeArray = {1, 2, 3, 4, -1, -1, 5};
    TreeNode* root = TreeUtils::CreateTree(treeArray);

    // Create a linked list that is a subpath
    std::vector<int> listArray = {2, 4};
    ListNode* head = ListUtils::CreateList(listArray);

    // Check if the linked list is a subpath in the binary tree
    ASSERT_TRUE(LinkedListInBinaryTree::IsSubPath(head, root));

    // Clean up
    delete root;
    delete head;
}