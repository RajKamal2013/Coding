package DS.List;

public class LList<E> implements List<E> {
    private Link<E> head;
    private Link<E> tail;
    private Link<E> curr;
    int cnt;

    LList() {
        curr = tail = head = new Link<E>(null);
        cnt = 0;
    }

    public boolean isEmpty() {
        return (cnt == 0);
    }

    public void clear() {
        head.setNext(null);
        curr = tail = head = new Link<E>(null);
        cnt = 0;
    }

    public void insert(E it) {
        curr.setNext(new Link<E>(it, curr.next()));
        if (tail == curr) {
            tail = curr.next();
        }
        cnt = cnt + 1;
    }

    public void append(E it) {
        Link<E> node = new Link<E>(it, null);
        tail.setNext(node);
        tail = node;
        cnt = cnt + 1;
    }

    public E remove() {
        if (curr.next() == null) return null;
        E data = curr.next().data();
        if (tail == curr.next()) {
            tail = curr;
        }
        cnt = cnt  - 1;
        return data;
    }

    public void moveToStart() {
        curr = head;
    }

    public void moveToEnd() {
        curr = tail;
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

    public void next() {
        if (curr != tail) {
            curr = curr.next();
        }
    }

    public int length() {
        return cnt;
    }

    public int currPos() {
        Link<E> temp = head;
        int pos = 0;
        for (pos = 0; temp!=curr; pos++) {
            temp = temp.next();
        }
        return pos;
     }

     public void moveToPos(int pos) {
        assert((pos >= 0) && (pos <= cnt));
        curr = head;
        for (int i = 0; i < pos; i++) {
            curr = curr.next();
        }
     }

     public E getValue() {
        if (curr.next() == null) return  null;
        return curr.next().data();
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
