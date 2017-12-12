#ifndef GTUITERATOR_H
#define GTUITERATOR_H

#include <iostream>
#include <utility>
#include <memory>

namespace GTU_NS {

	template <class T>
	class GTUIterator
	{
	public:
		GTUIterator(std::shared_ptr<T> _contents, int _index) : contents(_contents), index(_index) {
		}

		GTUIterator<T> operator++() {
			//OTOD
			++index;
			auto old = *this;
			return old;
		}

		GTUIterator<T> operator++ (int) { // post-increment 
			index++;
			return *this;
		}
		GTUIterator<T> operator--() {
			--index;
			auto old = *this;
			return old;
		}
		GTUIterator<T> operator--(int) {
			--index;
			return *this;
		}
		GTUIterator<T>& operator = (const GTUIterator& other) {
			return *this(other);
		}
		bool operator == (const GTUIterator<T>& other) {
			return other.index == index;
		}
		bool operator != (const GTUIterator<T>& other) {
			return other.index != index;
		}

		T& operator*() {
			return *(contents.get() + index);
		}

	private:
		int index;
		std::shared_ptr<T> contents;
	};
}
	#endif 
