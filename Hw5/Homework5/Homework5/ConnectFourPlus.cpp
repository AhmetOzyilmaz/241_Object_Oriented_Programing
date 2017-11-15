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
Ozyilmaz_Ahmet_111044014::ConnectFourPlus::ConnectFourPlus()
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

Ozyilmaz_Ahmet_111044014::ConnectFourPlus::~ConnectFourPlus()
{
	cout << "ConnectFourPlus constructor" << endl;
}
bool Ozyilmaz_Ahmet_111044014::ConnectFourPlus::IsEnd()
{
	cout << "Is end  func" << endl;
	return false;
}
/*
*	Desciription Why wrote ? : To play 1 round of the game
*	Input		   : no input
*	Return Value   : if return true game is over if return false game is not ended
*/
void Ozyilmaz_Ahmet_111044014::ConnectFourPlus::Play() {
	cout << "GAME IS STARTED" << endl;
	int control = 0;
	while (1) {
		cout << " Time to play for " << GetWhoIsWillPlay() << endl;
		if (1 == GetWhoIsWillPlay()) {
			cout << "*********** 1 "<< endl;

			control = MakeMove(USER1PLAYERID);
			PrintBoard();
			if (true == IsEnd()) {
				cout << "GAME IS ENDED " << endl;
				setGameisEnded(true);
				break;

			}
			SetWhoIsWillPlay(2);
		}
		if (2 == GetWhoIsWillPlay()) {
			cout << "*********** 2 " << endl;

			if ('P' == GetGameMode())
				control = MakeMove(USER2PLAYERID);
			else if ('C' == GetGameMode())
				control = MakeMove(COMPUTERPLAYERID);
			else if (true == IsEnd()) {
				cout << "GAME IS ENDED " << endl;
				setGameisEnded(true);
				break;
			}
			SetWhoIsWillPlay(1);
			PrintBoard();
		}
	}
	cout << "GAME IS END" << endl;
}
