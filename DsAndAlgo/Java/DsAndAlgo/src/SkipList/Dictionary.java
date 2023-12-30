package DS.SkipList;

public interface Dictionary<Key, E> {

    public void clear();

    public void insert(Key key, E value);

    public E remove(Key key);

  //public E removeAny();

    public E find(Key k);

    public int size();
};
