import unittest

from src.Practice.ds.list_node import ListNode
from src.Practice.ds.tree_node import TreeNode
from src.Practice.src.linkedlist_in_binary_tree import LinkedListInBinaryTree


class LinkedListInBinaryTreeTest(unittest.TestCase):
    def test_linked_list_in_binary_tree(self):

        # Create a binary tree
        root: TreeNode = TreeNode(1)
        root.left = TreeNode(2)
        root.right = TreeNode(3)
        root.left.left = TreeNode(4)
        root.left.right = TreeNode(5)

        # Create a linked list
        linked_list:ListNode = ListNode(1)
        linked_list.next = ListNode(2)
        linked_list.next.next = ListNode(4)

        # Check if the linked list is present in the binary tree
        self.assertTrue(LinkedListInBinaryTree.is_sub_path(linked_list, root))

        # Create another linked list that is not present in the binary tree
        linked_list_not_present = ListNode(3)
        linked_list_not_present.next = ListNode(6)

        # Check if the second linked list is present in the binary tree
        self.assertFalse(LinkedListInBinaryTree.is_sub_path(linked_list_not_present, root))