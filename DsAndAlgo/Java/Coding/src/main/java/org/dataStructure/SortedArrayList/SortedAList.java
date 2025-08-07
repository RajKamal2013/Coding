package DS.SortedArrayList;

import org.dataStructure.globals;

public class SortedAList <Key extends Comparable<? super Key>, E> implements SAList<Key, E>{
    private static final int defaultSize = 10;
    private int maxSize;
    private int listSize;
    private int curr;
    private KVPair<Key, E>[] listArray;
    String fileName  = new Throwable().getStackTrace()[0].getFileName();

    SortedAList() {
        this.maxSize = 10;
        this.curr = this.listSize = 0;
        this.listArray = (KVPair<Key, E>[]) new KVPair[defaultSize];
        for (int i = 0; i < maxSize; i++) {
            listArray[i] = new KVPair<>();
        }
    }

    SortedAList(int size) {
        this.maxSize = size;
        this.curr = 0;
        this.listSize = 0;
        this.listArray = (KVPair<Key, E>[]) new KVPair[size];
        for (int i = 0; i < maxSize; i++) {
            listArray[i] = new KVPair<>();
        }
    }

    public void clear() {
        for (int i = 0; i  < this.listSize; i++) {
            this.listArray[i] = null;
        }
        this.listSize = 0;
        this.curr = 0;
    }

    public boolean isEmpty() {
        return ((listSize == 0) && (listArray[0] == null))  ;
    }

    public void insert(Key key, E value)
    {
        assert (listSize < maxSize);
        curr  = 0;

        while ((listSize > 0) && (listArray[curr].key() != null) && (listArray[curr].key().compareTo(key) < 0)) {
            curr = curr + 1;
        }

        int idx = 0;
        for (idx = listSize; idx >= curr; idx--) {
            listArray[idx + 1] = listArray[idx];
        }
        listArray[curr] = new KVPair<>(key, value);
        listSize = listSize + 1;
    }

    public void append(Key key, E value) {
        int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
        String warning = "append is not implemented yet !!!";
        globals.LogWarning(1, currentLine, fileName, warning);
    }

    public E remove() {
        if (isEmpty()) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "list is empty, nothing to remove  !!!";
            globals.LogWarning(1, currentLine, fileName, warning);
            return null;
        }
        assert (listArray[curr] != null);
        E data = listArray[curr].value();
        for (int i = curr; i < listSize - 1 ; i++) {
            listArray[i] = listArray[i + 1];
        }
        listSize = listSize - 1;
        return data;
    }

    public E delete(Key key) {
        if (isEmpty()) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "list is empty, nothing to remove  !!!";
            globals.LogWarning(1, currentLine, fileName, warning);
            return null;
        }

        int i = 0;
        for ( i = 0; i < listSize; i++) {
            if (listArray[i].key().compareTo(key) == 0) {
                break;
            }
        }

        if (i == listSize) {
            return null;
        }

        E data = listArray[i].value();
        int idx = 0;

        for (idx = i; idx < listSize - 1; idx++) {
            listArray[idx] = listArray[idx + 1];
        }
        curr = idx;
        listSize = listSize - 1;

        return data;
    }

    public E find(Key key) {
        E ret = null;
        if (isEmpty()) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "list is empty, nothing to find  !!!";
            globals.LogWarning(1, currentLine, fileName, warning);
            return null;
        }

        int i = 0;
        for ( i = 0; i < listSize; i++) {
            if (listArray[i].key().compareTo(key) == 0) {
                ret = listArray[i].value();
                break;
            }
        }

        return ret;
    }

    public int length() {
        return this.listSize;
    }

    public void next() {
        if (curr == listSize - 1) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "curr is already at last !!!";
            globals.LogWarning(2, currentLine, fileName, warning);
            return;
        }
        curr = curr + 1;
        return;
    }

    public void prev() {
        if (curr == 0) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "curr is already at beginning  !!!";
            globals.LogWarning(1, currentLine, fileName, warning);
            return;

        }

        curr = curr - 1;
    }

    public void moveToStart() {
        curr = 0;
    }

    public void moveToEnd() {
        curr = listSize;
    }

    public void moveToPos(int pos) {
        if ((pos >= listSize) || (pos < 0)) {
            int currentLine = new Throwable().getStackTrace()[0].getLineNumber();
            String warning = "pos is beyond list size  !!!";
            globals.LogWarning(2, currentLine, fileName, warning);
            return;
        }
        curr = pos;
    }

    public int currPos() {
        return curr;
    }
    public Key getKey() {
        if (isEmpty()) {
            return null;
        }
        return listArray[curr].key();
    }
    public E getValue() {
        if (isEmpty()) {
            return null;
        }
        return listArray[curr].value();
    }

    public String toString() {
        int oldPos = currPos();
        int len = length();
        StringBuffer out = new StringBuffer((length() + 1) *4 * 3);

        moveToStart();
        out.append("< ");

        for (int i = 0; i < oldPos; i++) {
            out.append(listArray[i].toString());
            out.append(" ");
            next();
        }

        out.append("| ");

        for (int i = oldPos; i < length(); i++) {
            out.append(listArray[i].toString());
            out.append(" ");
            next();
        }

        out.append(">");
        moveToPos(oldPos);
        return out.toString();
    }

}
