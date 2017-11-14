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
	playGame();
	ReSizeGameBoard(getGameSizeRow(), getGameSizeColumn());
}
void ConnectFour::ReSizeGameBoard(const int& row, const int& column) {

	gameCells = new Cell*[row];
	for (int i = 0; i < row; i++)
		gameCells[i] = new Cell[column];
	setGameSizeRow(row);//2.deðiþken oyunun size ý
	setGameSizeColumn(column);//2.deðiþken oyunun size ý

	cout << endl << " New Game Size " << getGameSizeRow() << " X " << getGameSizeColumn() << endl;
}