/*Connected Four Game */
/*AHMET ÖZYILMAZ 111044014 HOMEWORK 1*/
#include<iostream>
//TODO
/***/

using namespace std;


void InputValidator();

int SizeOfGame = 0;
int GameMode = 0;
char USER1 = 'X';
char USER2 = 'O';
char EMTHY = '.';


int main() {

	
	InputValidator();


	return 0;
}

/*
*	Desciription : This function checking game board size and game mode 
*					Cheking interger or not and for size 6x6, 8x8, 10x10, …, 20x20
*					Cheking game mode  should be 1 or 2
*	Input		   : no input parameter
* 
*	Return Value : no return value
*
*/

void InputValidator() {

	while (1) {
		cout << "Enter Game size \n" << "Game board size should be ->  \n  <  6x6, 8x8, 10x10, …, 20x20 >.\n";
		cin >> SizeOfGame;

		if (cin.fail()) {
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cout << "Wrong input enter integer \n";
		}
		else {
			if (!(SizeOfGame % 2)) {
				if(SizeOfGame >=6 && SizeOfGame<=20)
					break;
			}
			else {
				cout << "Wrong input for game size \n";
			}
		}
	}

	while (1) {
		cout << "Enter Game mode \n" << "Game mode  1 : two player game \n 2: User versus computer game \n";
		cin >> GameMode;
		if (cin.fail()) {
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cout << "Wrong input enter integer \n";
		}
		else {
			if (GameMode>= 1 && GameMode <= 2 ) {
				break;
			}
			else {
				cout << "Wrong Game Mode \n";
			}
		}
	}
	return;
}

/*
*	Desciription : This function initial board
*					
*	Input		   : no input parameter
*
*	Return Value : no return value
*
*/

void InitialBoard() {




}

/*
*	Desciription : Printing screen current status of game board
*
*	Input		   : no input parameter
*
*	Return Value : no return value
*
*/

void PrintGameBoard() {



}