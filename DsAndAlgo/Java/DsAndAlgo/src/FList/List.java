package DS.FList;

public interface List<E> {
    public void clear();
    public boolean isEmpty();
    public void insert(E data);
    public void append(E data);
    public E remove();
    public void delete(E data);
    public void next();
    public void prev();
    public void moveToStart();
    public void moveToEnd();
    public void moveToPos(int pos);
    public int curPos();
    public int length();
    public E getData();
}
