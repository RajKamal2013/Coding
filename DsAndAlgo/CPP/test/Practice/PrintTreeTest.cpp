#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "../../include/practice/TreeNode.h"
#include "../../src/Practice/PrintTree.h"

class PrintTreeTest : public ::testing::Test {
protected:
    TreeNode* root = nullptr;

    void SetUp() override {
        /* Build tree:   1
         *             /   \
         *            2     3
         */
        root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
    }

    void TearDown() override {
        delete root;
    }
};

TEST_F(PrintTreeTest, Solution_BasicTree) {
    std::vector<std::vector<std::string>> expected = {
        {"", "1", ""},
        {"2", "", "3"}
    };

    auto result = PrintTree::Solution(root);

    ASSERT_EQ(result.size(), expected.size());
    for (size_t i = 0; i < result.size(); ++i) {
        ASSERT_EQ(result[i].size(), expected[i].size());
        for (size_t j = 0; j < result[i].size(); ++j) {
            EXPECT_EQ(result[i][j], expected[i][j]);
        }
    }
}