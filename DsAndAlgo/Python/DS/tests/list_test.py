from DS.list.linked_list import LinkedList


def LinkedListTest():
    list = LinkedList()
    for i in range(10):
        list.append(i)

    for item in list:
        print(item, end=" ")

    print("\n")
    print(list)
    list.reverse()
    list.display()
    print(list.contains(1))


def main():
    LinkedListTest()


main()
