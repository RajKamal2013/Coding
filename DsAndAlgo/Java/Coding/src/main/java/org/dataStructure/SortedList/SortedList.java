package DS.SortedList;

public interface SortedList<Key, E> {
    public void clear();
    public boolean isEmpty();
    public int length();

    public void insert(Key K, E e);
    public E remove();

    public void next();
    public void prev();
    public void moveToStart();
    public void moveToEnd();
    public void moveToPos(int pos);

    public int currPos();
    public E getValue();
    public Key getKey();
}

