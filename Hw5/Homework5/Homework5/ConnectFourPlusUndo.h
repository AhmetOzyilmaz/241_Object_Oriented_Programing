#ifndef CONNECTFOURPLUSUNDO_H
#define CONNECTFOURPLUSUNDO_H
#include "ConnectFourPlus.h"

namespace Ozyilmaz_Ahmet_111044014 {


	class ConnectFourPlusUndo : public ConnectFourPlus
	{
	public:
		bool CommandSelector(const string& command);
		void UndoMove();
	};
}
#endif