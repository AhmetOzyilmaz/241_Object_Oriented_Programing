import javafx.util.Pair;

public class GTUMap<K,V> extends GTUSet<Pair<K,V>>{
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
          System.out.println( "Key -> " + contents[i].getKey() +"  Value -> " +contents[i].getValue()+"\n");

        }
        return returnValue;
    }
    public int count(Pair e) {
        int counter = 0;
        for (int i = 0; i < used; ++i) {
            if (e.getKey() == GET(i).getKey() && e.getValue() == GET(i).getValue() )
                ++counter;
        }
        return counter;
    }
    @Override
    public void clear() {
        for (int i = 0; i< cap; ++ i) {
            contents =  new Pair[cap];
        }
        used = 0;

    }
    public boolean equals(Pair first,Pair second){
        System.out.println("MAPP***********************");
        if (first.getKey() == second.getKey() && first.getValue() == second.getValue() )
            return  true;
        return false;
    }

}
