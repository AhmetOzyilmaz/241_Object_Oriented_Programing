#ifndef CONNECTFOURPLUSUNDO_H
#define CONNECTFOURPLUSUNDO_H
#include "ConnectFourPlus.h"

namespace Ozyilmaz_Ahmet_111044014 {

class ConnectFourPlusUndo : public ConnectFourPlus{
	public:
		void UndoMove();
	private:
		int MoveCount = 0;
};
}
#endif