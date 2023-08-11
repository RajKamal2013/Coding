package DS.SortedArrayList;

public class SortedDictionary <Key extends Comparable <? super Key >, E>  implements Dictionary<Key, E>{
    private SortedAList<Key, E> list;
    SortedDictionary(int size) {
        list = new SortedAList<Key, E>(size);
    }
    SortedDictionary() {
        list = new SortedAList<>();
    }

    public void clear() {
        list.clear();

    }
    public void insert(Key key, E value) {
        list.insert(key, value);

    }
    public E remove(Key key) {
        E data = null;
        data = list.delete(key);
        return data;
    }
    public E find(Key key) {
        E data = null;
        data  = list.find(key);
        return data;
    }
    public int size() {
        return list.length();
    }
    public boolean isEmpty() {
        return list.isEmpty();
    }

    public String toString() {
        return list.toString();
    }
}
