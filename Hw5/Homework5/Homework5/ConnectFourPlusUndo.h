#ifndef CONNECTFOURPLUSUNDO_H
#define CONNECTFOURPLUSUNDO_H
#include "ConnectFourPlus.h"

namespace Ozyilmaz_Ahmet_111044014 {


	class ConnectFourPlusUndo : ConnectFourPlus
	{
	public:
		ConnectFourPlusUndo();
		~ConnectFourPlusUndo();
		bool IsEnd();
		void Play();
	};

}
#endif