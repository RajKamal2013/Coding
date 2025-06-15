package DS.SortedArrayList;

public interface Dictionary <Key, E> {
    public void clear();
    public void insert(Key Key, E Value);
    public E remove(Key key);
    public E find(Key key);
    public int size();
    public boolean isEmpty();
}
