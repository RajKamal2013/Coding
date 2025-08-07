package DS.FList;

public class LList<E> implements List<E> {
    private Link<E> head;
    private Link<E> tail;
    private Link<E> curr;
    private int cnt;

    LList() {
        this.cnt = 0;
        this.head = this.tail = this.curr = new Link<E>(null);
    }

    LList(int size) {
        this();
    }

    public void clear() {
        this.cnt = 0;
        this.head = this.tail = this.curr = new Link<E>(null);
    }

    public boolean isEmpty() {
        return (this.cnt == 0);
    }

    public void insert(E data) {
        Link<E> newNode = Link.get(data, curr.next());
        curr.setNext(newNode);
        curr = newNode;
        if (tail == curr) {
            tail = curr.next();
        }
        this.cnt = this.cnt + 1;
    }

    public void append(E data) {
        Link<E> newNode = Link.get(data, null);
        tail.setNext(newNode);
        tail = newNode;
        this.cnt  = this.cnt + 1;

    }
    public E remove() {
        if (isEmpty() || (curr.next() == null)) {
            return null;
        }

        E data = curr.next().data();
        if (tail == curr.next()) {
            tail = curr;
        }
        Link<E> temp = curr.next();
        curr.setNext(curr.next().next());
        temp.release();

        this.cnt = this.cnt - 1;
        return data;
    }
    public void delete(E data) {
        System.out.println("Not implemented!!!");
    }
    public void next() {
        curr = curr.next();
    }
    public void prev() {
        if (curr == head) {
            return;
        }
        Link<E> temp = head;

        while(temp.next() != curr) {
            temp = temp.next();
        }
        curr = temp;
    }

    public void moveToStart() {
        curr = head;
    }
    public void moveToEnd() {
        curr = tail;
    }

    public void moveToPos(int pos) {
        if ((pos < 0 ) || (pos >= cnt)) {
            return;
        }
        int i = 0;
        curr = head;
        for (i = 0; i < pos; i++) {
            curr = curr.next();
        }
    }
    public int curPos() {
        Link<E> temp = head;
        int pos = 0;
        for (pos = 0; temp != curr; pos++) {
            temp  = temp.next();
        }
        return pos;
     }

    public int length() {
        return this.cnt;
    }
    public E getData() {
        if (curr.next() == null) {
            return null;
        }
        return curr.next().data();
    }

    public String toString() {
        // Save the current position of the list
        int oldPos = curPos();
        int length = length();
        StringBuffer out = new StringBuffer((length() + 1) * 4);

        moveToStart();
        out.append("< ");
        for (int i = 0; i < oldPos; i++) {
            out.append(getData());
            out.append(" ");
            next();
        }
        out.append("| ");
        for (int i = oldPos; i < length; i++) {
            out.append(getData());
            out.append(" ");
            next();
        }
        out.append(">");
        moveToPos(oldPos); // Reset the fence to its original position
        return out.toString();
    }
}
