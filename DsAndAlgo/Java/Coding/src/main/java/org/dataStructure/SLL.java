package org.dataStructure;

/*
 * Constructor -> normal constructor, copy constructor
 */
public class SLL<T> {
    private ListNode<T> head;
    private int len = 0;
    String fileName  = new Throwable().getStackTrace()[0].getFileName();

    public SLL () {
        this.head = null;
        len = 0;
    }

    public SLL (SLL<T> s) {
        this.head = s.head;
        this.len = s.len;
    }

    public SLL(T data) {
        this.head = new ListNode<>(data);
        this.len = 1;
    }

    /* Over ride for specific type of class */
    public boolean contains(T data) {
        ListNode<T> temp = head;
        while (temp != null) {
            if (temp.getData() == data) {
                break;
            }
            temp = temp.getNext();
        }
        return  false;
    }

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
    public void insert(T data) {
        ListNode<T> newNode = new ListNode<>(data);
        if (this.head == null) {
            this.head = newNode;
            this.len = 1;
            return;
        }
        newNode.setNext(this.head);
        this.head = newNode;
        this.len = this.len + 1;
    }

    public void append(T data) {
        ListNode<T> newNode = new ListNode<>(data);
        if (this.head == null) {
            this.head = newNode;
            return;
        }
        ListNode<T> tempNode = this.head;
        while(tempNode.getNext() != null) {
            tempNode = tempNode.getNext();
        }
        tempNode.setNext(newNode);
        this.len = this.len + 1;
    }

    public void insert(SLL<T> list) {
        if (list.head == null) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "Head is null in list to be inserted ";
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }

