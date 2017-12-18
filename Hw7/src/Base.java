import javafx.util.*;
public class Base<T> {

    GTUSetBase<T>[] setIntersection( GTUSetBase<T> first,  GTUSetBase<T> second) {
        GTUSetBase<T>[] intersect = new GTUSetBase[first.size()+second.size()];

        for (GTUIterator<T> it = first.begin(); it.hasNext() !=true;)
        {
             T cur  =it.next();
            if( second.count(cur) > 0 ){
            //TODO intersect.insert(cur);
            }
        }

        return intersect;
    }

    public static void main(String[] args){
        GTUMap<String, String> plakalar;
        GTUMap<String, String> plakalar2;

        System.out.println( "GTUMap - emthy()-." + plakalar.empty() );
        System.out.println( "GTUMap - size()-." + plakalar.size() );
        System.out.println( "GTUMap - max_size()-." + plakalar.max_size() );

        plakalar.insert(Pair<String, String>("34", "istanbul"));
        plakalar.insert(Pair<String, String>("35", "izmir"));
        plakalar.insert(Pair<String, String>("45", "Manisa"));
        plakalar.insert(Pair<String, String>("06", "Ankara"));
        plakalar.insert(Pair<String, String>("01", "Adana"));

        System.out.println( "GTUMAP - erase() Before -.(01, Adana)" );

        for (auto i = plakalar.begin(); i != plakalar.end(); i++)
            System.out.println( (i).first + "  " + (i).second + " " );

        plakalar.erase(Pair<String, String>("01", "Adana"));
        System.out.println( "GTUMAP - erase() After -.(01, Adana)" );
        for (auto i = plakalar.end(); i != plakalar.begin(); i--)
            System.out.println( (i).first + "  " + (i).second + " " );

        System.out.println(  + "GTUMAP - clear() Before -." );
        for (auto i = plakalar.begin(); i != plakalar.end(); i++)
            System.out.println( (i) + "  " + (i).second + " " );
        plakalar.clear();

        System.out.println( "GTUMAP - erase() After -." );
        for (auto i = plakalar.begin(); i != plakalar.end(); i++)
            System.out.println( (i).first + "  " + (i).second + " " );


        plakalar.insert(Pair<String, String>("35", "izmir"));

        System.out.println( "GTUMAP - count(value)  -." );
        System.out.println( "counter -. " + plakalar.count(Pair<String, String>("35", "izmir"))+;

        plakalar["1"] = "Ankara";
        plakalar["2"] = "Second";
        plakalar["3"] = "Third";

        System.out.println( "plaka of 1: " + plakalar["1"] );
        System.out.println( "plaka of 2: " + plakalar["2"] );
        System.out.println( "plaka of 3: " + plakalar["3"] );

        plakalar2.insert(Pair<String, String>("34", "istanbul"));
        plakalar2.insert(Pair<String, String>("35", "izmir"));
        plakalar2.insert(Pair<String, String>("45", "Manisa"));
        plakalar2.insert(Pair<String, String>("06", "Ankara"));

        //TEST insert 
        GTUSet<int> myset;
        myset.insert(3);
        myset.insert(5);
        myset.insert(7);
        myset.insert(18);

        GTUSet<int> myset2;
        myset2.insert(4);
        myset2.insert(6);
        myset2.insert(7);
        myset2.insert(19);

        );
        System.out.println( "GTUSet - find() used in count function -." );
        System.out.println( "find() method " + " " + (myset.find(18));

        shared_ptr<GTUSetBase<int>> intersection = setIntersection(myset, myset2);
        System.out.println("Intersection Test" );
        System.out.println( "Size: " + intersection.size() + + "Elements:" );

        for (auto i = intersection.begin(); i != intersection.end(); i++)
            System.out.println( i );



        System.out.println(  +  + "Element already in set test" );

        try{
            GTUSet<int> overloadedSet;
            overloadedSet.insert(3);
            overloadedSet.insert(5);
            overloadedSet.insert(7);
            overloadedSet.insert(18);
            System.out.println(  +  + "Now trying to add same element to the set [" + 7 + "] " );
            overloadedSet.insert(7);
        }
        catch(Exception e){//TODO std::invalid_argument e
            System.out.println( "Expection chached (Was expected) : " + e.getMessage() );
        }


        System.out.println("Count test for  5 . "+  myset.count(5));
        for (int i = 0; i < myset.size(); i++) {
            System.out.println( myset.GET(i) );
        }

        System.out.println( "Size: " + myset.size());
        System.out.println( "Max size: " + myset.max_size() );

        myset.erase(5);
        for (int i = 0; i < myset.size(); i++) {
            System.out.println( myset.GET(i) );
        }
        System.out.println( "Size: " + myset.size() );
        System.out.println( "Max size: " + myset.max_size() );
        System.out.println( "Count test for  5 . " + myset.count(5) );

        myset.erase(3);	//TEST SET ERASE 

        for (int i = 0; i < myset.size(); i++) {
            System.out.println( myset.GET(i) );
        }
        System.out.println( "Size: " + myset.size() );
        System.out.println( "Max size: " + myset.max_size() );
        //TEST SET clear  

        myset.clear();

        for (int i = 0; i < myset.size(); i++) {
            System.out.println( myset.GET(i) );
        }
        System.out.println( "Size: " + myset.size() );
        System.out.println( "Max size: " + myset.max_size() );

    }
}



