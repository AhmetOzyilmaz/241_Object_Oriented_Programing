#include <iostream>
#include <string>
#include "GTUSetBase.h"
#include "GTUMap.h"

using namespace GTU_NS;
using namespace std;

template <class T>
shared_ptr<GTUSetBase<T>> setIntersection(const GTUSetBase<T>&  first, const GTUSetBase<T>&  second) {
	auto intersect = shared_ptr<GTUSetBase<T>>(new GTUSet<T>());

	for (auto i = first.begin(); i != first.end(); i++)
	{
		if( second.count(*i) > 0 ){
			intersect->insert(*i);
		}
	}

	return intersect;
}
int main() {
	GTUMap<string, string> plakalar;
	GTUMap<string, string> plakalar2;

	cout << "GTUMap - emthy()-->" << plakalar.empty() << endl;
	cout << "GTUMap - size()-->" << plakalar.size() << endl;
	cout << "GTUMap - max_size()-->" << plakalar.max_size() << endl;

	plakalar.insert(pair<string, string>("34", "istanbul"));
	plakalar.insert(pair<string, string>("35", "izmir"));
	plakalar.insert(pair<string, string>("45", "Manisa"));
	plakalar.insert(pair<string, string>("06", "Ankara"));
	plakalar.insert(pair<string, string>("01", "Adana"));

	cout << "GTUMAP - erase() Before -->(01, Adana)" << endl;

	for (auto i = plakalar.begin(); i != plakalar.end(); i++)
		cout << (*i).first << "  " << (*i).second << " " << endl;

	plakalar.erase(pair<string, string>("01", "Adana"));
	cout << "GTUMAP - erase() After -->(01, Adana)" << endl;
	for (auto i = plakalar.end(); i != plakalar.begin(); i--)
		cout << (*i).first << "  " << (*i).second << " " << endl;

	cout << endl << "GTUMAP - clear() Before -->" << endl;
	for (auto i = plakalar.begin(); i != plakalar.end(); i++)
		cout << (*i).first << "  " << (*i).second << " " << endl;
	plakalar.clear();

	cout << "GTUMAP - erase() After -->" << endl;
	for (auto i = plakalar.begin(); i != plakalar.end(); i++)
		cout << (*i).first << "  " << (*i).second << " " << endl;


	plakalar.insert(pair<string, string>("35", "izmir"));

	cout << "GTUMAP - count(value)  -->" << endl;
	cout << "counter --> " << plakalar.count(pair<string, string>("35", "izmir"))<<endl;
	
	plakalar["1"] = "Ankara";
	plakalar["2"] = "Second";
	plakalar["3"] = "Third";

	cout << "plaka of 1: " << plakalar["1"] << endl;
	cout << "plaka of 2: " << plakalar["2"] << endl;
	cout << "plaka of 3: " << plakalar["3"] << endl;

	plakalar2.insert(pair<string, string>("34", "istanbul"));
	plakalar2.insert(pair<string, string>("35", "izmir"));
	plakalar2.insert(pair<string, string>("45", "Manisa"));
	plakalar2.insert(pair<string, string>("06", "Ankara"));
	
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


	cout << "GTUSet - find() used in count function -->" << endl;
	cout << "find() method " << " " << (*myset.find(18));

	shared_ptr<GTUSetBase<int>> intersection = setIntersection(myset, myset2);
	cout << endl << endl << "Intersection Test" << endl;
	cout << "Size: " << intersection->size() << endl << "Elements:" << endl;

	for (auto i = intersection->begin(); i != intersection->end(); i++)
		cout << *i << endl;



	cout << endl << endl << "Element already in set test" << endl;

	try{
		GTUSet<int> overloadedSet;
		overloadedSet.insert(3);
		overloadedSet.insert(5);
		overloadedSet.insert(7);
		overloadedSet.insert(18);
		cout << endl << endl << "Now trying to add same element to the set [" << 7 << "] " << endl;
		overloadedSet.insert(7);
	}
	catch(std::invalid_argument e){
		cout << "Expection chached (Was expected) : " << e.what() << endl;
	}


	cout <<"Count test for  5 -> "<<  myset.count(5)<< endl;
	for (int i = 0; i < myset.size(); i++) {
		cout << myset.GET(i) << endl;
	}

	cout << "Size: " << myset.size()<< endl;
	cout << "Max size: " << myset.max_size() << endl;

	myset.erase(5);
	for (int i = 0; i < myset.size(); i++) {
		cout << myset.GET(i) << endl;
	}
	cout << "Size: " << myset.size() << endl;
	cout << "Max size: " << myset.max_size() << endl;
	cout << "Count test for  5 -> " << myset.count(5) << endl;

	myset.erase(3);	//TEST SET ERASE 

	for (int i = 0; i < myset.size(); i++) {
		cout << myset.GET(i) << endl;
	}
	cout << "Size: " << myset.size() << endl;
	cout << "Max size: " << myset.max_size() << endl;
	//TEST SET clear  

	myset.clear();
	
	for (int i = 0; i < myset.size(); i++) {
		cout << myset.GET(i) << endl;
	}
	cout << "Size: " << myset.size() << endl;
	cout << "Max size: " << myset.max_size() << endl;

	return  0;
}