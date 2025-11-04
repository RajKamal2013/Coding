package org.patterns;

import org.practice.ListNode;

public class InPlaceManipulation {
    public static ListNode swapPairs(ListNode head) {
        ListNode prev, curr, currNext, temp;

        curr = head;
        prev = currNext = temp = null;

        while (curr != null) {
            if (curr.next == null) { break;}
            currNext = curr.next;
            temp = currNext.next;
            currNext.next = curr;
            curr.next = temp;
            if (prev == null) {
                head = currNext;
            } else {
                prev.next = currNext;
            }
            prev = curr;
            curr = curr.next;
        }
        // Replace this placeholder return statement with your code
        return head;
    }

    /*
     * Reverse the list between left and right
     * 0->1->2->3->4 L-> 1, R->3
     * 0->3->2->1->4
     */
    public static ListNode reverseBetween(ListNode head, int left, int right)
    {
        if (head == null) { return head;}
        if (left == right) { return head;}
        ListNode leftNode, rightNode, leftPrev, rightNext;
        leftNode = rightNode = leftPrev = rightNext = null;

        ListNode curr = head;
        ListNode prev = null;

        int idx = 1;
        while (curr != null) {
            if (idx == left) {
                leftNode = curr;
                leftPrev = prev;
            }
            if (idx == right) {
                rightNode = curr;
                rightNext = curr.next;
            }
            idx = idx + 1;
            prev = curr;
            curr = curr.next;
        }

        if (leftNode == null || rightNode == null) {
            return head;
        }

        ListNode rev, temp;
        rev = null;

        curr = leftNode;

        while(curr != rightNext) {
            temp = curr.next;
            if (rev == null) {
                rev = curr;
            } else {
                curr.next = rev;
                rev = curr;
            }
            curr  = temp;
        }

        if (leftPrev != null) {
            leftPrev.next = rev;
        } else {
            head = rev;
        }
        leftNode.next = rightNext;

        return head;
    }

    /*
     * Given the head of a singly linked list, reorder the list as if it were folded on itself.
     * Input:
     *  Lo->L1->L2->L3-> ...... ->Ln-3->Ln-2->Ln-1->Ln
     * Output:
     *  Lo->Ln->L1->Ln-1->L2->Ln-2->....
     */
    public static ListNode reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        /* Split list into 2 halves */
        ListNode firstHalf = null;
        ListNode secondHalf = null;
        int size = 0;
        ListNode curr = head;
        while(curr != null) {
            curr=curr.next;
            size = size + 1;
        }

        ListNode tail = null;
        int mid = size/2 - 1;
        boolean isOdd = (size % 2 != 0);

        firstHalf = head;
        curr = head;
        ListNode prev = null;
        for (int i = 0; i <= mid; i++) {
            prev = curr;
            curr = curr.next;
        }
        if (prev != null) {
            prev.next = null;
        }

        ListNode lastNode = null;
        if (isOdd) {
            lastNode = curr;
            curr = curr.next;
            lastNode.next = null;
        }

        /* Reverse the second half */
        ListNode rev, temp;
        rev = temp = null;
        while (curr != null) {
            temp = curr.next;
            if (rev != null) {
                curr.next = rev;
            } else {
                curr.next = null;
            }
            rev = curr;
            curr = temp;
        }
        secondHalf = rev;

        /* Merge the two list by manipulating next */
        ListNode firstHalfCurr, secondHalfCurr, temp1, temp2;
        firstHalfCurr = firstHalf;
        secondHalfCurr = secondHalf;

        while (firstHalfCurr != null && secondHalfCurr != null) {
            temp1 = firstHalfCurr.next;
            temp2 = secondHalfCurr.next;

            firstHalfCurr.next = secondHalfCurr;
            secondHalfCurr.next = temp1;
            prev = secondHalfCurr;
            firstHalfCurr = temp1;
            secondHalfCurr = temp2;
        }
        if (lastNode != null && prev != null) {
            prev.next = lastNode;
        }
        return head;
    }

    // Better approach from solution
    public static ListNode optimizedReorderList(ListNode head)
    {
        if(head == null)
            return head;
        // find the middle of linked list
        // in 1->2->3->4->5->6 find 4
        ListNode slow = head;
        ListNode fast = head;

        while(fast!= null && fast.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        // reverse the second part of the list
        // convert 1->2->3->4->5->6 into 1->2->3 and 6->5->4
        // reverse the second half in-place
        ListNode prev = null;
        ListNode curr = slow;
        ListNode next = null;

        while(curr != null)
        {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        // merge two sorted linked lists
        // merge 1->2->3 and 6->5->4 into 1->6->2->5->3->4
        ListNode first = head;
        ListNode second = prev;
        ListNode temp = head;

        while(second.next != null)
        {
            temp = temp.next;
            first.next = second;
            second = second.next;
            first.next.next = temp;
            first = first.next.next;
        }

        return head;
    }
}
