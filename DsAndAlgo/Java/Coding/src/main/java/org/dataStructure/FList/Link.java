package DS.FList;

public class Link <E>{
    private E data;
    private Link<E> next;

    static Link freeList = null;

    Link(E data, Link<E> next) {
        this.data = data;
        this.next = next;
    }
    Link(Link<E> next) {
        this.next = next;
    }
    public Link<E> next() {
        return this.next;
    }
    public void setNext(Link<E> next) {
        this.next = next;
    }
    public E data() {
        return this.data;
    }
    public void setData(E data) {
        this.data = data;
    }

    static<E> Link <E> get(E it, Link<E> next) {
        if (freeList == null) {
            return new Link(it, next);
        }
        Link temp = freeList;
        freeList = freeList.next();
        temp.setData(it);
        temp.setNext(next);
        return temp;
    }
    void release() {
        this.data = null;
        this.next = freeList;
        freeList = this;
    }
}
