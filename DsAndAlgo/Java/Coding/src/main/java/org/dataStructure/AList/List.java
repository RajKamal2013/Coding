package DS.AList;

public interface List<E> {
    public void clear();
    public void insert(E data);
    public void append(E data);
    public E remove();
    public void moveToStart();
    public void moveToEnd();
    public void prev();
    public void next();
    public int length();
    public int currPos();
    public void moveToPos(int pos);
    public E getValue();
    public boolean isEmpty();
    //public boolean find(E data);
}
