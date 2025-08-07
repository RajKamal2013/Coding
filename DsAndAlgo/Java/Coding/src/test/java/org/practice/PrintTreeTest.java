package org.practice;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class PrintTreeTest {

    private PrintTree printTree;

    @BeforeEach
    void setUp() {
        //printTree = new PrintTree();
    }

    @Test
    void setPrintTree() {

    }

    @Test
    void testPrintTreeWithNullRoot() {
        TreeNode root = null;
        List<List<String>> result = PrintTree.printTree(root);
        assertTrue(result.isEmpty(), "Expected an empty list for a null root");
    }

    @Test
    void testPrintTreeWithSingleNode() {
        TreeNode root = new TreeNode(1);
        List<List<String>> result = PrintTree.printTree(root);
        assertEquals(1, result.size(), "Expected a single row for one node");
        assertEquals("1", result.get(0).get(0), "The single node's value should be correctly placed");
    }

    @Test
    void testPrintTreeWithMultipleLevels() {
        TreeNode root = TreeUtils.createTree(Arrays.asList(1, 2, 3, 4, 5, null, 6));
        TreeUtils.printLevelOrder(root);
        List<List<String>> result = PrintTree.printTree(root);
        assertEquals(3, result.size(), "Expected three levels in the tree");
        assertEquals("1", result.get(0).get(3), "The root node should be correctly placed at the center");
        assertEquals("2", result.get(1).get(1), "The left child of the root should be correctly placed");
        assertEquals("3", result.get(1).get(5), "The right child of the root should be correctly placed");
        assertEquals("4", result.get(2).get(0), "The leftmost child node should be correctly placed");
        assertEquals("6", result.get(2).get(6), "The rightmost child node should be correctly placed");
    }

    @Test
    void testPrintTreeTest() {

        String[][] expectedArray = {{"", "", "", "1", "", "", ""}, {"", "2", "", "", "", "3", ""}, {"", "", "4", "", "", "", ""}};
        List<List<String>> expected = new ArrayList<>();
        for (String[] row : expectedArray) {
            expected.add(Arrays.asList(row));
        }
        List<Integer> input = Arrays.asList(1, 2, 3, null, 4);
        TreeNode root = TreeUtils.createTree(input);
        List<List<String>> result = PrintTree.printTree(root);
        assertEquals(expected, result, "The tree should be printed correctly");
    }
}
