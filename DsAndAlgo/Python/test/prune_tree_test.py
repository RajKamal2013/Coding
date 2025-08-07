import unittest

from src.Practice.ds.tree_node import TreeNode
from src.Practice.src.binary_tree_pruning import BinaryTreePruning
from src.Practice.util.binary_tree_utils import BinaryTreeUtils


class PruneTreeTest(unittest.TestCase):

    def test_prune_tree(self):
        validator = BinaryTreePruning()
        binaryTreeUtils = BinaryTreeUtils()

        print(" --------------- Test 1 ----------------------")
        arr = [1, "null", 0, 0, 1]
        expected = [1, "null", 0, "null", 1]
        root:TreeNode = binaryTreeUtils.create_tree(arr)
        print("---------Printing Tree created ------------")
        binaryTreeUtils.print_tree(root)

        validated_root = validator.prune_tree(root)
        print("--------Printing Validated Tree created-------")
        binaryTreeUtils.print_tree(validated_root)

        actual = binaryTreeUtils.level_order_print(validated_root)


        for i in range(len(expected)):
            self.assertEqual(actual[i], expected[i])
        print()


        print(" --------------- Test 2 ----------------------")
        arr = [1, 1, 0, 1, 1, 0, 1, 0]
        expected  = [1, 1, 0, 1, 1, "null", 1]
        root: TreeNode = binaryTreeUtils.create_tree(arr)
        print("---------Printing Tree created ------------")
        binaryTreeUtils.print_tree(root)

        validated_root = validator.prune_tree(root)
        print("--------Printing Validated Tree created-------")
        binaryTreeUtils.print_tree(validated_root)

        actual = binaryTreeUtils.level_order_print(validated_root)

        for i in range(len(expected)):
            self.assertEqual(actual[i], expected[i])
        print()

        print(" --------------- Test 3 ----------------------")
        arr = [1, "null", 0, 0, 1]
        expected = [1, "null", 0, "null", 1]
        root: TreeNode = binaryTreeUtils.create_tree(arr)
        print("---------Printing Tree created ------------")
        binaryTreeUtils.print_tree(root)

        validated_root = validator.prune_tree(root)
        print("--------Printing Validated Tree created-------")
        binaryTreeUtils.print_tree(validated_root)

        actual = binaryTreeUtils.level_order_print(validated_root)

        for i in range(len(expected)):
            self.assertEqual(actual[i], expected[i])
        print()