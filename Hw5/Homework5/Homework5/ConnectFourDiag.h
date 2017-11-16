#ifndef CONNECTFOURDIAG_H
#define CONNECTFOURDIAG_H
#include "ConnectFourAbstract.h"

namespace Ozyilmaz_Ahmet_111044014 {

	class ConnectFourDiag : public ConnectFourAbstract
	{
	public:
		ConnectFourDiag();
		~ConnectFourDiag();
		virtual void UndoMove() {}

		bool IsEndOneSide(const char& User, const char& other);
	};
}
#endif

