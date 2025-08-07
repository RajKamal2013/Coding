from src.Practice.ds.list_node import ListNode


class ListUtils:
    @staticmethod
    def create_list(arr: list) -> ListNode:
        """
        Create a list from an array.

        :param arr: List of elements to create the list from.
        :return: A new list containing the elements of the array.
        """
        if not arr:
            return None
        head = ListNode(arr[0])
        current = head
        for value in arr[1:]:
            current.next = ListNode(value)
            current = current.next
        return head

    @staticmethod
    def print_list(head: ListNode) -> None:
        """
        Print the elements of the list.

        :param head: The head of the list to print.
        """
        current = head
        while current:
            print(current.val, end=" -> ")
            current = current.next
        print("None")