package DS.SkipList;

public class SkipNode<Key, E> {
    private E value;
    private Key key;
    int level;

    public SkipNode<Key,E> [] forward;

    public E value() { return value;}

    public Key key() { return  key;}

    public SkipNode(Key key, E value, int level) {
        this.key = key;
        this.value = value;
        this.level = level;

        forward = (SkipNode<Key, E>[]) new SkipNode[level + 1];

        for (int i = 0; i < level; i++) {
            forward[i] = null;
        }
    }
    public void printForward( ) {
        for (int i = this.forward.length -1; i >= 0; i--) {
            if (this.forward[i] == null)
                System.out.println( "level : " + i + " ----> null" );
            else
                System.out.println( "level : " + i + " ----> (" + this.forward[i].key() + " : " + this.forward[i].value() + ")");
        }
    }
}
