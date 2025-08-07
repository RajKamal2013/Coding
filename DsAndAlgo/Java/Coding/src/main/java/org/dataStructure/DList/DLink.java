package DS.DList;

public class DLink<E> {
    private E data;
    private DLink<E> next;
    private DLink<E> prev;

    DLink(E it, DLink<E> prev, DLink<E> next) {
        this.data  = it;
        this.next = next;
        this.prev = prev;
    }

    DLink(DLink<E> prev, DLink<E> next) {
        this.next  = next;
        this.prev = prev;
    }

    DLink<E> next() {return next;}
    DLink<E> prev() {return prev;}

    public void setNext(DLink<E> next) {
        this.next = next;
    }

    public void setPrev(DLink<E> prev) {
        this.prev = prev;
    }

    E data() {
        return this.data;
    }

    public void setData(E data) {
        this.data = data;
    }
}
