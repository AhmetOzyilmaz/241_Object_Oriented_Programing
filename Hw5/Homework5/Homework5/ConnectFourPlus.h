#ifndef CONNECTFOURPLUS_H
#define CONNECTFOURPLUS_H
#include "ConnectFourAbstract.h"

namespace Ozyilmaz_Ahmet_111044014 {

	class ConnectFourPlus : ConnectFourAbstract
	{
	public:
		ConnectFourPlus();
		~ConnectFourPlus();
		
		bool IsEnd();
		void Play();
		void playGame();
	};
}
#endif