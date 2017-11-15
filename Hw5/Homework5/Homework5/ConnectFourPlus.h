#ifndef CONNECTFOURPLUS_H
#define CONNECTFOURPLUS_H
#include "ConnectFourAbstract.h"

namespace Ozyilmaz_Ahmet_111044014 {

	class ConnectFourPlus :public ConnectFourAbstract
	{
	public:
		ConnectFourPlus();
		~ConnectFourPlus();
		void playGame();
		bool IsEndOneSide(const char& User, const char& other);

	};
}
#endif