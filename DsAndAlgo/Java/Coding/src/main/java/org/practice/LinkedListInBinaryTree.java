package org.practice;

import com.sun.source.tree.Tree;

public class LinkedListInBinaryTree {

    public static boolean dfsVisit(ListNode listNode, TreeNode treeNode) {
        if (listNode == null) {
            return true; // Reached the end of the linked list
        }
        if (treeNode == null) {
            return false; // Reached a leaf node in the tree without matching the list
        }
        if (listNode.val != treeNode.val) {
            return false; // Values do not match
        }
        // Continue searching in both left and right subtrees
        return dfsVisit(listNode.next, treeNode.left) || dfsVisit(listNode.next, treeNode.right);

    }
    public static boolean isSubPath(ListNode head, TreeNode root) {
        if (head == null) return  true;
        if (root == null) return false;
        // Start DFS from the root of the tree
        if (dfsVisit(head, root)) {
            return true; // Found a matching path
        }
        return  isSubPath(head, root.left) || isSubPath(head, root.right);
    }

}
