from typing import Optional

from src.Practice.ds.list_node import ListNode
from src.Practice.ds.tree_node import TreeNode


class LinkedListInBinaryTree:

  @staticmethod
  def dfs_vist(head: Optional[ListNode], root: Optional[TreeNode]) -> bool:

        """
        Check if the linked list is equal to the path in the binary tree.

        :param head: The head of the linked list.
        :param root: The current node in the binary tree.
        :return: True if the linked list is equal to the path in the binary tree, False otherwise.
        """
        if not head:
            return True
        if not root:
            return False
        if head.val != root.val:
            return False
        return (LinkedListInBinaryTree.dfs_vist(head.next, root.left) or
                LinkedListInBinaryTree.dfs_vist(head.next, root.right))

  @staticmethod
  def is_sub_path(head: Optional[ListNode], root: Optional[TreeNode]) -> bool:

        """
        Check if a linked list is a subpath in a binary tree.

        :param head: The head of the linked list.
        :param root: The root of the binary tree.
        :return: True if the linked list is a subpath in the binary tree, False otherwise.
        """
        if not head:
            return True
        if not root:
            return False
        if LinkedListInBinaryTree.dfs_vist(head, root):
            return True
        return (LinkedListInBinaryTree.is_sub_path(head, root.left) or
                LinkedListInBinaryTree.is_sub_path(head, root.right))