
/**
 *
 * @author ASUS
 * @param <T>
 */
public interface GTUSetInt<T> {

    /**
     *
     * @return
     */
    public Boolean empty();

    /**
     *
     * @return
     */
    public int size();

    /**
     *
     * @return
     */
    public int max_size();

    /**
     *
     * @param element
     */
    public void insert(  T element);

    /**
     *
     * @param element
     */
    public void erase( T element);

    /**
     *
     */
    public void clear();

    /**
     *
     * @param element
     * @return
     */
    public GTUSet<T>.GTUIterator<T> find(T element);

    /**
     *
     * @param e
     * @return
     */
    public int count(  T e);

    /**
     *
     * @return
     */
    public GTUSet<T>.GTUIterator<T> begin();

    /**
     *
     * @return
     */
    public GTUSet<T>.GTUIterator<T> end();

    /**
     *
     * @param other
     * @return
     */
    public GTUSetInt<T> intersection(GTUSetInt<T> other);
}
