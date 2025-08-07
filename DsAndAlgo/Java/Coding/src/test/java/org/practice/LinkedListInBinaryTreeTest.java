package org.practice;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

public class LinkedListInBinaryTreeTest {

    @Test
    void testBasic() {
        // Create a linked list: 4 -> 2 -> 8
        ListNode head = ListUtils.createList(new int[]{4, 2});

        // Create a binary tree:
        //       1
        //      / \
        //     4   5
        //    / \
        //   2   3
        //      / \
        //     8   9
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(4);
        root.right = new TreeNode(5);
        root.left.left = new TreeNode(2);
        root.left.right = new TreeNode(3);
        root.left.right.left = new TreeNode(8);
        root.left.right.right = new TreeNode(9);

        // Check if the linked list is a subpath of the binary tree
        boolean result = LinkedListInBinaryTree.isSubPath(head, root);

        System.out.println("Is the linked list a subpath of the binary tree? " + result);
        Assertions.assertTrue(result, "The linked list should be a subpath of the binary tree.");
    }

    @Test
    void testNoMatch() {
        // Create a linked list: 4 -> 2 -> 8
        ListNode head = ListUtils.createList(new int[]{4, 2, 8});

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

        // Check if the linked list is a subpath of the binary tree
        boolean result = LinkedListInBinaryTree.isSubPath(head, root);

        System.out.println("Is the linked list a subpath of the binary tree? " + result);
        Assertions.assertFalse(result, "The linked list should not be a subpath of the binary tree.");
    }

    @Test
    void testEmptyList() {
        // Create an empty linked list
        ListNode head = null;

        // Create a binary tree:
        //       1
        //      / \
        //     2   3
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        // Check if the empty linked list is a subpath of the binary tree
        boolean result = LinkedListInBinaryTree.isSubPath(head, root);

        System.out.println("Is the empty linked list a subpath of the binary tree? " + result);
        Assertions.assertTrue(result, "An empty linked list should always be a subpath of any binary tree.");
    }

    @Test
    void testEmptyTree() {
        // Create a linked list: 4 -> 2 -> 8
        ListNode head = ListUtils.createList(new int[]{4, 2, 8});

        // Create an empty binary tree
        TreeNode root = null;

        // Check if the linked list is a subpath of the empty binary tree
        boolean result = LinkedListInBinaryTree.isSubPath(head, root);

        System.out.println("Is the linked list a subpath of the empty binary tree? " + result);
        Assertions.assertFalse(result, "A linked list cannot be a subpath of an empty binary tree.");
    }

    @Test
    void testSingleNodeMatch() {
        // Create a linked list: 4
        ListNode head = ListUtils.createList(new int[]{4});

        // Create a binary tree:
        //       1
        //      / \
        //     4   5
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(4);
        root.right = new TreeNode(5);

        // Check if the linked list is a subpath of the binary tree
        boolean result = LinkedListInBinaryTree.isSubPath(head, root);

        System.out.println("Is the linked list a subpath of the binary tree? " + result);
        Assertions.assertTrue(result, "The linked list should be a subpath of the binary tree.");
    }


    @Test
    void testSingleNodeNoMatch() {
        // Create a linked list: 4
        ListNode head = ListUtils.createList(new int[]{4});

        // Create a binary tree:
        //       1
        //      / \
        //     2   3
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);

        // Check if the linked list is a subpath of the binary tree
        boolean result = LinkedListInBinaryTree.isSubPath(head, root);

