import javafx.util.*;
public class Base<T> {


    public static void main(String[] args){
        GTUMap<String, String> plakalar = new GTUMap<String, String>();

        System.out.println( "GTUMap - emthy()-." + plakalar.empty() );
        System.out.println( "GTUMap - size()-." + plakalar.size() );
        System.out.println( "GTUMap - max_size()-." + plakalar.max_size() );

        plakalar.insert(new Pair<String, String>("34", "istanbul"));
        plakalar.insert(new Pair<String, String>("35", "izmir"));
        plakalar.insert(new Pair<String, String>("45", "Manisa"));
        plakalar.insert(new Pair<String, String>("06", "Ankara"));
        plakalar.insert(new Pair<String, String>("01", "Adana"));

        System.out.println( "GTUMAP - erase() Before -.(01, Adana)" );


        System.out.println(plakalar.toString() + " " );

        plakalar.erase(new Pair<String, String>("01", "Adana"));

        System.out.println( "GTUMAP - erase() After -.(01, Adana)" );

        System.out.println( "GTUMAP - insert() Before -.(45, Manisa)" );

        System.out.println(plakalar.toString() + " " );



        System.out.println(  "GTUMAP - clear() Before -." );

        System.out.println(plakalar.toString() + " " );
        plakalar.clear();


        System.out.println( "GTUMAP - erase() After -." );
        plakalar.clear();

        plakalar.insert(new Pair<String, String>("35", "izmir"));
        System.out.println(plakalar.toString() + " " );

        System.out.println( "GTUMAP - count(value)  -." );

        System.out.println( "counter -> " + plakalar.count(new Pair<String, String>("35", "izmir")));

        plakalar.insert(new Pair<String, String>("45", "Manisa"));
        plakalar.insert(new Pair<String, String>("06", "Ankara"));
        plakalar.insert(new Pair<String, String>("01", "Adana"));

        GTUIterator it = plakalar.find(new Pair<String, String>("45", "Manisa") );

        System.out.println( "find -> " + it);//TODO

        for (it = plakalar.begin(); it != plakalar.end();  ){
            System.out.println("Begin End Test --> " +it.next().toString());
        }
        GTUMap<String, String> plakalar2= new GTUMap<>();
        plakalar2.insert(new Pair<String, String>("45", "Manisa"));
        plakalar2.insert(new Pair<String, String>("06", "Ankara"));
        plakalar2.insert(new Pair<String, String>("01", "Adana"));


        GTUSetInt<Pair<String, String>> intersect = plakalar.intersection(plakalar2);

        System.out.println(intersect.toString());
        //TEST insert 
       /* GTUSet<int> myset;
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

        shared_ptr<GTUSetInt<int>> intersection = setIntersection(myset, myset2);
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
        System.out.println( "Max size: " + myset.max_size() );*/

    }
}



