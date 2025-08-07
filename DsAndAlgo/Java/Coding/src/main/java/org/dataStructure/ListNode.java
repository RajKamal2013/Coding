package org.dataStructure;

public class ListNode<T> {
    private T data;
    private ListNode next;
    private ListNode prev;

    String fileName  = new Throwable().getStackTrace()[0].getFileName();

    public ListNode () {
        this.data = null;
        this.next = null;
    }
    public ListNode (T data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }

    public ListNode (T data, ListNode<T> next, ListNode<T> prev) {
        this.data = data;
        this.next = next;
        this.prev = prev;
    }
    public ListNode(T data, ListNode<T> next) {
        this.data  = data;
        this.next  = next;
        this.prev = null;
    }

    public void setData(T data) {
        if (data == null) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "Data is null. Node is dummy filled";
            globals.LogWarning(1, currentLine, fileName, warning);
        }
        this.data = data;
    }

    public T getData() {
        if (this.data == null) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning  = "Data is Null, Fill the data at line ";
            globals.LogError(1, currentLine, fileName, warning);
            return null;
        } else {
            return this.data;
        }
    }
    public void setNext(ListNode<T> next) {
        this.next = next;
    }

    public ListNode<T> getNext() {
        return  this.next;
    }

    public void setPrev(ListNode<T> next) {
        this.prev = next;
    }

    public ListNode<T> getPrev() {
        return  this.prev;
    }

    public String toString() {
        return this.data.toString();
    }
}
