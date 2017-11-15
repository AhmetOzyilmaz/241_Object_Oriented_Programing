#include "ConnectFourPlus.h"

/*
*	Desciription : This function take row and column
*					Cheking game mode  should be 1 or 2
*	Input		 : no input parameter
*	Return Value : no return value */
void Ozyilmaz_Ahmet_111044014::ConnectFourPlus::playGame() {
	int row = 0, column = 0;
	while (1) {
		cout << "Enter Game Row Size  \n" << "Game board can be any size \n";
		cin >> row;
		cout << "Enter Game Column Size  \n" << "Game board can be any size \n";
		cin >> column;
		if (cin.fail()) {
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cerr << " <--->ILLEGAL<---> Wrong input enter integer \n";
		}
		else {
			setColumn(column);
			setRow(row);
			break;
		}
	}

}
/*
*	Desciription : This function checking is game ended for one side
*	Input		   : no input
*	Return Value : return interger if 1 user one won if  2 user2 won  if -1 game is not ender
*/
bool Ozyilmaz_Ahmet_111044014::ConnectFourPlus::IsEndOneSide(const char & User, const char & other)
{
	int row = getRow();
	int column = getColumn();
	string controller = "0000";
	for (int i = row - 1; i >= 0; --i) {
		for (int j = column - 1; j >= 0; --j) {
			controller = "0000";
			for (int direction = 5; direction <= 8; direction++)//8 is number of direction
				controller += PartnerCheck(direction, i, j, User, other, 4, true);
			if (controller != "00000000")
				return true;
		}
	}
	return false;
}


Ozyilmaz_Ahmet_111044014::ConnectFourPlus::ConnectFourPlus()
{
	//
}

Ozyilmaz_Ahmet_111044014::ConnectFourPlus::~ConnectFourPlus()
{
	cout << "ConnectFourPlus constructor" << endl;
}
