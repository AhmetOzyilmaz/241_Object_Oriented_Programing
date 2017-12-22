public interface GTUSetInt<T> {

    public Boolean empty();
    public int size() ;
    public int max_size();
    public void insert(  T element) ;
    public void erase( T element) ;
    public void clear();
    public GTUSet<T>.GTUIterator<T> find(T element) ;
    public int count(  T e) ;
    public GTUSet<T>.GTUIterator<T> begin();
    public GTUSet<T>.GTUIterator<T> end();
    public GTUSetInt<T> intersection(GTUSetInt<T> other);
}
