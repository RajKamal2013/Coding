package org.dataStructure;

public class DLL<T> {
    private ListNode<T> head;
    private int len;
    String fileName  = new Throwable().getStackTrace()[0].getFileName();

    public DLL () {
        this.head = null;
        this.len = 0;
    }

    public DLL (DLL<T> list) {
        this.head  = list.head;
        this.len = list.len;
    }

    public void append(T data) {
        ListNode<T> newNode = new ListNode<>(data);
        ListNode<T> nodeItr = this.head;

        if (this.head == null) {
            this.head  = newNode;
            this.len = 1;
            return;
        }

        while(nodeItr.getNext() != null) {
            nodeItr = nodeItr.getNext();
        }

        nodeItr.setNext(newNode);
        newNode.setPrev(nodeItr);
        newNode.setNext(null);

        this.len = this.len + 1;
    }

    public void append(DLL<T> list) {
        if (list == null) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "NULL list is passed to append ";
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }

        if (list.head == null) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "list with no data is passed to append ";
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }

        if (this.head == null) {
            this.head = list.head;
            this.len = list.len;
            return;
        }

        ListNode<T> nodeItr = this.head;

        while(nodeItr.getNext() != null) {
            nodeItr = nodeItr.getNext();
        }

        nodeItr.setNext(list.head);
        list.head.setPrev(nodeItr);
        this.len = this.len + list.len;
    }

    public void insert(T data) {
        ListNode<T> newNode = new ListNode<T>(data);

        if (this.head == null) {
            this.head = newNode;
            this.len = 1;
            return;
        }

        newNode.setNext(this.head);
        this.head.setPrev(newNode);
        this.head = newNode;
        this.len  = this.len + 1;
    }

    public void insert(DLL<T> list) {
        if (list == null) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "Null List  is passed to insert ";
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }

        if (list.head == null) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "list with no data is passed to insert ";
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }

        if (this.head == null) {
            this.head = list.head;
            this.len = list.len;
            return;
        }

        ListNode<T> nodeItr = list.head;
        while(nodeItr.getNext() != null) {
            nodeItr = nodeItr.getNext();
        }

        nodeItr.setNext(this.head);
        this.head.setPrev(nodeItr);
        this.head = list.head;
        this.len = this.len + list.len;
        return;
    }

    /* add function -> insertAfter, insertBefore */
    public String toString() {
        String res = "[";
        if (this.head == null) {
            res = res + "]";
            return res;
        }
        res = res + this.head.getData();
        ListNode<T> temp = this.head.getNext();
        while(temp != null) {
            res = res + ", " + temp.getData();
            temp = temp.getNext();
        }
        res = res + "]";
        return res;
    }

    public T getData(int pos) {
        if (pos == -1 ) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String error = "invalid index is passed to get data ";
            globals.LogError(1, currentLine, fileName, error);
            return null;
        }

        if (this.len <= pos) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String error = "index out of bound is passed to get data ";
            globals.LogError(1, currentLine, fileName, error);
            return null;
        }

        ListNode<T> nodeItr = this.head;
        int idx = 0;
        while (idx != pos) {
            nodeItr = nodeItr.getNext();
            idx = idx + 1;
        }

        assert(idx == pos);

        return nodeItr.getData();
    }

    public T getFront() {
        if (this.head == null) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "Empty List ";
            globals.LogWarning(1, currentLine, fileName, warning);
            return null;
        }

        return this.head.getData();
    }

    public T getLast() {
        if (this.head == null) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "Empty List ";
            globals.LogWarning(1, currentLine, fileName, warning);
            return null;
        }
        ListNode<T> nodeItr = this.head;

        while (nodeItr.getNext() != null) {
            nodeItr= nodeItr.getNext();
        }

        return nodeItr.getData();
    }

    public boolean contains(T data) {
        if (data == null) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "No data to search ";
            globals.LogWarning(1, currentLine, fileName, warning);
            return false;
        }

        ListNode<T> nodeItr = this.head;
        if (this.head.getData() == data) {
            return true;
        }

        while (nodeItr != null) {
            if (nodeItr.getData() == data) {
                return true;
            }
            nodeItr = nodeItr.getNext();
        }

        return false;
    }

    public boolean isEmpty() {
        if (this.head == null) {
            return true;
        } else {
            return false;
        }
    }

    public void removeFront() {
        if (this.head == null) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "List is empty ";
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }

        ListNode<T> cur = this.head;
        ListNode<T> next = cur.getNext();
        next.setPrev(null);
        this.head = next;
        cur = null;
        return;
    }

    public void removeLast() {
        if (this.head == null) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "List is empty ";
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }

        ListNode<T> prev = this.head;
        ListNode<T> nodeItr = this.head;

        while (nodeItr.getNext() != null) {
            prev = nodeItr;
            nodeItr = nodeItr.getNext();
        }

        prev.setNext(null);
        nodeItr.setPrev(null);
        nodeItr = null;
    }

    public void remove(T data) {
        ListNode<T> cur = null;


    }
    /* add Api for removeAfter, removeBefore, removeAllAfter, removeAllBefore */
}
