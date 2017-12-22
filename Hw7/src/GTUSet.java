import java.lang.reflect.Array;
import java.security.InvalidParameterException;

public class GTUSet<T> implements GTUSetInt<T>{

    public int cap=10;
    public int used=0 ;
    public T[] contents ;


    GTUSet() {
        contents = (T[]) new Object[cap];

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
            throw  new InvalidParameterException();
        }

        if (used >= cap) {
            Resize(cap * 2);
        }
        contents[used] = element;
        used++;
    }

    @Override
    public void erase(T element) {
        T[] curDate = contents;
        int cpyUsed = used;

        //this.Resize(cap);
        for (int i = 0; i < cpyUsed; ++i) {
            if (!element.equals(curDate[i])){
                contents[i] = curDate[i];
            }else {
                used--;
            }
        }

    }

    @Override
    public void clear() {
        for (int i = 0; i< cap; ++ i) {
            contents[i] = (T) new GTUSet<T>();
        }
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
            if (equals(element,it.next())){
                return it;

            }
        }
        return null;
    }

    @Override
    public int count(T e) {
        int counter = 0;
        for (int i = 0; i < used; ++i) {
            if (e == GET(i))
                ++counter;
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

    @Override
    public GTUSetInt<T> intersection(GTUSetInt<T> other) {
        GTUSet<T> intersect = (GTUSet<T>)new Object();
        for (GTUIterator<T> it = this.begin(); it.hasNext() !=true;)
        {
            for (GTUIterator<T> it2 = this.begin(); it.hasNext() !=true;)
            {
                T cur  =it2.next();
                if( other.count(cur) > 0 ){
                    intersect.insert(cur);
                }
            }
        }
        return intersect;
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
    public String toString(){
        String returnValue= new String();
        for(int i = 0; i < used ; ++i){
            System.out.println( contents[i].toString() +  "\n");

        }
        return returnValue;
    }
    public boolean equals(T element,T element2){
        if(element == element2)
            return  true;
        return false;
    }
}
