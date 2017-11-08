#include "ConnectFour.h"

/*	Desciription : Printing screen current status of game board
*	Input		 : no input parameter
*	Return Value : no return value
*/
void ConnectFour::PrintGameBoard() {
	char a = 'A', b = 'A';
	int row = getGameSizeRow();
	int column = getGameSizeColumn();
	//cout << "GameBoard row -> " << row << endl;
	//cout << "GameBoard column -> " << column << endl;
	while (a < b + column) {
		cout << "  " << a << " ";
		a++;
	}
	cout << endl;
	for (auto i = 0; i < row; i++) {
		for (auto j = 0; j < column; j++)
			cout << "  " << GetGameBoard(i, j).GetCellValue() << " ";
		cout << "\n";
	}
}
/*
*	Desciription : This function initial board
*	Input		   : taking row and column value and resize game table
*	Return Value : no return value
*/
void ConnectFour::InitialBoard(const int& row, const int& column) {
	ReSizeGameBoard(row, column);
}
/*
*	Desciription : This function initial board before ask user
*	Input		   : no input parameter
*	Return Value : no return value
*/
void ConnectFour::InitialBoard() {
	cout << "Initial board" << endl;
	int row = 0, column = 0;
	while (1) {
		cout << "Enter Row " << endl;
		cin >> row;
		if (cin.fail()) {
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cerr << " <--->ILLEGAL<---> Wrong input enter integer \n";
		}
		else
			break;
	}
	while (1) {
		cout << "Enter Column " << endl;
		cin >> column;
		if (cin.fail()) {
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cerr << " <--->ILLEGAL<---> Wrong input enter integer \n";
		}
		else
			break;

	}
	ReSizeGameBoard(row, column);
}