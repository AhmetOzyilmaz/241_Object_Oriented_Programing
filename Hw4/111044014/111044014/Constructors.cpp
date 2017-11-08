#include "ConnectFour.h"

void ConnectFour::JointConstructor() {
	++GameCount;
	setGameID(GameCount);
	cout << "\n\nGame " << getGameID() << endl;
}
/*
*	This input file first line 1 element is game mode
*	second element is game board size and
*	3 element is which player will play  after loading game*/
ConnectFour::ConnectFour(char mode) {
	JointConstructor();
	cout << " Enter Board Source File or just double click enter button " << endl;
	string file;
	cin >> file;

	if (file.size() > 4) {
		LoadFileNew(file, 0);
	}
	else
		PrintGameBoard();

	SetStartPlayer();

}
ConnectFour::ConnectFour() {
	JointConstructor();
	cout << " Enter Board Source File or enter " << endl;
	string file;
	cin >> file;

	if (file.size() > 4) {
		LoadFileNew(file, 0);
	}
	else {
		NewGame();
	}
	
}
ConnectFour::ConnectFour(const string & FileName)
{
	JointConstructor();
	LoadFileNew(FileName, 0);
}
ConnectFour::ConnectFour(int row, int column, char mode) : gameSizeRow(row), gameSizeColumn(column), GameMode(mode) {
	JointConstructor();
	InitialBoard(gameSizeRow, gameSizeColumn); /*Can Be Emthy	*/
	PrintGameBoard();
}
ConnectFour::ConnectFour(const ConnectFour & other)
{
	CopyConnectedFour(other);
}
ConnectFour::~ConnectFour()
{
	for (int i = 0; i < getGameSizeRow(); ++i) {
		delete[] gameCells[i];
		gameCells[i] = nullptr;
	}
	delete[] gameCells;
	gameCells = nullptr;
}