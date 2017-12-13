#ifndef GTUMAP_H
#define GTUMAP_H

#include "GTUSet.h"
#include "GTUIterator.h"

namespace GTU_NS {

	template <class T> 	class GTUIterator;

	template <class K, class V>
	class GTUMap : public GTUSet<std::pair<K,V>>
	{
	public:

		GTUMap(){}
		~GTUMap(){}
		V& operator[](const K& k) {
			for ( auto it = this->begin(); it != this->end(); it++)
			{
				if (k == (*it).first) {
					return (*it).second;
				}
			}
			V obj = V();
			std::pair<K,V> temp(k, obj);
			this->insert( temp);
			return (*this)[k];
		}
	};

}

#endif // !GTUSET_H
