#include "Cell.h"

class ConnectFourAbstract{

public:
	ConnectFourAbstract();
	~ConnectFourAbstract();
	virtual void LoadFileNew(const string& filename, const int useles) = 0;
	virtual void LoadFile(const string& filename) = 0;
	virtual void SaveFile(const string& filename) = 0;
	virtual void PrintBoard() = 0;
	virtual void PlayMove(char move, const int& PlayerID) = 0;
	virtual void PlayMove() = 0;
	virtual void IsEnd() = 0;
	virtual void playGame() = 0;

private:
	Cell** gameCells;
	int BoardRow = 5; //default size
	int BoardColumn = 5; //default size
	char GameMode = 'S'; //default game mode
	int WhoIsWillPlay = 1;
	int CurrentElementCounter = 0;// 4 lü yapmaya ne kadar yakýn olduðunu tutan bir  deðiþken 
	bool isEnded = false;
	int GameID = 0;

};