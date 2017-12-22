import java.security.InvalidParameterException;
import java.util.ArrayList;

public class GTUSet<T> implements GTUSetInt<T>{

    public int cap=10;
    public int used=0 ;
    public T[] contents = (T[]) new Object[cap] ;


    public class GTUIterator<T> {
        private int index = 0;

        GTUIterator(int _index)
        {
            index = _index;
        }

        boolean hasNext( ){

            if(index<used)
                return true;

            return false;
        }
        boolean hasPrevious( ){
            if(index>=0)
                return true;
            return false;
        }

        T next( ){
            ++index;
            return (T) contents[index];
        }
        T previous(){
            --index;
            return (T) contents[index];
        }

        public String toString(){
            return contents[index].toString();
        }

    }

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
            throw  new InvalidParameterException();
        }

        if (used >= cap) {
            Resize(cap +1);
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
        GTUIterator<T> it = new GTUIterator<T>(0);

        if(size() == 0) // TODO arrayin basindan aramayi duzelt -1 den baslama
            return null;
        for (int i = 0;i< size() ; ++i) {
            if (isSame(element,contents[i])){
                return it;

            }
        }
        return null;
    }

    @Override
    public int count(T e) {
        if(find(e) !=  null)
            return 1;
        else
            return 0;

    }

    @Override
    public GTUIterator<T> begin() {
        return new GTUIterator<T>( 0);
    }

    @Override
    public GTUIterator<T> end() {
        return new GTUIterator<T>( size());
    }

    @Override
    public GTUSetInt<T> intersection(GTUSetInt<T> other) {
        GTUSet<T> intersect = new GTUSet<>();
        for (GTUIterator<T> it = this.begin(); it.next() !=end(); )
        {
           T cur  =it.next();
            if( other.find(cur) != null ){
            intersect.insert(cur);
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
    public boolean isSame(T element, T element2){
        if(element == element2)
            return  true;
        return false;
    }

}
