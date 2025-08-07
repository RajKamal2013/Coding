from collections import deque

from src.Practice.ds.tree_node import TreeNode


class TreeUtils:

    @staticmethod
    def create_tree(arr) -> TreeNode | None:
        if len(arr) == 0:
            return None
        root = TreeNode(arr[0])
        queue = deque()
        queue.append(root)
        i = 1
        while i < len(arr):
            node = queue.popleft()
            if arr[i] != "null":
                node.left = TreeNode(arr[i])
                queue.append(node.left)
            i = i + 1
            if i < len(arr) and arr[i] != "null":
                node.right = TreeNode(arr[i])
                queue.append(node.right)
            i = i + 1

        return root

    @staticmethod
    def level_order_print(root):
        if root is None:
            return
        queue = deque()
        queue.append(root)
        while queue:
            level_size = len(queue)
            for _ in range(level_size):
                node = queue.popleft()
                print(node.val, end=" ")
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)

    @staticmethod
    def get_height(node):
        if node is None:
            return 0
        return max(TreeUtils.get_height(node.left), TreeUtils.get_height(node.right)) + 1

    @staticmethod
    def inorder_print(root):
        if root is None:
            return
        TreeUtils.inorder_print(root.left)
        print(root.val, end=" ")
        TreeUtils.inorder_print(root.right)

    @staticmethod
    def preorder_print(root):
        if root is None:
            return
        print(root.val, end=" ")
        TreeUtils.preorder_print(root.left)
        TreeUtils.preorder_print(root.right)


    @staticmethod
    def create_row(node: TreeNode, height: int, row: int, column: int, matrix: list[list[str]]):
        if (node.left is None) and (node.right is None):
            return
        if node.left is not None:
            r = row + 1
            c = column - 2 ** (height - row)
            matrix[r][c] = str(node.left.val)
            TreeUtils.create_row(node.left, height, r, c, matrix)
        if node.right is not None:
            r = row + 1
            c = column + 2 ** (height - row)
            matrix[r][c] = str(node.right.val)
            TreeUtils.create_row(node.right, height, r, c, matrix)

    @staticmethod
    def get_tree_node_matrix(root) -> list[list[str]]:
        def height(node):
            if node is None:
                return 0
            return max(height(node.left), height(node.right)) + 1

        def update_matrix(node, r, left, right):
            if not node:
                return
            mid = (right + left) // 2
            tree_matrix[r][mid] = str(node.val)
            #print(tree_matrix)
            if node.left is not None:
                update_matrix(node.left, r + 1, left, mid - 1)
            if node.right is not None:
                update_matrix(node.right, r + 1, mid + 1, right)

        if root is None:
            return [[]]

        if root.left is None and root.right is None:
            mat = [[str(root.val)]]
            return mat

        tree_height = height(root)
        row = tree_height
        col = (2 ** tree_height) - 1
        default_value: str = ""
        tree_matrix: list[list[str]] = [[default_value for _ in range(col)] for _ in range(row)]
        update_matrix(root, 0, 0, col - 1)
        return tree_matrix

    @staticmethod
    def print_tree(root) -> None:
        """
        Returns a matrix representation of the tree for printing.
        """
        tree_matrix:list[list[str]]  = TreeUtils.get_tree_node_matrix(root)
        for row in tree_matrix:
            for data in row:
                print(data + " ")
            print()