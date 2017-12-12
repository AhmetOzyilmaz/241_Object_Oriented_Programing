#ifndef GTUSETBASE_H
#define GTUSETBASE_H

#include <iostream>
#include <utility>
#include <memory>
using namespace std;
namespace GTU_NS {
	template <class T>
	class GTUSetBase
	{
	public:
		template <class T>
		class GTUIterator
		{
		public:
			GTUIterator(std::shared_ptr<T> _contents, int _index) : contents(_contents), index(_index) {
			}

			GTUIterator<T> operator++(){
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

		virtual ~GTUSetBase() {};

		virtual bool empty() const = 0;
		virtual int size() const = 0;
		virtual int max_size() const = 0;
		virtual void insert(const T element) = 0;
		virtual void erase(const T element) = 0;
		virtual void clear() = 0;
		virtual T find(const GTUIterator<T> it) const = 0;
		virtual int count(const T e) const = 0;
		virtual GTUIterator<T> begin() const = 0;
		virtual GTUIterator<T> end() const = 0;


	protected:
		int cap=10;
		int used = 0;
		std::shared_ptr<T> contents;
		
	};
}
#endif // !GTUSETBASE_H
