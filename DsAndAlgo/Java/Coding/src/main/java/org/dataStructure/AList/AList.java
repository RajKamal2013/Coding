package DS.AList;

public class AList <E> implements List<E> {
    private static final int defaultSize = 10;
    private int maxSize;
    private int listSize;
    private int curr;
    private E[] listArray;

    AList() {
        this.maxSize = defaultSize;
        this.listSize=this.curr = 0;
        this.listArray = (E[]) new Object[defaultSize];
    }

    AList(int size) {
        this.maxSize = size;
        this.listSize = curr = 0;
        this.listArray = (E[]) new Object[size];
    }

    public void clear() {
        this.listSize = this.curr = 0;
    }

    public boolean isEmpty() {
        return (this.listSize == 0);
    }

    public int length() {
        return  this.listSize;
    }

    public void insert(E it) {
        assert listSize < maxSize : "List capacity exceeded";
        for (int i = listSize; i > curr; i--) {
            this.listArray[i] = this.listArray[i-1];
        }

        listArray[curr] = it;
        listSize = listSize + 1;
    }

    public void append(E it) {
        assert listSize < maxSize: "list capacity exceeded";
        listArray[listSize++] = it;
    }

    public E remove() {
        if ((curr < 0) || (curr >= listSize)) {
            return  null;
        }
        E it = listArray[curr];
        for (int i = curr; i < listSize; i++) {
            listArray[i] = listArray[i + 1];
        }
        listSize--;
        return it;
    }

    public void prev() {
        if (curr != 0) {
            curr = curr  - 1;
        }
    }

    public void next() {
        if (curr < listSize) {
            curr = curr + 1;
        }
    }

    public void moveToStart() {
        curr = 0;
    }

    public void moveToEnd() {
        curr = listSize;
    }

    public void moveToPos(int pos) {
        assert ((pos >= 0 ) && (pos <= listSize));
        curr = pos;
    }

    public int currPos() {
        return curr;
    }

    public  E getValue() {
        assert((curr >= 0) && (curr < listSize));
        return listArray[curr];
    }

    public String toString() {
        int oldPos = currPos();
        int len = length();
        StringBuffer out = new StringBuffer((length() + 1) *4);

        moveToStart();
        out.append("< ");

        for (int i = 0; i < oldPos; i++) {
            out.append(getValue().toString());
            out.append(" ");
            next();
        }

        for (int i = oldPos; i < length(); i++) {
            out.append(getValue().toString());
            out.append(" ");
            next();
        }

        out.append(">");
        moveToPos(oldPos);
        return out.toString();
    }

}
