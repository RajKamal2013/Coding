package DS.SortedArrayList;

public interface SAList<Key, E> {
    public void clear();
    public void insert(Key key, E e);
    public void append(Key key, E e);
    public E remove();
    public E delete(Key key);
    public void next();
    public void prev();
    public void moveToStart();
    public void moveToEnd();
    public void moveToPos(int pos);
    public int currPos();
    public Key getKey();
    public E getValue();
    public int length();
    public boolean isEmpty();
    public E find(Key key);
}
