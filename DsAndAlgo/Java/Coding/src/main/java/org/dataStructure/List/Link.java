package DS.List;

public class Link<E> {
    private E data;
    private Link<E> next;

    Link(E data, Link<E> next) {
        this.data = data;
        this.next = next;
    }

    Link(Link<E> next) {
        this.next = next;
    }

    Link<E> next() {return next;}
    void setNext(Link<E> node) { next = node;}
    E data() {return  data; }
    void setData(E data) { this.data = data;}
}
