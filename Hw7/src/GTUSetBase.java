public interface GTUSetBase<T> {

    public Boolean empty();
    public int size() ;
    public int max_size();
    public void insert(  T element) ;
    public void erase( T element) ;
    public void clear();
    public GTUIterator<T> find( T element) ;
    public int count(  T e) ;
    public GTUIterator<T> begin();
    public GTUIterator<T> end();
}
