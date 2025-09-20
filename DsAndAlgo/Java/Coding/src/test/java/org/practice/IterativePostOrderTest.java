package org.practice;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.util.List;

public class IterativePostOrderTest {

    @Test
    @DisplayName("Post Order Traversal Test")
    void postOrderTraversalTest() {
        // Create a sample tree
        // Create a binary tree:
        //       1
        //      / \
        //     5   6
        //    / \
        //   7   3
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(5);
        root.right = new TreeNode(6);
        root.left.left = new TreeNode(7);
        root.left.right = new TreeNode(3);

        List<Integer> expectedPostOrder = List.of(7, 3, 5, 6, 1);
        // Perform post-order traversal
        List<Integer> postOrder = IterativePostOrder.postorderTraversal(root);


        Assertions.assertArrayEquals(expectedPostOrder.toArray(), postOrder.toArray(),
                "The post-order traversal did not return the expected result.");
        // The expected output should be 4, 5, 2, 3, 1
        // This can be verified by checking the console output or using a mock for System.out
    }

}
