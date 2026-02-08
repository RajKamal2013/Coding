package org.patterns;

import org.patterns.TreeNode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Backtracking {

    public static boolean wordSearch(char[][] grid, String word) {

        if (grid.length == 0 || word == null || word.isEmpty()) {
            return false;
        }
        StringBuilder builder = new StringBuilder();
        boolean ret;
        int index = 0;
        int m = grid.length;
        int n = grid[0].length;
        boolean [][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                //builder = new StringBuilder();
                ret = wordSearchBacktracking(grid, word, index, i, j, visited);
                if (ret) {
                    return ret;
                }
            }
        }
        return false;
    }

    public static boolean wordSearchBacktracking(char[][] grid, String word, int index, int row, int col, boolean[][] visited) {
        if (word.length() == index) { return true; }

        if (row < 0 || row >= grid.length || col < 0 || col > grid[row].length || visited[row][col] ||
                Character.toLowerCase(word.charAt(index)) != Character.toLowerCase(grid[row][col])) {
            return false;
        }

        visited[row][col] = false;
        boolean ret = false;
        int[][] offsets = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int[] offset: offsets) {
            ret = wordSearchBacktracking(grid, word, index + 1, row + offset[0], col + offset[1], visited);
            if (ret) { break; }
        }
        visited[row][col] = false;
        return ret;
    }

    public static boolean wordSearchBacktracking1(char[][] grid, String word, StringBuilder builder, int i, int j) {
        if (i >= grid.length || j >= grid[i].length) { return false; }
        if (builder.length() > word.length()) { builder.setLength(0); }
        System.out.println("----------------------"  + builder);
        if (builder.length() == word.length() && builder.toString().equalsIgnoreCase(word)) { return true;}

        if (!builder.isEmpty() &&
                Character.toLowerCase(builder.charAt(builder.length() - 1)) !=
                        Character.toLowerCase(word.charAt(builder.length() - 1))) {
               builder.setLength(0);
        }
        builder.append(grid[i][j]);

        boolean ret = wordSearchBacktracking1(grid, word, new StringBuilder(builder), i + 1, j) ||
                wordSearchBacktracking1(grid, word, new StringBuilder(builder), i, j + 1);

        return ret;

    }

    public static int rob(TreeNode<Integer> root) {

        if (root == null) { return -1;}
        if (root.left == null && root.right == null) { return root.data;}

        Map<TreeNode<Integer>, Integer[]> memo = new HashMap<>();
        int maxSum = Math.max(robBacktracking(root, 0, true, memo), robBacktracking(root, 0, false, memo));
        return maxSum;
    }

    public static int robBacktracking(TreeNode<Integer> node, int sum, Boolean include, Map<TreeNode<Integer>, Integer[]> memo) {
        if (node == null) { return 0;}
        if (memo.containsKey(node) && memo.get(node)[include ? 1 : 0] != null) {
            return memo.get(node)[include ? 1 : 0];
        }
        int maxSum = 0;
        if (include) {
            int sumExcludeLeft = robBacktracking(node.left, sum, false, memo);
            int sumExcludeRight = robBacktracking(node.right, sum, false, memo);
            maxSum = sum + node.data + sumExcludeRight + sumExcludeLeft;
        } else {
            int sumIncludeLeft = robBacktracking(node.left, sum, true, memo);
            int sumExcludeLeft = robBacktracking(node.left, sum, false, memo);
            int sumIncludeRight = robBacktracking(node.right, sum, true, memo);
            int sumExcludeRight = robBacktracking(node.right, sum, false, memo);

            maxSum =  Math.max(sumIncludeRight + sumIncludeLeft, Math.max(sumIncludeLeft + sumExcludeRight, sumIncludeRight + sumExcludeLeft));
            maxSum = Math.max(maxSum, sumExcludeLeft + sumExcludeRight);
        }

        memo.computeIfAbsent(node, k -> new Integer[2])[include ? 1 : 0] = maxSum;
        return maxSum;
    }

    public static List<String> restoreIpAddresses(String s) {
        if (s == null || s.isEmpty()) {
            return new ArrayList<String>();
        }
        StringBuilder builder = new StringBuilder();
        List<String> ipAddresses = generateIpAddresses(s, builder, 0, 3);
        // Replace this placeholder return statement with your code
        return ipAddresses;
    }

    public static List<String> generateIpAddresses(
            String str, StringBuilder builder, int currentIdx, int remainingDots) {
        if (str.isEmpty() || currentIdx >= str.length()) {
            return null;
        }
        int remainingLength = str.length() - currentIdx;
        switch (remainingDots) {
            case 3 -> {
                if (remainingLength > 12) {
                    return new ArrayList<String>();
                }
            }
            case 2 -> {
                if (remainingLength < 3 || remainingLength > 9) {
                    return null;
                }
            }
            case 1 -> {
                if (remainingLength < 2 || remainingLength > 6) {
                    return null;
                }
            }
            case 0 -> {
                if (remainingLength < 1 || remainingLength > 3) {
                    return null;
                }
                if ((remainingLength > 1) && (str.substring(currentIdx).startsWith("0"))) {
                    return null;
                }
                if ((remainingLength == 3) && (Integer.parseInt(str.substring(currentIdx, currentIdx + 3)) > 255)) {
                    return null;
                }
            }
        }

        List<String> ipAddresses = new ArrayList<>();
        if (remainingDots == 0) {
            builder.append(str.substring(currentIdx));
            ipAddresses.add(builder.toString());
            return ipAddresses;
        }

        List<String> ipAddresses1, ipAddresses2, ipAddresses3;
        ipAddresses1 = ipAddresses2 = ipAddresses3 = null;
        StringBuilder builder1 = new StringBuilder(builder);
        builder1.append(str.charAt(currentIdx));
        builder1.append(".");
        ipAddresses1 = generateIpAddresses(str, builder1, currentIdx + 1, remainingDots - 1);
        if (str.charAt(currentIdx) != '0') {
            if (currentIdx + 1 <= str.length() - 1) {
                StringBuilder builder2 = new StringBuilder(builder);
                builder2.append(str.charAt(currentIdx));
                builder2.append(str.charAt(currentIdx + 1));
                builder2.append(".");
                ipAddresses2 =
                        generateIpAddresses(str, builder2, currentIdx + 2, remainingDots - 1);
            }
            if (currentIdx + 2 <= str.length() - 1) {
                String str1 = str.substring(currentIdx, currentIdx + 3);
                if (Integer.parseInt(str1) <= 255) {
                    StringBuilder builder3 = new StringBuilder(builder);
                    builder3.append(str.charAt(currentIdx));
                    builder3.append(str.charAt(currentIdx + 1));
                    builder3.append(str.charAt(currentIdx + 2));
                    builder3.append(".");
                    ipAddresses3 =
                            generateIpAddresses(str, builder3, currentIdx + 3, remainingDots - 1);
                }
            }
        }

        if (ipAddresses1 != null) {
            ipAddresses.addAll(ipAddresses1);
        }
        if (ipAddresses2 != null) {
            ipAddresses.addAll(ipAddresses2);
        }
        if (ipAddresses3 != null) {
            ipAddresses.addAll(ipAddresses3);
        }
        return ipAddresses;
    }
}
