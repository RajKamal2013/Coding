package org.practice;

import java.util.*;

public class PrintTree {


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
        int height = TreeUtils.getHeight(root);
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
