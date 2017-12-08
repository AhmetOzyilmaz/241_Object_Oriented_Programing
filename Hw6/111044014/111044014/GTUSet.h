#ifndef GTUSET_H
#define GTUSET_H
#include "GTUSetBase.h"

#include <memory>

namespace GTU_NS {
	template <class T>
	class GTUSet : public GTUSetBase<T>
	{
	public:
		GTUSet() {
			cap = 10;
			used = 0;

			Resize(cap);
		}

		~GTUSet() {

		}

		bool empty() override {
			return used == 0;
		}

		int size() override {
			return used;
		}

		int max_size() override {
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

		}

		void clear() override {

		}

		T& GET(int index) {
			if (index < used && index > -1) {
				return contents.get()[index];
			}
			throw;
		}

		T find(const GTUIterator<T> it) const override {
			throw;
		}
		int count(const T e) const override {
			return 0;
		}

		GTUIterator<T> begin() const override {
			throw;
		}
		GTUIterator<T> end() const override {
			throw;
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

	private:
		int cap;
		int used;

		std::shared_ptr<T> contents;
	};


}
#endif // !GTUSET_H
