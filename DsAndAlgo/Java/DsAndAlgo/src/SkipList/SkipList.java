package DS.SkipList;

public class SkipList<Key extends Comparable <? super Key>, E> implements Dictionary<Key, E>{
    static int MAXLEVEL = 4;
    private SkipNode<Key, E> head;
    private int level;
    private int size;

    public SkipList() {
        head = new SkipNode<Key, E>(null, null, 0);
        level = -1;
        size = 0;
    }

    int randomLevel() {
        int lev;
        for (lev = 0; DSUtil.random(2) == 0; lev++);
        lev = lev % MAXLEVEL;
        return lev;
    }

    public void adjustHead(int newLevel) {
        SkipNode<Key, E> temp = head;
        head = new SkipNode<>(null, null, newLevel);
        for (int i = 0; i <=  level; i++ ) {
            head.forward[i] = temp.forward[i];
        }
        this.level = newLevel;
    }

    public void print () {
        SkipNode<Key, E> temp = head;
        while (temp != null) {
            System.out.print(temp.value() + ": Length is " + temp.forward.length + ":");
            for (int i = 0; i < temp.forward.length; i++) {
                if (temp.forward[i] == null) {
                    System.out.print(" null ");
                } else {
                    System.out.print(temp.forward[i].value() + " ");
                }
            }
            System.out.println();
            temp = temp.forward[0];
        }
    }

    public void printEverything() {
        SkipNode ptr = this.head;
        System.out.println( "Head Node " );
        ptr.printForward();
        ptr = ptr.forward[0];
        while (ptr != null) {
            System.out.println( "Node (" + ptr.key() + " : " + ptr.value() + ")" );
            ptr.printForward();
            ptr = ptr.forward[0];
        }
    }

    public int size() {
        return size;
    }

    public E remove(Key K) {
        SkipNode<Key, E> x = head;
        SkipNode<Key, E>[] update = (SkipNode<Key, E>[]) new SkipNode[this.level + 1];

        for (int i = this.level; i >= 0; i--) {
            while((x.forward[i] != null) && (K.compareTo(x.forward[i].key()) > 0)) {
                x = x.forward[i];
            }
            update[i] = x;
        }

        x = x.forward[0];

        if ((x != null) && (K.compareTo(x.key()) == 0)) {

            for (int i = 0; i <= level; i++) {
                if (update[i].forward[i] != x) {
                    break;
                }
                update[i].forward[i] = x.forward[i];
            }

            while ((level > 0) && (head.forward[level] == null)) {
                level = level - 1;
            }
        }
        return x.value();
    }

    public void clear() {
        System.out.println("Not yet implemented");
        return;
    }

    public void insert(Key K, E newValue) {
        int newLevel = randomLevel();
        if (newLevel > level) {
            adjustHead(newLevel);
        }

        SkipNode<Key, E>[] update = (SkipNode<Key, E>[]) new SkipNode[this.level + 1];

        SkipNode<Key, E> x = head;

        for (int i = level; i >= 0; i--) {
            while((x.forward[i] != null) && (K.compareTo(x.forward[i].key()) > 0)) {
                x = x.forward[i];
            }
            update[i] = x;
        }

        SkipNode<Key, E> newNode  = new SkipNode<>(K, newValue, newLevel);

        for (int i = 0; i < newLevel; i++) {
            newNode.forward[i] = update[i].forward[i];
            update[i].forward[i] = newNode;
        }
        size++;
    }

    public E find (Key K) {
        SkipNode<Key, E> x = head;

        for (int i = level; i >= 0; i--) {
            while ((x.forward[i] != null) && (K.compareTo(x.forward[i].key()) > 0)) {
                x = x.forward[i];
            }
        }
        x = x.forward[0];

        if ((x != null) && (K.compareTo(x.key()) == 0)) {
            return x.value();
        } else {
            return null;
        }
    }


}
