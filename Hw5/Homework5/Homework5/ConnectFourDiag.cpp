#include "ConnectFourDiag.h"


Ozyilmaz_Ahmet_111044014::ConnectFourDiag::ConnectFourDiag()
{
	InitialBoard();
	PrintBoard();
	while (1) {
		cout << "Please Enter Game mode Player | Computer  - > P | C" << endl;
		char mode = ' ';
		cin >> mode;
		if (mode == 'P' || mode == 'p' || mode == 'C' || mode == 'c') {
			setMode(mode);
			break;
		}
		else
		{
			cout << "<-----> Error mode Enter Correct Mode <-----> " << endl;
		}
	}
}
Ozyilmaz_Ahmet_111044014::ConnectFourDiag::~ConnectFourDiag()
{
	cout << "destructor ConnectFourDiag" << endl;
}
/*
*	Desciription : This function checking is game ended for one side
*	Input		   : no input
*	Return Value : return interger if 1 user one won if  2 user2 won  if -1 game is not ender
*/
bool Ozyilmaz_Ahmet_111044014::ConnectFourDiag::IsEndOneSide(const char & User, const char & other)
{
	int row = getRow();
	int column = getColumn();
	string controller = "";
	for (int i = row - 1; i >= 0; --i) {
		for (int j = column - 1; j >= 0; --j) {
			controller = "";
			for (int direction = 1; direction <= 4; direction++)//8 is number of direction
				controller += PartnerCheck(direction, i, j, User, other, 4, true);
			controller += "0000";
			if (controller != "00000000")
				return true;
		}
	}
	return false;
}


