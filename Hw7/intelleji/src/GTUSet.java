import java.security.InvalidParameterException;

public class GTUSet<T> implements GTUSetInt<T>{

    public int cap=10;
    public int used=0 ;
    public T[] contents ;


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
            String str= new String();
            str+="Index is "  + index ;
            return  str;
        }

    }

    GTUSet() {
        contents= (T[]) new Object[cap];
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

        if( find(element) != null ){
            throw  new InvalidParameterException();
        }

        if (used >= cap) {
            Resize(cap *2);
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
        int i =0;
        for(; i <used ; ++ i) {
            if (element == contents[i]){
                return new GTUIterator<>(i);
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
      for (int i = 0; i < this.size() ;++i ) {

          if (other.find(this.contents[i]) != null) {
              intersect.insert(this.contents[i]);
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
            System.out.println( contents[i].toString());

        }
        return returnValue;
    }
    public boolean isSame(T element, T element2){
        if(element == element2)
            return  true;
        return false;
    }

}
