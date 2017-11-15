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
	return;


}
Ozyilmaz_Ahmet_111044014::ConnectFourPlus::ConnectFourPlus()
{
	playGame();
}

Ozyilmaz_Ahmet_111044014::ConnectFourPlus::~ConnectFourPlus()
{
	cout << "ConnectFourPlus constructor" << endl;
}
void Ozyilmaz_Ahmet_111044014::ConnectFourPlus::IsEnd()
{
	cout << "Is end  func" << endl;
}


void Ozyilmaz_Ahmet_111044014::ConnectFourPlus::Play()
{
	cout << "Play  func" << endl;

}
