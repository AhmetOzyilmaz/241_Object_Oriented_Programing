public class GTUMap<K,V> extends GTUSet<javafx.util.Pair<K,V>>{

    GTUMap(){}

    V at( K k) {
        for (int i = 0;i < used; ++i)
        {
            if (k == contents[i].getKey())
                return contents[i].getValue();
        }

        return null;
    }
}
