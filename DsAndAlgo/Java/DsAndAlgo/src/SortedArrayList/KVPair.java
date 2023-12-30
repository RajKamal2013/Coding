package DS.SortedArrayList;

import java.util.stream.Stream;

public class KVPair <Key, E>{
    Key key;
    E value;

    KVPair() {
        key = null;
        value = null;
    }

    KVPair(Key key, E value) {
        this.key = key;
        this.value = value;
    }

    public Key key() {
        return key;
    }

    public E value() {
        return value;
    }

    public String toString() {
        String out = "(" + key.toString() + "-" + value.toString() + ")";
        return out;
    }
}
