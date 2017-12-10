#ifndef GTUITERATOR_H
#define GTUITERATOR_H
namespace GTU_NS {

	template <class T >
	class GTUIterator
	{
	public:
		GTUIterator() {
			//TODO
		}

		~GTUIterator() {
			//TODO
		}

		GTUIterator<T> operator ++ () {  // pre-increment 
			//TODO
			return ;
		}

		GTUIterator<T> operator ++ (int) { // post-increment 
			pointer* ++;
			return *this;
		}
		GTUIterator<T> operator --() {
			//TODO
			return
		}
		GTUIterator<T> operator --(int) {
			//TODO
			return
		}
		GTUIterator& operator = (const GTUIterator& other) {
			//TODO
			return *this;
		}
		bool operator == (const GTUIterator& other) {
			//TODO
			return false;
		}
	private:
		T* pointer;
		int size = 0;
	};

}
#endif // !GTUITERATOR_H
