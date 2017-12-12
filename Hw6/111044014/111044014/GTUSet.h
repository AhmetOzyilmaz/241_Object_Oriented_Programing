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
			Resize(cap);
		}
		~GTUSet() {
		}
		bool empty() const override {
			return used == 0;
		}
		int size() const override {
			return used;
		}
		int max_size() const override {
			return cap;
		}
		void insert(const T element) override {
			if (used >= cap) {
				Resize(cap * 2);
			}
			contents.get()[used] = element;
			used++;
		}
		void erase(const T element) override {
			auto oldData = contents.get();
			int cpyUsed = used;
			used = 0;
			for (int i = 0; i < cpyUsed; ++i) {
				if (element != oldData[i]) 
					insert(oldData[i]);
			}
		}
		void clear() override {
			Resize(cap);
			used = 0;
		}
		T GET(int index) const {
			if (index < used && index > -1) {
				return contents.get()[index];
			}
			throw std::out_of_range("contents.get()[index] : index is out of range");
		}
		T find(const GTUIterator<T> it) const override {
			for (auto i = begin(); i != end(); ++i) {
				if (i == it)
					return *i;
			}
			throw runtime_error("Item not found");
		}
		int count(const T e) const override {
			int counter = 0;

			for (int i = 0; i < used; ++i) {
				if (e == GET(i))
					counter++;
			}
			return counter;
		}
		GTUIterator<T> begin() const override {
			return GTUIterator<T>(contents, 0);
		}
		GTUIterator<T> end() const override {
			return GTUIterator<T>(contents, size());
		}
	private:
		void Resize(int newcap) {
			cap = newcap;

			T* d;
			//copy old contents if such a thing exist
			if (contents != nullptr) {
				auto oldData = contents.get();
				d = new T[cap];
				for (int i = 0; i < used; i++) {
					d[i] = oldData[i];
				}
			}
			else {
				d = new T[cap];
			}

			contents = std::shared_ptr<T>(d, std::default_delete<T[]>());
		}
	};
}
#endif // !GTUSET_H
