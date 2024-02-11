import queue


class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    # set data
    def setData(self, data):
        self.data = data

    # set left child
    def setLeft(self, left):
        self.left = left

    # set right child
    def setRight(self, right):
        self.right = right

    # get data
    def getData(self):
        return self.data

    # get left
    def getLeft(self):
        return self.left

    # get right
    def getRight(self):
        return self.right


class BinaryTree:
    def __init__(self):
        self.root = None

    def m_insert(self, node, data):
        if node is None:
            self.root = TreeNode(data)
        else:
            if (node.getData() > data):
                if (node.getLeft() is None):
                    node.setLeft(TreeNode(data))
                else:
                    self.m_insert(node.getLeft(), data)
            else:
                if (node.getRight() is None):
                    node.setRight(TreeNode(data))
                else:
                    self.m_insert(node.getRight(), data)

    def insert(self, data):
        self.m_insert(self.root, data)

    def inorder(self, node):
        if node is not None:
            self.inorder(node.getLeft())
            print(str(node.getData()), end=" ")
            self.inorder(node.getRight())

    def inorder_traversal(self):
        self.inorder(self.root)

    def preorder(self, node):
        if node is not None:
            print(str(node.getData()), end=" ")
            self.preorder(node.getLeft())
            self.preorder(node.getRight())

    def preorder_traversal(self):
        self.preorder(self.root)

    def postorder(self, node):
        if node is not None:
            self.postorder(node.getLeft());
            self.postorder(node.getRight());
            print(str(node.getData()), end=" ")

    def postorder_traversal(self):
        self.postorder(self.root)

    def levelorder(self, node):
        if self.root is None:
            return
        q = queue.Queue()
        l = []
        q.put(node)
        q.put(None)

        temp = None
        while not q.empty():
            temp = q.get()

            if temp is not None:
                l.append(temp.getData())
                if temp.getLeft() is not None:
                    q.put(temp.getLeft());
                if temp.getRight() is not None:
                    q.put(temp.getRight());
            else:
                if not q.empty():
                    q.put(None)

        for items in l:
            print(items, end=" ")

    def levelorder_traversal(self):
        self.levelorder(self.root)

    def m_search(self, node, data):
        if node is None:
            return False
        if node.getData() > data:
            return self.m_search(node.getLeft(), data)
        elif node.getData() < data:
            return self.m_search(node.getRight(), data)
        else:
            return True

    def search(self, data):
        return self.m_search(self.root, data)

    def m_size(self, node):
        if node is None:
            return 0
        leftsize = self.m_size(node.getLeft())
        rightsize = self.m_size(node.getRight())
        return (1 + leftsize + rightsize)

    def size(self):
        return m_size(self, self.root)

    def m_minimum(self, node):
        if node is None:
            return None
        while node.getLeft() is not None:
            node = node.getLeft()
        return node.getData()

    def minimum(self):
        node = self.root;
        return self.m_minimum(node);

    def maximum(self):
        node = self.root
        if node is None:
            return None
        while node.getRight() is not None:
            node = node.getRight()
        return node.getData()

    def m_remove(self, node, data):
        if node is None:
            return None
        if node.getData() < data:
            node.right = self.m_remove(node.getRight(), data);
        elif node.getData() > data:
            node.left = self.m_remove(node.getLeft(), data);
        else:
            if node.getLeft() is None:
                temp = node
                node = node.getRight()
                del temp
            elif node.getRight() is None:
                temp = node
                node = node.getLeft()
            else:
                temp = self.m_minimum(node.getRight())
                node.setData(temp.getData())
                self.m_remove(node.getRight(), temp.getData());

    def remove(self, data):
        return self.m_remove(self.root, data)


def main():
    BST = BinaryTree()
    arr = [45, 30, 60, 20, 40, 10, 5, 15, 50, 48, 55, 80, 100, 90, 120]
    for items in arr:
        BST.insert(items)

    "--------------------------Traversal Test-----------------------------"
    print("Inorder Traversal ")
    BST.inorder_traversal()
    print()
    print("LevelOrder Traversal ")
    BST.levelorder_traversal()
    print()
    print("Preorder Traversal ")
    BST.preorder_traversal()
    print()
    print("Postorder Traversal ")
    BST.postorder_traversal()
    print()
    "----------------------------Minumum & Maximum Test-------------------"
    print("maximum")
    print(BST.maximum(), " ")
    print()
    print("minimum")
    print(BST.minimum(), " ")
    print()
    "----------------------------Search Test------------------------------"
    data = 45
    print("Search for ", data)
    print(BST.search(data))
    data = 70
    print("Search for ", data)
    print(BST.search(data))
    "----------------------------Deletion Test-----------------------------"
    Removal_list = [45, 20, 80, 90]
    for items in Removal_list:
        data = items;
        node = BST.remove(data)
        print("Data Removed : ", data, " and Root now : ", node.getData());
        print("Inorder Traversal ")
        BST.inorder_traversal()
        print()
        print("LevelOrder Traversal ")
        BST.levelorder_traversal()
        print()
        print("Preorder Traversal ")
        BST.preorder_traversal()
        print()
        print("Postorder Traversal ")
        BST.postorder_traversal()
        print()
        print("maximum")
        print(BST.maximum(), " ")
        print()
        print("minimum")
        print(BST.minimum(), " ")
        print()

    "------------------------------Search Test-------------------------------"
    Search_List = [45, 100, 120, 60]
    for items in Search_List:
        data = items
        print("Search for ", data)
        print(BST.search(data))


if __name__ == '__main__':
    main()
