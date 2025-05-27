class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def height(self, root):
        if root is None:
            return 0
        return max(self.height(root.left), self.height(root.right)) + 1

