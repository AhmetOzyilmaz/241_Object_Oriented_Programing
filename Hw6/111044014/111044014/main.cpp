#include <iostream>
#include <string>
#include "GTUSetBase.h"
#include "GTUMap.h"
#include "GTUIterator.h"

using namespace GTU_NS;
using namespace std;



template <class T>
shared_ptr<GTUSetBase<T>> setIntersection(const GTUSetBase<T>&  first, const GTUSetBase<T>&  second) {
	throw;
}


int main() {
	GTUMap<int, string> plakalar;
	plakalar.insert( pair<int, string>(34, "istanbul") );
	plakalar.insert(pair<int, string>(35, "izmir"));
	plakalar.insert(pair<int, string>(12, "ahmet"));

	plakalar[36] = "Gumushane";

	cout << "plhaka of 36: " << plakalar[36] << endl;

	plakalar[36] = "NotGumushane";

	cout << "plhaka of 36: " << plakalar[36] << endl;

	plakalar[1] = "Ankara";
	plakalar[2] = "Second";
	plakalar[3] = "Third";

	cout << "plaka of 1: " << plakalar[1] << endl;
	cout << "plaka of 2: " << plakalar[2] << endl;
	cout << "plaka of 3: " << plakalar[3] << endl;

	system("PAUSE");


	//TEST insert 
	GTUSet<int> myset;
	myset.insert(3);
	myset.insert(5);
	myset.insert(7);
	myset.insert(18);
	myset.insert(3);
	myset.insert(5);
	myset.insert(7);
	myset.insert(18);
	myset.insert(3);
	myset.insert(5);
	myset.insert(7);
	myset.insert(18);

	for (auto i = myset.begin(); i != myset.end(); i++)
	{
		std::cout << *i << " ";
	}

	system("PAUSE");

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

	/*GTUMap<int, int> mymap;
	pair<int, int> p(4, 5);

	mymap.insert(p);

	pair<int, int> p1(14, 5);

	mymap.insert(p1);

	/*for (int i = 0; i < mymap.size(); i++) {
		cout << "KEY -> " << mymap.GET(i).first << " Value "<<  mymap.GET(i).second << endl;
	}
	cout << "Size: " << mymap.size() << endl;
	cout << "Max size: " << mymap.max_size() << endl;

	mymap.erase(p1);

	for (int i = 0; i < mymap.size(); i++) {
		cout << "KEY -> " << mymap.GET(i).first << " Value " << mymap.GET(i).second << endl;
	}
	cout << "Size: " << mymap.size() << endl;
	cout << "Max size: " << mymap.max_size() << endl;
	*/
	system("PAUSE");
	return  0;
}