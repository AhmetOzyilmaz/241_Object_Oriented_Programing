
public class GTUSet<T> implements GTUSetBase<T>{

    public int cap=10;
    public int used=0 ;
    public T[] contents=null;

    GTUSet() {
        Resize(cap);
    }
    @Override
    public Boolean empty() {
        return used == 0;
    }

    @Override
    public int size() {
        return used;
    }

    @Override
    public int max_size() {
        return cap;
    }

    @Override
    public void insert(T element) {
        if( count(element) > 0 ){
            //TODOthrow("Element is already in set");
        }

        if (used >= cap) {
            Resize(cap * 2);
        }
        contents[used] = element;
        used++;
    }

    @Override
    public void erase(T element) {
        T[] oldData = contents;
        int cpyUsed = used;
        used = 0;
        for (int i = 0; i < cpyUsed; ++i) {
            if (element != oldData[i])
                insert(oldData[i]);
        }
    }

    @Override
    public void clear() {
        used = 0;
    }

    T GET(int index){
        if (index < used && index > -1) {
            return contents[index];
        }
        //TODOthrow ::out_of_range("contents.get()[index] : index is out of range");
        return null;
    }

    @Override
    public GTUIterator<T> find(T element) {
        GTUIterator<T> it = new GTUIterator<T>(contents,-1);

        for (; it.hasNext() != true; ) {
            if (it.next() == element)
            return it;
        }
        return null;
    }

    @Override
    public int count(T e) {
        int counter = 0;
        for (int i = 0; i < used; ++i) {
            if (e == GET(i))
                counter++;
        }
        return counter;
    }

    @Override
    public GTUIterator<T> begin() {
        return new GTUIterator<T>(contents, 0);
    }

    @Override
    public GTUIterator<T> end() {
        return new GTUIterator<T>(contents, size());
    }
    public void Resize(int newcap) {
        cap = newcap;
        if (contents != null) {
            T[] oldData = contents;
            contents = (T[])new Object[cap];
            for (int i = 0; i < used; i++) {
                contents[i] = oldData[i];
            }
        }
        System.gc();
    }

}
