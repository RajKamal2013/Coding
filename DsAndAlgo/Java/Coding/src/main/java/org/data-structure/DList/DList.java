package DS.DList;

import DS.globals;

public class DList<E> implements List<E>{
    private DLink<E> head;
    private DLink<E> tail;
    protected DLink<E> curr;
    int cnt;
    String fileName  = new Throwable().getStackTrace()[0].getFileName();


    DList(int size) {this();}

    DList() {
        curr = head  = new DLink<E>(null, null);
        tail = new DLink<E>(head, null);
        head.setNext(tail);
        cnt = 0;
    }

    public void clear() {
        head.setNext(null);
        curr = head = new DLink<E>(null, null);
        tail = new DLink<E>(head, null);
        head.setNext(tail);
        cnt = 0;
    }

    public boolean isEmpty() {
        return (cnt == 0);
    }
    public void moveToStart() {
        curr = head;
    }

    public void moveToEnd() {
        curr = tail.prev();
    }

    public void moveToPos(int pos) {
        assert((pos >= 0) && (pos <= cnt));
        curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next();
        }
    }

    public int length() {
        return  cnt;
    }

    public E getValue() {
        return curr.next().data();
    }

    public void next() {
        if (curr != tail.prev()) {
            curr = curr.next();
        }
    }

    public void prev() {
        if (curr != head) {
            curr = curr.prev();
        }
    }

    public int currPos() {
        DLink<E> temp = head;

        int i = 0;
        for (i = 0; temp!= curr; i++) {
            temp = temp.next();
        }
        return i;
    }

    public void insert(E it) {
        DLink<E> node = new DLink<E>(it, curr, curr.next());
        curr.next().setPrev(node);
        curr.setNext(node);
        cnt = cnt + 1;

        int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
        String debug = "count is " + cnt;
        globals.LogDBG(2, currentLine, fileName, debug);
    }

    public void append(E it) {
        DLink<E> node = new DLink<E>(it, tail.prev(), tail);
        tail.prev().setNext(node);
        tail.setPrev(node);
        cnt = cnt + 1;

        int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
        String debug = "count is " + cnt;
        globals.LogDBG(2, currentLine, fileName, debug);

    }

    public E remove(){
        if (curr.next() == tail) { return null;}
        E it = curr.next().data();
        curr.setNext(curr.next().next());
        curr.next().next().setPrev(curr);
        cnt = cnt - 1;
        return it;
    }

    public String toString() {
        int oldPos = currPos();
        int length = length();

        StringBuffer out = new StringBuffer((length() + 1) * 4);

        moveToStart();
        out.append("< ");
        for (int i = 0; i < oldPos; i++) {
            out.append(getValue());
            out.append(" ");
            next();
        }

        out.append("| ");
        for (int i = oldPos; i < length; i++) {
            out.append(getValue());
            out.append(" ");
            next();
        }
        out.append("> ");
        moveToPos(oldPos);
        return out.toString();
    }
}

