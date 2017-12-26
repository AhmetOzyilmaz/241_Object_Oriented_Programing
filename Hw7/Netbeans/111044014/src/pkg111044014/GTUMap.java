import javafx.util.Pair;

/**
 *
 * @author ASUS
 * @param <K>
 * @param <V>
 */
public class GTUMap<K,V> extends GTUSet<Pair<K,V>>{

    /**
     *
     */
    public class T {} ;

    GTUMap(){
        contents =  new Pair[cap];
    }

    V at( K k) {
        for (int i = 0;i < used; ++i)
        {
            if (k == contents[i].getKey())
                return contents[i].getValue();
        }

        return null;
    }
    public String toString(){
        String returnValue= new String();
        returnValue += "size() " + size() + "  " + "MaxSize() -> " + max_size() + "\n";
        for(int i = 0; i < used ; ++i){
            returnValue += "Key -> " + contents[i].getKey() +"  Value -> " +contents[i].getValue() +"\n" ;

        }
        return returnValue;
    }

    /**
     *
     * @param e
     * @return
     */
    public int count(Pair e) {
        int counter = 0;
        for (int i = 0; i < used; ++i) {
            if (e.getKey() == GET(i).getKey() && e.getValue() == GET(i).getValue() )
                ++counter;
        }
        return counter;
    }

    /**
     *
     */
    @Override
    public void clear() {
        for (int i = 0; i< cap; ++ i) {
            contents =  new Pair[cap];
        }
        used = 0;

    }

    /**
     *
     * @param element
     * @return
     */
    @Override
    public GTUIterator<T> find(Pair element) {
        System.out.printf("MAP");
        GTUIterator<T> it = new GTUIterator<T>(0);
        if(size() == 0)
            return null;

        for (int i = 0;i< size() ; ++i) {
            if (isSame(element,contents[i])){
                return it;
            }
        }
        return null;
    }

    /**
     *
     * @param element
     * @param element2
     * @return
     */
    public boolean isSame(Pair element, Pair element2){
        if(element.getKey() == element2.getKey())
            return  true;
        return false;
    }
}
