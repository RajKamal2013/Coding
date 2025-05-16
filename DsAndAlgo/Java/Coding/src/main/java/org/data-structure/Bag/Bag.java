package DS.Bag;

import java.util.Iterator;
import java.util.NoSuchElementException;

/* To do
* 1. remove in iterator
* 2. remove in main class
* 3. inherit and add remove and find
 */
public class Bag<Item> implements Iterable<Item> {
    /* Inner Class */
    private class  Node <Item> {
            Item item;
            public Node<Item> next;
            public String toString() {
                return item.toString();
            }
    }
    /* Inner Class */
    private class BagIterator<Item > implements Iterator<Item> {
        private Node<Item> current;
        private Node<Item> prev;
        BagIterator(Node<Item> first) {
            current = first;
            prev = null;
        }

        @Override
        public boolean hasNext() {
            return (current != null);
        }

        @Override
        public Item next() {
            if (!hasNext()) throw new NoSuchElementException();
            Item item = current.item;
            prev = current;
            current = current.next;
            return item;
        }

        @Override
        public void remove(){
        }
    }

    private Node<Item> first;
    private int cnt;

    Bag() {
        first = null;
        cnt = 0;
    }

    public boolean isEmpty() {
        return (first == null);
    }

    public int size() {
        return cnt;
    }

    public void add (Item item) {
        Node<Item> oldNode = first;
        first  = new Node<Item>();
        first.item = item;
        first.next = oldNode;
        cnt  = cnt + 1;
    }

    public void append(Item item) {
        throw new UnsupportedOperationException();
    }

    public Item remove() {
        if (isEmpty()) {
            return null;
        }
        Item item = first.item;
        first = first.next;
        cnt = cnt - 1;
        return item;
    }

    public void delete(Node<Item> node) {
        Node<Item> temp = first;
        Node<Item> del= null;
        while(temp.next != null) {
            if (temp.next == node) {
                temp.next = temp.next.next;
                break;
            }
            temp = temp.next;
        }
    }

    public Iterator<Item> iterator()  {
        return new BagIterator<Item>(first);
    }

    public String toString(){
        StringBuffer out = new StringBuffer((size() + 1) *4);
        out.append("< ");


        for (BagIterator<Item> it = new BagIterator<Item>(first); it.hasNext(); ) {
            Item s = it.next();
            out.append(s.toString());
        }

        out.append(">");
        return out.toString();
    }

}
