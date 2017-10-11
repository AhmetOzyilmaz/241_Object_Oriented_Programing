#include <iostream>
#include<iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>
#include <string>
#include <fstream>
#include <vector>


const int USER1PLAYERID = 1;
const int USER2PLAYERID = 2;
const int COMPUTERPLAYERID = 3;
const int TWO_PLAYER = 1;
const int ONE_PLAYER_VERSUS_COMPUTER = 2;
const char USER1 = 'X';
const char USER2 = 'O';
const char EMTHY = '.';

using namespace std;

struct NeigborEnemy
{
	int posX;
	int posY;
	string NeighborEnemyCounter;
};

class ConnectFour
{
private:
	class Cell
	{
	public:
		Cell() :Cell(0, 0, '.') { CellCounter+=1;	/*Can Be Emthy	*/ }
		Cell(int PosC, int PosR,char val) :PosColumn(PosC), PosRow(PosR),CellValue(val) { CellCounter += 1;/*Can Be Emthy*/ }

		inline void SetPosRow(const int& row) { PosRow = row; }
		inline void SetPosColumn(const int& col) { PosColumn = col; }
		inline int GetPosRow() { return PosRow; }
		inline int GetPosColumn() { return PosColumn; }
		inline void SetCellValue(const char& col) { CellValue = col; }
		inline const char GetCellValue() { return CellValue; }
	private:
		int PosColumn = 0;
		int  PosRow = 0;
		char CellValue = '.';
	};
	static int CellCounter;
	vector< vector<Cell> > gameCells;
	int gameSizeRow = 4; //default size
	int gameSizeColumn = 4; //default size
	int GameMode = 1; //default game mode
	int WhoIsWillPlay = 1;


public:
	
	ConnectFour() {
		InputValidator();
		InitialBoard(gameSizeRow, gameSizeColumn); 
	}
	ConnectFour(int row,int column): gameSizeRow(row),gameSizeColumn(column) {
		InputValidator();
		InitialBoard(gameSizeRow, gameSizeColumn); /*Can Be Emthy	*/ 
	}
	//TODO at least 3 constructors

	inline void SetWhoIsWillPlay(const int who) { WhoIsWillPlay = who; }
	inline const int GetWhoIsWillPlay() { return WhoIsWillPlay; }

	inline void setGameSizeRow(const int size) { gameSizeRow = size; }
	inline const int getGameSizeRow() { return gameSizeRow; }
	
	inline void setGameSizeColumn(const int size) { gameSizeColumn = size; }
	inline const int getGameSizeColumn() { return gameSizeColumn; }

	inline void SetGameMode(const int mode) { GameMode = mode; }
	inline const int GetGameMode() { return GameMode; }

	inline const vector <vector<Cell>> GetGameBoard() { return gameCells;}

	inline Cell GetGameBoard(const int& row, const int& column) { return gameCells[row][column]; }
	inline void SetGameBoard(const int& row, const int& column,const char& value) { gameCells[row][column].SetCellValue(value);	 }

	inline static int GetCellCounter() { return CellCounter; }

	void SetGameBoard(Cell c) {
		int row = c.GetPosRow();
		int column = c.GetPosColumn();
		gameCells[row][column] = c;
	}

	void Play();
	void InputValidator();
	void InitialBoard(const int& row,const int& column);

	//File Operation
	void SaveFile(const string& filename);
	void LoadFile(const string& filename);
	//End File Operation
	void PrintGameBoard();	

	bool MoveInputCheck(const string& command);
	char TakeMove(const int& PlayerID);
	bool CommandSelector(const string& command);
	int MyStringCompare(const string& s1);
	int CheckCounter(const int& CurComp, const int& OtherComp, int count, const int& i, const int& j);
	string PartnerCheck(const int direction, const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& WinCounter, const bool& flag = false);
	bool PlayIsPlayeable(const int& direction, bool isPlayeable, const NeigborEnemy& MaxEnem, int row, int column);
	bool IsPositionPlayable(const int& player_id, const char& pos);
	bool IsGameOverOneSide(const char& User, const char& other);
	int IsGameOver();
	int AllMoveOperation(const int& PlayerID);

	bool AnyMoveMore();
	void GameManager();
	void MovePlayer(const int&, const char&);
	char MoveComputer();
	void FindComputerMove();


};

