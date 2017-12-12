#include <iostream>
#include <string>
#include "GTUSetBase.h"
#include "GTUMap.h"

using namespace GTU_NS;
using namespace std;

template <class T>
shared_ptr<GTUSetBase<T>> setIntersection(const GTUSetBase<T>&  first, const GTUSetBase<T>&  second) {
	throw;
}


int main() {
	GTUMap<string, string> plakalar;

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
	for (auto i = plakalar.begin(); i != plakalar.end(); i++)
		cout << (*i).first << "  " << (*i).second << " " << endl;

	cout << endl << "GTUMAP - clear() Before -->" << endl;
	for (auto i = plakalar.begin(); i != plakalar.end(); i++)
		cout << (*i).first << "  " << (*i).second << " " << endl;
	plakalar.clear();

	cout << "GTUMAP - erase() After -->" << endl;
	for (auto i = plakalar.begin(); i != plakalar.end(); i++)
		cout << (*i).first << "  " << (*i).second << " " << endl;

	cout << "GTUMAP - find()  -->" << endl;
	//TODO find
	
	plakalar["1"] = "Ankara";
	plakalar["2"] = "Second";
	plakalar["3"] = "Third";

	cout << "plaka of 1: " << plakalar["1"] << endl;
	cout << "plaka of 2: " << plakalar["2"] << endl;
	cout << "plaka of 3: " << plakalar["3"] << endl;

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

	return  0;
}