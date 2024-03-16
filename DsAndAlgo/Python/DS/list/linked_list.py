from DS.list.node import Node


class LinkedList:
    def __init__(self, data=None):
        if data is None:
            self.head = None
        else:
            self.head = Node(data)

    def __iter__(self):
        curr = self.head
        while curr:
            yield curr.data
            curr = curr.next

    def __len__(self) -> int:
        return len(tuple(iter(self)))

    def __repr__(self):
        return "->".join([str(item) for item in self])

    def __getitem__(self, idx):
        if not 0 <= idx < len(self):
            raise IndexError("List Index out of range")
        for i, node in enumerate(self):
            if i == idx:
                return node

    def __setitem__(self, idx, data):
        if not 0 <= idx < len(self):
            raise IndexError("List Index out of range")
        curr = self.head
        for i in range(idx):
            curr = curr.next
        curr.data = data

    def insert_nth(self, idx, data):
        if not 0 <= idx < len(self) + 1:
            raise IndexError("List Index out of range")

        newNode = Node(data)
        if self.head is None:
            self.head = newNode
        elif idx == 0:
            newNode.next = self.head
            self.head = newNode
        else:
            temp = self.head
            for _ in range(idx - 1):
                temp = temp.next
            newNode.next = temp.next
            temp.next = newNode

    def prepend(self, data):
        self.insert_nth(0, data)

    def append(self, data):
        newNode = Node(data)
        if self.head is None:
            self.head = newNode
        else:
            curr = self.head
            while curr.next is not None:
                curr = curr.next
            curr.next = newNode
        newNode.next = None

    def display(self):
        print(self)

    def remove_nth(self, idx):
        if not 0 <= idx < len(self):
            raise IndexError(":List:Index out of bound")

        deleteNode = self.head
        if idx == 0:
            self.head = self.head.next
        else:
            curr = self.head
            for _ in range(idx - 1):
                curr = curr.next
            deleteNode = curr.next
            curr.next = curr.next.next

        deleteNode.next = None
        return deleteNode.data

    def removeFront(self):
        data = self.remove_nth(0)
        return data

    def removeLast(self):
        return self.remove_nth(len(self) - 1)

    def is_Empty(self) -> bool:
        return self.head is None

    def contains(self, data) -> bool:
        curr = self.head
        while curr is not None:
            if curr.data == data:
                return True
            curr = curr.next
        return False

    def reverse(self):
        curr = self.head
        temp = None
        rev = None
        while curr is not None:
            temp = curr.next
            curr.next = rev
            rev = curr
            curr = temp
        self.head = rev
