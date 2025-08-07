package org.practice;

public class ListUtils {
    public static ListNode createList(int[] arr) {
        if (arr == null || arr.length == 0) {
            return null;
        }
        ListNode head = new ListNode(arr[0]);
        ListNode current = head;
        for (int i = 1; i < arr.length; i++) {
            current.next = new ListNode(arr[i]);
            current = current.next;
        }
        return head;
    }

    public static void printList(ListNode head) {
        ListNode current = head;
        System.out.println("------------Linked List-------------");
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.next;
        }
        System.out.println();
    }
    public static void printListVertical(ListNode head) {
        ListNode current = head;
        System.out.println("------------Linked List-------------");
        while (current != null) {
            System.out.println(current.val);
            current = current.next;
        }
        System.out.println();
    }
}