        ListNode<T> temp = list.head;
        while(temp.getNext() != null) {
            temp = temp.getNext();
        }
        assert((temp != null) && (temp.getNext() == null));
        temp.setNext(this.head);
        this.head = list.head;
        this.len  = this.len + list.len;
    }

    public void append(SLL<T> list) {
        if (list.head == null) {
            String warning = "Head is null in list to be inserted";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }

        if (this.head == null) {
            this.head = list.head;
            this.len = list.len;
            return;
        }

        ListNode<T> temp = this.head;
        while(temp.getNext() != null) {
            temp = temp.getNext();
        }
        temp.setNext(list.head);
        this.len = this.len + list.len;
        return;
    }


    /* Override for custom classes */
    public boolean insertAfter(T data, T after) {
        ListNode<T> newNode  = new ListNode<>(data);
        ListNode<T> temp = this.head;
        while ((temp != null) && (temp.getData()!= after)) {
            temp = temp.getNext();
        }
        if (temp == null) {
            String error = "Data " + after + "not present in SLL";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogError(1, currentLine, fileName, error);
            return false;
        }
        assert(temp.getData() == after);
        newNode.setNext(temp.getNext());
        temp.setNext(newNode);
        this.len = this.len + 1;
        return  true;
    }

    public boolean insertAfter(SLL<T> list, T after) {
        ListNode<T> temp = this.head;
        if (list.head == null) {
            return false;
        }
        ListNode<T> ltemp = list.head;
        while(ltemp.getNext() != null) {
          ltemp = ltemp.getNext();
        }
        assert((ltemp != null) && (ltemp.getNext() == null));
        while ((temp != null) && (temp.getData() != after)) {
            temp = temp.getNext();
        }
        if (temp == null) {
            String error = "Data " + after + "not present in SLL";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogError(1, currentLine, fileName, error);
            return false;
        }
        assert((temp != null) && (temp.getData() == after));
        ltemp.setNext(temp.getNext());
        temp.setNext(list.head);
        this.len = this.len + list.len;
        return true;
    }

    /* Override for custom classes */
    public boolean insertBefore(T data, T before) {
        ListNode<T> newNode = new ListNode<>(data);
        ListNode<T> temp = this.head;
        ListNode<T> prev = this.head;

        while ((temp != null) && (temp.getData() != before)) {
            prev = temp;
            temp = temp.getNext();
        }
        if (temp == null) {
            String error = "Data" + before + "not present in SLL ";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogError(1, currentLine, fileName, error);
            return false;
        }

        assert (temp.getData() == before);
        if (prev == this.head) {
            newNode.setNext(this.head);
            head = newNode;
            this.len = this.len + 1;
            return true;
        } else {
            newNode.setNext(temp);
            prev.setNext(newNode);
            this.len = this.len + 1;
            return true;
        }
    }

    public boolean insertBefore(SLL<T> list, T before) {
        ListNode<T> ltemp = list.head;
        while(ltemp.getNext() != null) {
            ltemp = ltemp.getNext();
        }
        assert((ltemp != null) && (ltemp.getNext() == null));

        ListNode<T> temp = this.head;
        ListNode<T> prev = this.head;

        while ((temp != null) && (temp.getData() != before)) {
            prev = temp;
            temp = temp.getNext();
        }
        if (temp == null) {
            String error = "Data"  + before + "not present in SLL";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogError(1, currentLine, fileName, error);
            return false;
        }

        assert((temp != null) && (temp.getData() == before));

        if (prev == this.head) {
            ltemp.setNext(prev);
            this.head = list.head;
            this.len = this.len + list.len;
            return true;
        } else {
            ltemp.setNext(temp);
            prev.setNext(ltemp);
            this.len = this.len + list.len;
            return true;
        }
    }

    public void remove(T data) {
        if (this.head == null) {
            String error = "list is empty, nothing to remove ";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogError(1, currentLine, fileName, error);
            return;
        }

        ListNode<T> temp = this.head;
        if (this.head.getData() == data) {
            this.head = this.head.getNext();
            this.len = this.len - 1;
            temp = null;
            return;
        }

        ListNode<T> prev = this.head;
        while ((temp.getNext() != null) && (temp.getData() != data)) {
            prev = temp;
            temp = temp.getNext();
        }
        if (temp.getData() != data) {
            String error = "Data " + data + "not present to remove at line ";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogError(1, currentLine, fileName, error);
            return;
        }
        prev.setNext(temp.getNext());
        temp = null;
        this.len = this.len - 1;
    }

    public void removeLast() {
        ListNode<T> temp = this.head;
        if (temp == null) {
            String warning = "List is empty in line";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }
        ListNode<T> prev = temp;
        while(temp.getNext() != null) {
            temp = temp.getNext();
        }

        if (temp == this.head) {
            head = null;
        } else {
            prev.setNext(temp.getNext());
        }
        temp = null;
        this.len = this.len - 1;
        return;
    }

    public void removeFront() {
        ListNode<T> temp = this.head;
        if (temp == null) {
            String warning = "List is empty";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }

        if (temp.getNext() == null) {
            this.head = null;
            this.len = this.len + 1;
            return;
        }

        this.head = this.head.getNext();
        temp = null;
        this.len = this.len - 1;
        return;
    }

    public void removeAfter(T data) {
        ListNode<T> temp = this.head;
        if (temp == null) {
            String warning = "List is empty";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }

        ListNode<T> prev = temp;
        while((temp.getNext() != null) && (temp.getData() == data)) {
            prev = temp;
            temp = temp.getNext();
        }

        if ((temp.getNext() == null) && (temp.getData() != data)) {
            String error = "data" + data + "Not present";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogError(1, currentLine, fileName, error);
            return;
        }

        if ((temp.getNext() == null) && (temp.getData() == data)) {
            return;
        }

        prev.setNext(temp.getNext());
        temp = null;
        this.len = this.len - 1;
    }

    public void removeAllAfter(T data) {
        ListNode<T> temp = this.head;
        if (temp == null) {
            String warning = "List is empty";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }

        ListNode<T> prev = temp;
        while((temp.getNext() != null) && (temp.getData() == data)) {
            prev = temp;
            temp = temp.getNext();
        }

        if ((temp.getNext() == null) && (temp.getData() != data)) {
            String error = "data " + data + " Not present";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogError(1, currentLine, fileName, error);
            return;
        }

        if ((temp.getNext() == null) && (temp.getData() == data)) {
            return;
        }

        prev.setNext(null);

        ListNode<T> nodeToFree;
        while(temp.getNext() != null) {
            nodeToFree = temp;
            temp = temp.getNext();
            nodeToFree = null;
            this.len = this.len - 1;
        }
        return;
    }

    public void removeBefore(T data) {
        ListNode<T>temp = this.head;
        if (temp == null) {
            String error = "List Is Empty";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogError(1, currentLine, fileName, error);
            return;
        }

        if (temp.getData() == data) {
            String warning = "Nothing to remove";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }

        ListNode<T> prev = temp;
        while((temp.getNext()!= null) && (temp.getNext().getData() != data)) {
            prev = temp;
            temp = temp.getNext();
        }

        if (temp.getNext() == null) {
            String error = "data: " + data + "not present";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogWarning(1, currentLine, fileName, error);

            return;
        }

        prev.setNext(temp.getNext());
        temp = null;
        this.len = this.len - 1;
    }

    public void removeAllBefore(T data) {
        ListNode<T>temp = this.head;
        if (temp == null) {
            String error = "List is empty";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogError(1, currentLine, fileName, error);
            return;
        }

        if (temp.getData() == data) {
            String warning = "Nothing to remove";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogWarning(1, currentLine, fileName, warning);
            return;
        }


        while((temp.getNext()!= null) && (temp.getData() != data)) {
            temp = temp.getNext();
        }

        if (temp.getNext() == null) {
            String error = "data " + data + "not present";
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            globals.LogError(1, currentLine, fileName, error);
            return;
        }

        ListNode<T> nodeItr = this.head;
        ListNode<T> freeNode;
        while(nodeItr.getNext() != temp) {
            freeNode = nodeItr;
            nodeItr = nodeItr.getNext();
            this.head.setNext(nodeItr);
            freeNode = null;
            this.len = this.len - 1;
        }
        return;
    }



    public void clear() {
        ListNode<T> nodeItr = this.head;
        ListNode<T> temp;
        while(nodeItr.getNext() != null) {
            temp = nodeItr;
            nodeItr = nodeItr.getNext();
            temp = null;
            this.len = this.len - 1;
        }
        this.head = null;
    }

    public boolean isEmpty() {
        if (this.head == null) {
            return  true;
        } else {
            return false;
        }
     }

     /* handle exceptions in below cases  */
    public T getFront() {
        return this.head.getData();
    }

    public T getLast() {
        ListNode<T> nodeItr = this.head;
        while(nodeItr.getNext()!= null) {
            nodeItr = nodeItr.getNext();
        }
        return nodeItr.getData();
    }

    public T getdata(int index) {
        if ((index < 0 ) || (index >= this.len)){
            return null;
        }
        int idx = 0;
        ListNode<T> itr = this.head;
        while(idx < index) {
            idx = idx + 1;
            itr = itr.getNext();
        }

        return itr.getData();

    }

    /* Do we need getAfter and getBefore */

    public int getLength() {
        return this.len;
    }

    public int getPosition(T data) {
        ListNode<T> nodeItr = this.head;
        int idx = 0;
        while((nodeItr.getNext() != null) && (nodeItr.getData() != data)) {
            idx = idx + 1;
            nodeItr = nodeItr.getNext();
        }

        if (nodeItr.getData() == data) {
            return idx;
        } else {
            return  -1;
        }
    }

    public void reverse() {
        ListNode<T>[] rev = new ListNode[1];
        rev[0] = null;
        if (this.head.getNext() == null) {
            return;
        }
        reverse_int(this.head, rev);
        this.head = rev[0];
    }

    public void reverse_int(ListNode<T> cur, ListNode<T>[] rev) {
         ListNode<T> next = cur.getNext();
         if (next == null) {
             rev[0] = cur;
             return;
         }
         reverse_int(next, rev);
         cur.setNext(null);
         next.setNext(cur);
    }

    public void reverseItr(){
        ListNode<T> rev = null;
        ListNode<T> temp = this.head;
        ListNode<T> itr = null;

        if (this.head.getNext() == null) {
            return;
        }

        rev = null;
        while (itr.getNext() != null) {
            temp = itr.getNext();
            itr.setNext(rev);
            rev = itr;;
            itr = temp;
        }
    }
}
