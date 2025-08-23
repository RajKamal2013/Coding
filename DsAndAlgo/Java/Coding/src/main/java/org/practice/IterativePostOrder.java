package org.practice;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

public class IterativePostOrder {

    public static List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> postOrderList = new ArrayList<>();
        if (root == null) {
            return postOrderList;
        }
        Deque<TreeNode> stack = new ArrayDeque<>();
        stack.push(root);
        TreeNode prev, curr;
        prev = curr = null;
        while (!stack.isEmpty()) {
            curr = stack.peek();
            //Tree traversal (order is parent -> left/right)
            // Parent has left and right both, then insert left first. Right will be processed in diff case
            // Parent has only left or only right then insert in stack which one is not null.
            // Each node is which is entered here will be visited again in else case.
            if (prev == null || prev.left == curr || prev.right == curr) {
                if (curr.left != null) {
                    stack.push(curr.left);
                } else if (curr.right != null) {
                    stack.push(curr.right);
                } else {
                }
            } else if (curr.left == prev) {
                // We are visiting after left child, we need to visit after right child for postorder
                if (curr.right != null) {
                    stack.push(curr.right);
                } else {
                }
            } else {
                // We are visiting after left and right child, we need to add the node to postorder
                // we are visiting node who has no left and right child.
                postOrderList.add(curr.val);
                stack.pop();
            }
            prev = curr;
        }
        return postOrderList;
    }
}