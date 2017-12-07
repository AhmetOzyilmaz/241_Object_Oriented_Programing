#ifndef GTUSET_H
#define GTUSET_H
#include "GTUSetBase.h"

namespace GTU_NS {
	template <class T>
	class GTUSet : public GTUSetBase<class T>
	{
	public:
		GTUSet();
		~GTUSet();
	private:
		T Data[];
	};
}
#endif // !GTUSET_H
