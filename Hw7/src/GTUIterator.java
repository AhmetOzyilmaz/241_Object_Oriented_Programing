public class GTUIterator<T> {
    private int index = 0;
    private T[] contents;

    GTUIterator(T[] _contents, int _index)
    {
        contents =_contents;
        index=_index;
    }

    boolean hasNext( ){

        if(index<contents.length)
            return true;

        return false;
    }
    boolean hasPrevious( ){
        if(index>0)
            return true;
        return false;
    }

    T next( ){
        ++index;
        return contents[index];
    }
    T previous(){
        --index;
        return contents[index];
    }

}
