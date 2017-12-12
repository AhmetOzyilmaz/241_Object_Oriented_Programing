#ifndef GTUSETBASE_H
#define GTUSETBASE_H

#include <iostream>
#include <utility>
#include <memory>
#include "GTUIterator.h"

using namespace std;
namespace GTU_NS {

	template <class T>
	class GTUSetBase
	{
	public:

		virtual ~GTUSetBase() {};

		virtual bool empty() const = 0;
		virtual int size()  const = 0;
		virtual int max_size() const = 0;
		virtual void insert( const T element) = 0;
		virtual void erase(const T element) = 0;
		virtual void clear()  = 0;
		virtual T find( GTUIterator<T> it) const  = 0;
		virtual int count(const  T e) const  = 0;
		virtual GTUIterator<T> begin()const  = 0;
		virtual GTUIterator<T> end() const = 0;


	public:
		int cap=10;
		int used = 0;
		std::shared_ptr<T> contents;
		
	};

}
#endif // !GTUSETBASE_H
