#ifndef GTUMAP_H
#define GTUMAP_H

#include <iostream>
#include <utility>

#include "GTUSet.h"

namespace GTU_NS {

	template <class K, class V>
	class GTUMap : public GTUSet<std::pair<K,V>>
	{
	public:
		GTUMap(){}
		~GTUMap(){}
		V& operator[](const K& k) {
			for (auto it = begin(); it != end(); it++)
			{
				if (k == (*it).first) {
					return (*it).second;
				}
			}
			V obj = V();
			insert( std::pair<K,V>(k, obj) );
			return (*this)[k];
		}
	private:


	};

}

#endif