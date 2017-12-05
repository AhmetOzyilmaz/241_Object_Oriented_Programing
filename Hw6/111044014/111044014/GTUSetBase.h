#include <iostream>
using namespace std;
namespace GTU_NS {
	template<class K, class V>
	class GTUSetBase
	{
		public:
			virtual bool empty() = 0;
			virtual int size() = 0 ;
			virtual int max_size() = 0;//like capacity
			virtual void insert(const pair<K,V> element)  = 0; // TODO throw exception
			virtual void erase(const pair<K,V> element) = 0;
			virtual void clear()=0 ;
			virtual pair<K,V> find(const iterator it) const = 0;
			virtual int count(const V) const = 0;
			virtual iterator begin() const  = 0 ;
			virtual iterator end() const = 0 ;
		private:
	};
}