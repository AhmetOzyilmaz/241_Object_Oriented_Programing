#ifndef GTUSETBASE_H
#define GTUSETBASE_H

#include <iostream>
#include <utility>
using namespace std;
namespace GTU_NS {
	template <class T>
	class GTUSetBase
	{
		public:
			virtual bool empty() = 0;
			virtual int size() = 0 ;
			virtual int max_size() = 0;//like capacity
			virtual void insert(const T element)  = 0; // TODO throw exception
			virtual void erase(const T element) = 0;
			virtual void clear()=0 ;
			virtual T find(const iterator it) const = 0;
			virtual int count(const V) const = 0;
			virtual iterator begin() const  = 0 ;
			virtual iterator end() const = 0 ;		
	};
}
#endif // !GTUSETBASE_H
