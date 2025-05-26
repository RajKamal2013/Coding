package org.practice;

import org.checkerframework.checker.units.qual.A;

import java.util.*;

public class PrintTree {

    public static TreeNode createTree(List<Integer> arr) {
        if (Collections.emptyList().equals(arr)) {
            return null;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        int i  = 0;
        TreeNode root = new TreeNode(arr.get(i));
        queue.add(root);
        i = 1;
        while (i < arr.size()) {
            TreeNode node = queue.poll();
            if (arr.get(i) != null) {
                node.left = new TreeNode(arr.get(i));
                queue.add(node.left);
            }
            i = i + 1;
            if (i < arr.size()) {
                if (arr.get(i) != null) {
                    node.right = new TreeNode(arr.get(i));
                    queue.add(node.right);
                }
                i = i + 1;
            }
        }
        return root;
    }

    public  static void printLevelOrder(TreeNode root) {
        if (root == null) {
            return;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int levelSize;
        while (!queue.isEmpty()) {
            levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();
                System.out.print(node.val + " ");
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
        }
    }

    public static void printInOrder(TreeNode root) {
        if (root == null) {
            return;
        }
        printInOrder(root.left);
        System.out.print(root.val + " ");
        printInOrder(root.right);
    }

    public static void printPostOrder(TreeNode root) {
        if (root == null) {
            return;
        }
        printPostOrder(root.left);
        printPostOrder(root.right);
        System.out.print(root.val + " ");
    }

    public static void printPreOrder(TreeNode root) {
        if (root == null) {
            return;
        }
        System.out.print(root.val + " ");
        printPreOrder(root.left);
        printPreOrder(root.right);
    }

    public static int getHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int leftHeight = getHeight(root.left);
        int rightHeight = getHeight(root.right);
        return Math.max(leftHeight, rightHeight) + 1;
    }

    public static void fillMatrix(List<List<String>> matrix, TreeNode node, int row, int left, int right) {
        if (node == null) {
            return;
        }
        int mid = (left + right) / 2;
        matrix.get(row).set(mid, String.valueOf(node.val));
        //matrix.get(row).set(mid, String.valueOf(node.val));
        fillMatrix(matrix, node.left, row + 1, left, mid - 1);
        fillMatrix(matrix, node.right, row + 1, mid + 1, right);
    }

    public static List<List<String>> printTree(TreeNode root) {
        if (root == null) {
            return Collections.emptyList();
        }
        if (root.left == null && root.right == null) {
            List<List<String>> matrix = new ArrayList<>();
            matrix.add(new ArrayList<>());
            matrix.get(0).add(String.valueOf(root.val));
            return matrix;
        }
        int height = getHeight(root);
        int col = (1 << height) - 1;
        List<List<String>> matrix = new ArrayList<>();
        String defaultValue = "";
        for (int i = 0; i < height; i++) {
            List<String> row = new ArrayList<>();
            for (int j = 0; j < col; j++) {
                row.add(defaultValue);
            }
            matrix.add(row);
        }
        fillMatrix(matrix, root, 0, 0, col - 1);
        return matrix;
    }
}
