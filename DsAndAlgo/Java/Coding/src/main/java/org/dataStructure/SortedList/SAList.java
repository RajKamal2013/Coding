package DS.SortedList;

public class SAList<Key extends Comparable <? super Key>, E> implements SortedList<Key, E>  {

    private static final int defaultSize = 10;
    private int maxSize;
    private int listSize;
    private int curr;
    private KVPair<Key, E>[] listArray;


    SAList() {
        setup(defaultSize);
    }

    SAList(int size) {
        setup(size);
    }

    private void setup(int size) {
        maxSize = size;
        listSize = curr = 0;
        listArray = (KVPair<Key, E>[]) new KVPair[size];
    }

    public void clear() {
        listSize = curr = 0;
    }

    public boolean isEmpty() {
        return (listSize == 0);
    }

    public int length() {
        return listSize;
    }

    public void insert(Key K, E e) {
        KVPair<Key, E> data = new KVPair<>(K, e);

        curr = 0;

        while ((curr < listSize) && (listArray[curr].key().compareTo(K) < 0)) {
            curr = curr + 1;
        }

        for (int i = listSize; i > curr; i--) {
            listArray[i] = listArray[i-1];
        }

        listArray[curr] = data;
        listSize = listSize + 1;
    }

   public E remove() {
        if ((curr < 0) || (curr >= listSize)) {
            return null;
        }
        E it = listArray[curr].value();
        for (int i = curr; i <= listSize; i++) {
            listArray[i] = listArray[i + 1];
        }
        listSize = listSize  - 1;
        return it;
   }

   public void next() {
        if (curr <  listSize) {
            curr = curr + 1;
        }
   }

   public void prev() {
        if (curr != 0) {
            curr = curr  - 1;
        }
   }

   public void moveToStart() {
        curr = 0;
   }

   public void moveToEnd() {
        curr = listSize;
   }

   public void moveToPos(int pos) {
        assert ((pos >= 0 ) && (pos < listSize )): "Pos out of range";
        curr = pos;
   }

   public E getValue() {
        if ((curr < 0 ) && (curr >= listSize)) {
            return null;
        }
        return listArray[curr].value();
   }

   public Key getKey() {
       if ((curr < 0 ) && (curr >= listSize)) {
           return null;
       }
       return listArray[curr].key();
   }

   public int currPos() {
        return curr;
   }

    public String toString() {
        int oldPos = currPos();
        int len = length();
        StringBuffer out = new StringBuffer((length() + 1) *4 * 3);

        moveToStart();
        out.append("< ");

        for (int i = 0; i < oldPos; i++) {
            out.append(getKey().toString() + "-" + getValue().toString());
            out.append(" ");
            next();
        }

        out.append("| ");

        for (int i = oldPos; i < length(); i++) {
            out.append(getKey().toString() + "-" + getValue().toString());
            out.append(" ");
            next();
        }

        out.append(">");
        moveToPos(oldPos);
        return out.toString();
    }


}
