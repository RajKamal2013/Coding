from typing import Optional

from src.Practice.ds.tree_node import TreeNode


class BinaryTreePruning:

    @staticmethod
    def prune_tree(root:Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return None
        root.left = BinaryTreePruning.prune_tree(root.left)
        root.right = BinaryTreePruning.prune_tree(root.right)

        if root.left is None and root.right is None and root.val != 1:
            root = None
            return root

        return root