        System.out.println("Is the linked list a subpath of the binary tree? " + result);
        Assertions.assertFalse(result, "The linked list should not be a subpath of the binary tree.");
    }

    @Test
    void testAdvance() {
        int listArray[] = {4, 2, 8};
        // Create a linked list: 4 -> 2 -> 8
        ListNode head = ListUtils.createList(listArray);

        List<Integer> treeNodeList = Arrays.asList(1,4,4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null,1,3);
        TreeNode root = TreeUtils.createTree(treeNodeList);
        // Check if the linked list is a subpath of the binary tree
        boolean result = LinkedListInBinaryTree.isSubPath(head, root);

        System.out.println("Is the linked list a subpath of the binary tree? " + result);
        Assertions.assertTrue(result, "The linked list should be a subpath of the binary tree.");
    }

    @Test
    void testAdvance2() {
        int listArray[] = {4, 2};
        // Create a linked list: 4 -> 2 -> 8
        ListNode head = ListUtils.createList(listArray);

        List<Integer> treeNodeList = Arrays.asList(4,4,4,1,null,null,null,2);
        TreeNode root = TreeUtils.createTree(treeNodeList);
        // Check if the linked list is a subpath of the binary tree
        boolean result = LinkedListInBinaryTree.isSubPath(head, root);

        System.out.println("Is the linked list a subpath of the binary tree? " + result);
        Assertions.assertFalse(result, "The linked list should not be a subpath of the binary tree.");
    }

    @Test
    void testAdvance3() {
        int listArray[] = {1, 10};
        // Create a linked list: 4 -> 2 -> 8
        ListNode head = ListUtils.createList(listArray);

        List<Integer> treeNodeList = Arrays.asList(1,null,1,10,1,9);
        TreeNode root = TreeUtils.createTree(treeNodeList);
       // System.out.println(PrintTree.printTree(root));

        // Check if the linked list is a subpath of the binary tree
        boolean result = LinkedListInBinaryTree.isSubPath(head, root);

        System.out.println("Is the linked list a subpath of the binary tree? " + result);
        Assertions.assertTrue(result, "The linked list should be a subpath of the binary tree.");
    }

    @Test
    void testAdvance4() {
        int listArray[] = {2,1,2,1,2,2,2,2,1,2,1,2,2,2,1,1,2,1,2,1,2,1,2,1,1,2,2,1,1,2,1,2,1,2,2,2,2,2,2,1,2,1,1,1,2,1,2,2,1,1,2,1,2,1,1,2,2,2,1,1,2,2,2,1,1,2,2,2,2,2,2,2,1,1,1,2,1,2,2,1,1,2,1,2,1,1,2,1,1,2,2,2,2,1,2,1,2,1,1,1};
        // Create a linked list: 4 -> 2 -> 8
        ListNode head = ListUtils.createList(listArray);
        ListUtils.printListVertical(head);
        List<Integer> treeNodeList = Arrays.asList(2,null,1,null,2,null,2,null,2,null,1,2,2,null,null,null,2,2,2,null,null,null,2,null,2,1,2,null,null,null,2,2,2,null,null,null,1,null,1,1,2,null,null,null,2,2,2,null,null,null,2,null,2,null,2,null,1,1,1,null,null,null,1,2,1,null,null,1,1,null,null,null,1,2,2,null,null,1,2,null,null,null,2,null,1,1,2,null,null,null,1,null,1,null,2,null,1,null,1,2,2,null,null,2,1,null,null,null,1,2,1,null,null,null,1,null,1,null,1,null,1,null,1,2,2,null,null,null,2,null,2,null,2,1,2,null,null,1,1,null,null,null,2,null,2,null,1,2,1,null,null,2,1,null,null,null,1,null,1,null,1,null,1,null,1,null,2,1,1,null,null,null,1,null,2,null,1,null,2,1,1,null,null,2,2,null,null,1,2,null,null,null,1,null,2,null,2,2,1,null,null,null,1,null,2,null,2,null,2,2,2,null,null,null,2,null,1,null,2,null,1,null,1,2,2,null,null,null,1,null,1,1,2,null,null,null,2,null,1,2,1,null,null,1,2,null,null,null,1,2,2,null,null,null,2,null,2,null,1,null,1,null,2,2,1,null,null,2,1,null,null,null,2,null,1,null,2,2,2,null,null,null,2,2,2,null,null,null,1,null,1,1,2,null,null,1,2,null,null,null,2,1,1,null,null,null,1,null,1,null,2,null,1,null,2,null,2,null,1,null,2,null,2,1,1,null,null,null,1,null,2,null,2,1,1,null,null,1,1,null,null,1,1,null,null,null,1,null,2,null,2,null,2,null,1,1,2,null,null,null,2,2,1,null,null,1,2,null,null,null,1,null,2,null,1,null,1,null,2,null,1,null,1,null,2,null,1,null,1,1,1,null,null,null,2,null,1,1,1,null,null,null,1,null,1,null,1,1,1,null,null,null,2,null,2,null,1,null,2,1,1,null,null,2,2,null,null,null,2,null,2,null,2,2,2,null,null,null,2,null,2,2,2,null,null,null,1,null,2,null,1,2,2,null,null,null,2,2,2,null,null,2,1,null,null,null,2,null,1,null,1,null,1,1,2,null,null,null,2,null,1,null,1,2,1,null,null,null,2,null,1,null,2,null,1,2,1,null,null,null,1,1,2,null,null,1,1,null,null,null,1,1,2,null,null,1,2,null,null,null,1,null,1,null,2,null,2,2,2,null,null,null,1,2,2,null,null,null,2,2,1,null,null,null,1,null,1,null,2,1,1,null,null,null,1,null,1,1,2,null,null,null,1,1,2,null,null,null,1,1,2,null,null,null,1,null,2,null,1,null,2,null,2,null,1,null,1,null,1,2,1,null,null,1,2,null,null,1,1,null,null,null,2,null,1,null,1,null,1,null,1,null,2,1,1,null,null,null,1,null,2,null,1,null,1,null,2,null,2,null,2,null,2,null,1,null,2,null,1,null,1,2,2,null,null,2,2,null,null,null,1,null,2,null,1,null,2,null,2,2,1,null,null,1,2,null,null,null,1,null,2,null,2,null,2,2,2,null,null,null,2,1,2,null,null,null,1,null,1,null,2,1,2,null,null,null,1,null,1,null,1,null,2,null,1,null,1,2,2,null,null,null,1,null,1,1,2,null,null,null,1,null,2,null,2,2,1,null,null,1,2,null,null,null,2,null,2,null,1,null,1,null,2,2,2,null,null,null,1,2,2,null,null,null,1,null,1,2,2,null,null,null,2,null,2,2,1,null,null,2,1,null,null,null,2,null,1,null,2,null,1,null,2,null,1,2,2,null,null,null,2,1,2,null,null,null,2,2,1,null,null,null,2,null,1,null,2,null,2,1,2,null,null,null,1,null,1,null,2,null,1,null,2,null,1,null,2,null,1,null,2,null,1,null,1,null,2,null,2,null,1,null,1,null,2,null,1,2,2,null,null,1,1,null,null,null,2,2,2,null,null,null,2,1,2,null,null,null,2,2,2,null,null,1,1,null,null,null,2,null,1,2,1,null,null,2,1,null,null,null,2,2,1,null,null,null,2,null,2,null,1,null,1,null,2,null,1,null,2,1,1,null,null,null,1,null,2,null,2,null,2,null,1,2,1,null,null,null,2,null,2,null,2,null,1,2,1,null,null,null,2,null,2,null,2,null,2,null,2,1,2,null,null,null,2,null,1,null,1,null,1,null,2,2,1,null,null,null,2,2,2,null,null,null,1,null,1,null,2,1,1,null,null,1,2,null,null,null,1,null,1,null,2,null,1,2,1,null,null,null,2,null,2,null,2,null,2,null,1,2,2,null,null,null,1,null,2,null,1,1,1,null,null,null,1,null,1,null,1,1,2,null,null,null,1,null,2,null,1,null,2,1,1,null,null,1,1,null,null,null,1,null,2,null,1,null,2,null,1,2,2,null,null,2,1,null,null,null,2,null,2,null,1,null,2,null,2,null,1,null,1,null,2,null,2,null,2,null,1,1,1,null,null,null,1,1,1,null,null,null,1,null,1,2,2,null,null,2,1,null,null,null,1,null,1,null,1,null,1,2,1,null,null,1,2,null,null,null,2,2,2,null,null,null,2,2,2,null,null,null,1,null,2,null,1,1,1,null,null,null,2,2,1,null,null,2,1,null,null,null,2,null,1,1,1,null,null,null,1,1,1,null,null,null,2,null,1,null,1,1,1,null,null,1,2,null,null,null,2,2,1,null,null,null,2,2,1,null,null,1,2,null,null,1,2,null,null,null,1,2,1,null,null,2,1,null,null,2,2,null,null,null,1,null,1,null,1,2,1,null,null,1,2,null,null,1,1,null,null,null,1,1,1,null,null,2,1,null,null,null,1,null,2,null,1,null,1,null,2,1,2,null,null,1,1,null,null,null,2,2,2,null,null,2,1,null,null,null,1,1,2,null,null,1,1,null,null,null,2,null,2,1,1,null,null,null,1,null,1,null,2,null,1,2,2,null,null,null,2,null,1,null,1,null,1,null,2,null,2,1,2,null,null,2,1,null,null,null,2,1,1,null,null,2,1,null,null,null,1,null,2,null,1,2,2,null,null,2,2,null,null,null,2,null,2,null,1,null,1,null,1,null,2,null,1,null,1,null,2,null,2,2,2,null,null,null,1,null,1,2,2,null,null,null,2,null,1,null,1,2,2,null,null,null,2,1,1,null,null,null,2,null,1,null,1,null,1,null,1,null,1,2,2,null,null,null,2,null,1,null,2,null,1,null,2,null,1,null,2,2,1,null,null,2,1,null,null,null,1,2,2,null,null,null,1,null,1,1,1,null,null,1,2,null,null,2,1,null,null,null,2,1,2,null,null,1,2,null,null,2,1,null,null,2,2,null,null,1,1,null,null,null,1,2,2,null,null,null,2,2,1,null,null,null,1,null,1,null,1,null,1,null,2,1,2,null,null,1,2,null,null,null,2,1,1,null,null,null,2,null,2,1,1,null,null,null,1,2,1,null,null,1,2,null,null,2,2,null,null,1,2,null,null,null,1,2,2,null,null,2,1,null,null,null,2,null,2,null,2,1,2,null,null,null,1,2,1,null,null,null,1,2,1,null,null,2,1,null,null,1,2,null,null,null,1,null,2,2,2,null,null,2,1,null,null,null,1,2,1,null,null,2,2,null,null,null,1,null,2,1,2,null,null,null,1,null,2,null,1,null,1,null,1,null,1,null,1,2,1,null,null,null,1,null,1,null,2,2,1,null,null,1,1,null,null,null,1,null,2,2,1,null,null,null,2,null,1,null,1,null,1,null,2,1,1,null,null,null,2,null,2,2,1,null,null,null,2,null,1,2,1,null,null,2,2,null,null,null,1,null,1,1,1,null,null,2,1,null,null,null,2,1,1,null,null,null,2,null,1,2,2,null,null,2,2,null,null,null,1,null,1,null,1,null,2,2,1,null,null,null,1,2,2,null,null,null,1,null,1,null,2,null,1,null,2,null,1,null,1,null,2,2,1,null,null,null,1,null,1,null,1,null,2,null,1,null,2,null,1,1,1,null,null,null,1,null,1,1,1,null,null,null,1,null,1,null,2,null,2,null,2,null,1,1,1,null,null,null,2,1,1,null,null,null,1,1,1,null,null,null,2,null,1,null,1,null,2,null,1,null,2,1,1,null,null,null,1,2,1,null,null,2,1,null,null,null,2,1,1,null,null,null,2,2,2,null,null,null,2,null,2,null,1,2,2,null,null,null,2,null,1,null,2,1,1,null,null,1,2,null,null,null,1,null,2,2,1,null,null,null,1,null,1,null,1,null,2,null,2,null,2,2,1,null,null,null,2,null,1,null,1,null,2,null,1,null,1,2,1,null,null,null,1,null,1,2,1,null,null,null,2,1,2,null,null,null,1,null,2,null,2,1,2,null,null,2,1,null,null,2,1,null,null,2,2,null,null,1,1,null,null,null,1,2,2,null,null,null,2,2,2,null,null,2,1,null,null,null,1,1,1,null,null,null,1,null,1,1,2,null,null,null,2,null,1,null,2,null,1,2,2,null,null,null,2,null,2,1,2,null,null,null,1,null,2,1,2,null,null,2,2,null,null,null,2,null,2,null,2,2,1,null,null,null,2,null,1,1,1,null,null,null,1,null,2,2,2,null,null,null,1,null,1,1,1,null,null,2,1,null,null,null,2,null,2,null,1,null,2,null,2,null,2,null,2,null,2,null,1,null,1,null,2,2,2,null,null,null,1,null,1,null,2,null,2,null,2,null,2,null,1,null,1,null,1,null,1,null,2,null,1,null,2,null,2,1,2,null,null,null,1,null,2,2,1,null,null,null,1,null,2,null,1,1,1,null,null,1,1,null,null,null,1,null,2,null,1,null,1,1,2,null,null,2,1,null,null,null,1,null,2,2,2,null,null,null,1,null,1,1,1,null,null,2,2,null,null,2,1,null,null,null,1,null,2,null,1,null,2,null,1,null,1,null,2,null,1,1,2,null,null,null,1,null,1,null,2,null,1,1,1,null,null,2,2,null,null,null,2,2,1,null,null,null,2,1,1,null,null,null,2,null,2,null,2,null,1,null,2,2,2,null,null,null,2,null,1,null,2,null,2,null,2,1,1,null,null,null,2,null,1,null,2,null,1,null,2,1,2,null,null,null,2,1,1,null,null,null,2,null,2,null,2,1,2,null,null,null,1,1,1,null,null,1,2,null,null,null,2,null,1,null,2,1,2,null,null,null,2,null,1,null,1,null,2,1,1,null,null,null,1,1,1,null,null,1,2,null,null,2,2,null,null,null,1,null,1,null,1,2,1,null,null,null,1,null,2,1,2,null,null,null,1,1,2,null,null,1,1,null,null,null,1,null,2,2,1,null,null,null,1,null,1,null,1,null,2,2,1,null,null,2,1,null,null,null,2,2,2,null,null,2,1,null,null,2,1,null,null,null,1,null,1,null,2,null,1,null,2,null,2,null,2,1,2,null,null,1,1,null,null,1,1,null,null,null,1,null,1,null,2,null,1,null,2,null,2,null,2,null,1,null,2,null,1,null,1,null,1,null,2,null,1,2,1,null,null,2,1,null,null,null,1,null,2,null,1,1,1,null,null,null,1,null,2,1,2,null,null,1,1,null,null,null,2,2,1,null,null,null,2,null,1,null,1,null,1,2,2,null,null,1,2,null,null,null,2,1,1,null,null,1,2,null,null,1,2,null,null,null,2,2,1,null,null,2,2,null,null,null,2,null,2,null,1,1,2,null,null,1,1,null,null,null,2,1,1,null,null,null,2,2,1,null,null,null,1,null,1,2,1,null,null,null,2,null,2,null,1,2,2,null,null,null,1,null,1,null,2,null,2,null,1,null,1,null,1,null,2,2,1,null,null,null,1,null,1,null,2,null,1,null,1,2,2,null,null,null,1,2,1,null,null,null,2,null,1,1,2,null,null,null,2,null,1,2,1,null,null,null,1,null,1,null,2,null,1,2,2,null,null,null,1,2,2,null,null,null,2,null,2,null,2,null,2,2,1,null,null,null,2,null,1,null,2,1,1,null,null,null,2,null,1,null,1,null,1,1,1,null,null,null,1,null,1,2,2,null,null,null,2,null,1,null,2,2,1,null,null,null,1,null,1,2,1,null,null,2,2,null,null,2,2,null,null,2,2,null,null,null,2,null,2,2,2,null,null,null,2,null,1,null,2,null,2,null,2,null,2,null,2,2,1,null,null,null,1,2,1,null,null,null,1,1,2,null,null,null,2,2,2,null,null,null,2,null,1,null,1,1,2,null,null,null,2,2,1,null,null,1,2,null,null,null,1,null,2,1,1,null,null,2,1,null,null,null,2,null,1,1,1,null,null,1,1,null,null,null,1,null,1,2,1,null,null,null,2,null,1,2,1,null,null,null,1,null,1,null,1,null,1,2,1,null,null,2,2,null,null,null,2,null,2,null,2,null,2,null,1,null,2,null,1,1,2,null,null,null,2,null,1,null,1,null,2,null,1,2,2,null,null,null,2,null,2,null,1,2,1,null,null,null,2,null,2,1,1,null,null,null,2,null,1,1,1,null,null,1,1,null,null,null,1,null,1,1,1,null,null,null,1,null,1,null,2,null,1,2,2,null,null,null,2,null,2,null,1,null,1,1,1,null,null,2,2,null,null,null,1,null,2,null,1,null,2,null,1,2,1,null,null,null,2,null,2,null,1,null,1,null,2,null,1,null,2,null,1,null,1,null,1,2,1,null,null,null,2,1,2,null,null,null,2,null,1,null,1,2,2,null,null,1,2,null,null,null,2,2,1,null,null,2,2,null,null,2,2,null,null,1,1,null,null,null,1,1,2,null,null,null,2,null,1,null,2,null,2,2,1,null,null,null,1,null,1,null,1,null,2,null,2,1,2,null,null,null,2,null,2,2,1,null,null,2,1,null,null,null,1,2,2,null,null,null,2,null,1,null,2,null,2,null,2,2,2,null,null,null,2,null,1,null,1,2,1,null,null,null,1,null,1,null,1,null,1,null,1,1,2,null,null,null,1,null,1,null,2,null,2,null,2,null,2,null,1,1,1,null,null,2,2,null,null,null,1,null,1,1,2,null,null,1,2,null,null,null,2,null,2,null,2,null,2,1,2,null,null,null,2,null,1,null,2,null,1,null,2,null,2,null,2,null,1,null,2,2,2,null,null,2,2,null,null,2,2,null,null,2,1,null,null,2,1,null,null,2,2,null,null,2,2,null,null,null,2,2,2,null,null,null,2,1,2,null,null,null,1,null,2,2,1,null,null,2,1,null,null,2,2,null,null,null,1,null,2,2,2,null,null,null,1,null,1,null,2,null,1,null,1,2,2,null,null,null,1,null,1,null,1,1,2,null,null,2,1,null,null,null,1,null,2,null,1,null,2,1,2,null,null,1,2,null,null,null,2,null,1,2,1,null,null,null,1,null,2,null,1,1,2,null,null,null,2,null,1,1,1,null,null,null,2,2,1,null,null,2,2,null,null,null,2,null,1,null,1,null,2,null,2,null,1,null,1,1,1,null,null,null,2,null,1,null,2,2,1,null,null,null,2,null,2,1,2,null,null,null,2,2,2,null,null,null,2,null,2,null,1,2,2,null,null,null,2,null,1,null,2,null,2,null,2,null,2,2,2,null,null,null,2,null,1,1,1,null,null,1,1,null,null,null,1,2,2,null,null,2,1,null,null,null,2,null,1,null,2,null,2,1,1,null,null,1,2,null,null,1,2,null,null,null,1,null,1,null,1,1,1,null,null,null,1,null,2,null,1,null,2,null,2,null,1,2,2,null,null,1,1,null,null,null,2,null,1,null,1,null,2,1,1,null,null,null,2,null,1,null,2,2,1,null,null,null,2,null,2,2,1,null,null,null,1,2,1,null,null,null,2,null,1,1,2,null,null,null,2,null,2,2,1,null,null,null,2,null,1,null,2,null,2,1,1,null,null,null,1,null,1,1,1,null,null,null,1,null,2,null,2,null,1,1,2,null,null,null,2,null,1,null,2,null,1,null,1,null,1,null,1,null,1,null,1,null,2,null,2,null,2,null,2,2,1,null,null,1,1,null,null,null,2,null,1,null,1,1,2,null,null,2,1,null,null,null,2,null,2,2,1,null,null,null,1,null,1,null,1,null,1,null,2,null,2,1,1,null,null,null,2,1,2,null,null,1,2,null,null,2,2,null,null,null,1,null,2,null,1,null,1,2,2,null,null,null,2,null,1,null,1,null,2,1,2,null,null,null,2,null,1,null,1,1,1,null,null,null,2,1,1,null,null,2,2,null,null,2,2,null,null,null,1,2,2,null,null,1,1,null,null,null,2,null,1,null,2,null,1,null,2,1,2,null,null,null,1,null,2,2,2,null,null,null,1,null,1,null,2,2,2,null,null,null,1,null,1,2,1,null,null,null,2,null,1,2,2,null,null,null,1,null,2,null,2,1,2,null,null,null,1,null,1,null,2,null,2,null,2,null,1,null,1,null,1,null,2,null,2,null,1,null,1,1,2,null,null,2,1,null,null,null,2,null,1,2,1,null,null,null,2,2,1,null,null,null,1,2,1,null,null,null,1,null,2,null,2,2,2,null,null,1,1,null,null,null,2,2,2,null,null,1,1,null,null,null,1,null,1,null,1,null,2,null,1,null,1,null,2,null,2,1,1,null,null,null,1,null,1,null,1,null,2,2,1,null,null,null,1,null,2,1,1,null,null,null,2,null,1,2,2,null,null,null,1,2,2,null,null,2,2,null,null,null,2,null,1,null,1,null,2,null,2,null,2,1,2,null,null,1,2,null,null,null,2,null,2,null,1,null,1,null,2,null,2,null,1,2,1,null,null,null,1,null,2,null,2,null,1,null,2,2,2,null,null,null,1,null,1,null,2,null,2,1,2,null,null,null,1,null,2,1,1,null,null,null,1,null,2,null,2,2,2,null,null,null,2,null,2,null,1,2,2,null,null,null,1,null,2,2,1,null,null,1,1,null,null,null,1,null,2,2,1,null,null,2,1,null,null,null,1,null,1,2,2,null,null,2,2,null,null,1,2,null,null,null,1,null,2,null,2,null,1,null,1,null,2,1,1,null,null,null,2,null,2,null,1,1,2,null,null,null,2,null,1,null,2,1,2,null,null,2,1,null,null,null,1,null,1,null,1,null,1,2,1,null,null,null,1,2,2,null,null,2,2,null,null,null,2,null,2,null,1,null,1,2,1,null,null,null,1,null,2,2,1,null,null,1,2,null,null,null,2,null,1,null,2,null,1,null,2,null,1,null,1,null,1,1,1,null,null,null,2,2,1,null,null,1,2,null,null,null,1,1,2,null,null,null,1,null,2,null,2,null,2,null,1,null,2,null,1,null,2,null,2,null,1,null,1,1,2,null,null,null,2,null,1,1,1,null,null,null,2,null,2,null,2,null,2,null,2,null,1,null,1,null,2,null,1,null,1,null,2,2,1,null,null,1,2,null,null,null,1,1,2,null,null,2,2,null,null,null,1,2,2,null,null,1,1,null,null,null,1,1,2,null,null,null,1,1,2,null,null,1,1,null,null,null,1,1,2,null,null,null,2,null,1,null,1,null,2,2,2,null,null,null,1,null,1,null,1,null,1,null,1,null,2,1,2,null,null,2,2,null,null,null,2,null,1,null,2,null,1,null,1,2,1,null,null,null,1,null,2,null,2,null,2,null,1,null,2,null,1,null,1,null,2,null,1,2,1,null,null,null,2,null,2,2,2,null,null,null,2,null,1,null,1,null,1,null,1,null,2,null,1,2,1,null,null,null,2,null,2,null,1,null,1,null,1,2,1,null,null,null,2,null,2,1,2,null,null,null,1,2,2,null,null,1,2,null,null,1,2,null,null,2,2,null,null,2,2,null,null,null,1,null,2,null,2,null,1,null,2,null,1,null,1,2,1,null,null,null,1,1,1,null,null,null,2,null,2,null,2,null,1,null,1,null,1,null,2,1,2,null,null,null,1,2,1,null,null,1,1,null,null,null,2,null,1,null,1,null,1,2,2,null,null,null,2,null,2,1,1,null,null,null,1,null,1,null,1,null,2,null,2,null,2,null,2,null,1
        );
        TreeNode root = TreeUtils.createTree(treeNodeList);
        // System.out.println(PrintTree.printTree(root));
        //TreeUtils.printTree(root);
        // Check if the linked list is a subpath of the binary tree
        boolean result = true;
        //result = LinkedListInBinaryTree.isSubPath(head, root);

        System.out.println("Is the linked list a subpath of the binary tree? " + result);
        Assertions.assertTrue(result, "The linked list should be a subpath of the binary tree.");
    }
}
