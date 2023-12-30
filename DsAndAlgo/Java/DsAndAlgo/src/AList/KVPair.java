package DS.AList;

public class KVPair<Key, E> {
    private Key k;
    private E v;

    KVPair() {
        k = null;
        v = null;
    }

    KVPair(Key K, E V) {
        this.k = K;
        this.v = V;
    }

    public Key key() {return  k;}
    public E value() {return  v;}

    public String toString() {
        String str = "(" + k + "," + v +")";
        return str;
    }
}
