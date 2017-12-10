#include <iostream>
#include "GTUSetBase.h"
#include "GTUMap.h"
#include "GTUIterator.h"

using namespace GTU_NS;
using namespace std;
//template <class T>
//shared_ptr<GTUSetBase<T> >setIntersection<T>(const GTUSetBase<T>&  first, const GTUSetBase<T>&  second);
int main() {
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