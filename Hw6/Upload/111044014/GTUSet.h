#ifndef GTUSET_H
#define GTUSET_H
#include "GTUSetBase.h"

using namespace std;
namespace GTU_NS {
	template <class T>
	class GTUSet : public GTUSetBase<T>
	{
		public:

		GTUSet() {
			Resize(this->cap);
		}
		~GTUSet() {
		}
		bool empty() const  override {
			return this->used == 0;
		}
		int size() const  override {
			return this->used;
		}
		int max_size()const   override {
			return this->cap;
		}
		void insert( const T element)  override {
			if (this->used >= this->cap) {
				Resize(this->cap * 2);
			}
			this->contents.get()[this->used] = element;
			this->used++;
		}
		void erase(const T element) override {
			auto oldData = this->contents.get();
			int cpyUsed = this->used;
			this->used = 0;
			for (int i = 0; i < cpyUsed; ++i) {
				if (element != oldData[i]) 
					insert(oldData[i]);
			}
		}
		void clear() override {
			Resize(this->cap);
			this->used = 0;
		}
		T GET(int index)const  {
			if (index < this->used && index > -1) {
				return this->contents.get()[index];
			}
			throw std::out_of_range("contents.get()[index] : index is out of range");
		}
		T find( GTUIterator<T> it)const  override {
			for (auto i = begin(); i != end(); ++i) {
				if (i == it)
					return *i;
			}
			throw runtime_error("Item not found");
		}
		int count( const T e) const override {
			int counter = 0;

			for (int i = 0; i < this->used; ++i) {
				if (e == GET(i))
					counter++;
			}
			return counter;
		}
		GTUIterator<T> begin()  const override {
			return GTUIterator<T>(this->contents, 0);
		}
		GTUIterator<T> end()const  override {
			return GTUIterator<T>(this->contents, size());
		}
	private:
		void Resize(int newcap) {
			this->cap = newcap;

			T* d;
			//copy old contents if such a thing exist
			if (this->contents != nullptr) {
				auto oldData = this->contents.get();
				d = new T[this->cap];
				for (int i = 0; i < this->used; i++) {
					d[i] = oldData[i];
				}
			}
			else {
				d = new T[this->cap];
			}

			this->contents = std::shared_ptr<T>(d, std::default_delete<T[]>());
		}
	};
}
#endif // !GTUSET_H
