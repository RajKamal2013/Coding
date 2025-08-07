import unittest

from src.Practice.src.print_tree import PrintTree


class PrintTreeTest(unittest.TestCase):
    def test_printTree(self):
        print_tree = PrintTree()
        print("---- Test Case 1 -------")
        arr = [1, 2]
        expected = [["", "1", ""],["2", "", ""]]
        tree = print_tree.create_tree(arr)
        print_tree.level_order_print(tree)
        print()
        actual = print_tree.print_tree(tree)
        for i in range(len(expected)):
            self.assertEqual(actual[i],expected[i])

        print("---- Test Case 2 -------")
        arr = [1, 2, 3, "null", 4]
        expected = [["", "", "", "1", "", "", ""],["", "2", "", "", "", "3", ""],["", "", "4", "", "", "", ""]]
        tree = print_tree.create_tree(arr)
        #print_tree.level_order_print(tree)
        #print()
        #print_tree.inorder_print(tree)
        #print()
        #print_tree.preorder_print(tree)
        #print()
        actual = print_tree.print_tree(tree)
        print(actual)
        print()
        for i in range(len(expected)):
            self.assertEqual(actual[i], expected[i])



if __name__ == '__main__':
    unittest.main()