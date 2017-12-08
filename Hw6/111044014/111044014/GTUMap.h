#ifndef GTUMAP_H
#define GTUMAP_H

#include <iostream>
#include <utility>

#include "GTUSet.h"

namespace GTU_NS {

	template <class K, class V>
	class GTUMap : public GTUSet < std::pair<K,V> >
	{
	public:
		GTUMap();
		~GTUMap();
		V& operator[](const K& k);// returns reference to ites mapped value

	};

}
#endif