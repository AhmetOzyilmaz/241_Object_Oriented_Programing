#include <iostream>
#include "GTUSetBase.h"
#include "GTUMap.h"
#include "GTUIterator.h"

using namespace GTU_NS;

int main() {

	cout << "HELLO WORLD" << endl;
	
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

	for (int i = 0; i < myset.size(); i++) {
		cout << myset.GET(i) << endl;
	}

	cout << "Size: " << myset.size()<< endl;
	cout << "Max size: " << myset.max_size() << endl;

	system("PAUSE");
	return  0;
}