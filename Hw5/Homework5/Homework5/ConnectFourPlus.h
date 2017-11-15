#ifndef CONNECTFOURPLUS_H
#define CONNECTFOURPLUS_H

#include "ConnectFourAbstract.h"

namespace Ozyilmaz_Ahmet_111044014 {

	class ConnectFourPlus : ConnectFourAbstract
	{
	public:
		ConnectFourPlus();
		~ConnectFourPlus();
		
		void IsEnd();
		void playGame();
		void Play();
	private:
	};
}
#endif