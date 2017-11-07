#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>
#include <string>
#include <fstream>

using namespace std;


const int USER1PLAYERID = 1;
const int USER2PLAYERID = 2;
const int COMPUTERPLAYERID = 3;
const int TWO_PLAYER ='M';
const int ONE_PLAYER_VERSUS_COMPUTER = 'S';
const char USER1 = 'X';
const char USER2 = 'O';
const char EMTHY = '.';
const char SPECIALEMTHY = '*';

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
		Cell() :Cell(0, 0, '.') { CellCounter += 1;	/*Can Be Emthy	*/ }
		Cell(int PosC, int PosR, char val) :PosColumn(PosC), PosRow(PosR), CellValue(val) { CellCounter += 1;/*Can Be Emthy*/ }
		Cell(const Cell& cell) :PosColumn(cell.PosColumn), PosRow(cell.PosRow), CellValue(cell.CellValue) { CellCounter += 1;/*Can Be Emthy*/ }

		inline void SetPosRow(const int& row) { PosRow = row; }
		inline void SetPosColumn(const int& col) { PosColumn = col; }
		inline int GetPosRow() const{ return PosRow; }
		inline int GetPosColumn() const { return PosColumn; }
		inline void SetCellValue(const char& col) { CellValue = col; }
		inline char GetCellValue()const { return CellValue ; }

		Cell operator++(); // prefix  önce arttır 
		Cell operator++(int);// post fix sonra arttır 
	private:
		int PosColumn = 0;
		int  PosRow = 0;
		char CellValue = '.';
	};
	static int CellCounter;
	static int GameCount;
	Cell** gameCells;
	int gameSizeRow = 5; //default size
	int gameSizeColumn = 5; //default size
	char GameMode = 'S'; //default game mode
	int WhoIsWillPlay = 1;
	int CurrentElementCounter = 0;// 4 lü yapmaya ne kadar yakýn olduðunu tutan bir  deðiþken 
	bool isEnded = false;
	int GameID = 0;

	void CopyConnectedFour(const ConnectFour& other);
public:

	ConnectFour();
	ConnectFour(int row, int column, char mode);
	ConnectFour(int row, int column) :ConnectFour(row, column, 'S') {
		//automaticly starting with PLAYER VS COMPUTER
	}
	inline void SetWhoIsWillPlay(const int who) { WhoIsWillPlay = who; }
	inline const int GetWhoIsWillPlay() { return WhoIsWillPlay; }
	inline void setGameSizeRow(const int size) { gameSizeRow = size; }
	inline const int getGameSizeRow() { return gameSizeRow; }
	inline void setGameisEnded(const bool end) { isEnded = end; }
	inline const bool getGameisEnded() { return isEnded; }
	inline void setGameID(const int id) { GameID = id; }
	inline int getGameID() const { return GameID; }
	inline void setCurrentElementCounter(const int count) { CurrentElementCounter = count; }
	inline const int getCurrentElementCounter() { return CurrentElementCounter; }
	inline void setGameSizeColumn(const int size) { gameSizeColumn = size; }
	inline const int getGameSizeColumn() { return gameSizeColumn; }
	inline void SetGameMode(const char mode) { GameMode = mode; }
	inline const char GetGameMode() { return GameMode; }

	//inline const Cell** GetGameBoard() { return gameCells; }

	inline Cell GetGameBoard(const int& row, const int& column) { return gameCells[row][column]; }
	inline void SetGameBoard(const int& row, const int& column, const char& value) { gameCells[row][column].SetCellValue(value); }

	inline static int GetCellCounter() { return CellCounter; }
	inline static int GetGameCounter() { return GameCount; }

	void SetGameBoard(Cell c) {
		int row = c.GetPosRow();
		int column = c.GetPosColumn();
		gameCells[row][column] = c;
	}
	void Play();
	void playGame();
	void ParseFirstLine(const string& line, int& mode, int& row, int& column, int& play);
	void ReSizeGameBoard(const int& row, const int& column);
	void InitialBoard(const int& row, const int& column);
	void InitialBoard();

	//File Operation
	void SaveFile(const string& filename);
	void LoadFile(const string& filename);
	void LoadFileNew(const string& filename, const int useles);
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
	bool GameManager();
	void MovePlayer(const int&, const char&);
	char MoveComputer();
	int PlayMove();
	int PlayMove(const string& column, const int& playerID);
	void NewGame();
	bool IsBetter(ConnectFour& one, ConnectFour& two);
	void SetStartPlayer();
	/*
	operator overload part*/
	~ConnectFour();
	ConnectFour(char mode);
	ConnectFour(const ConnectFour& other);
	ConnectFour& operator=(const ConnectFour& other);
	ConnectFour(const string& FileName);

	 bool operator ==( const ConnectFour& other);
	 bool operator !=( const ConnectFour& other);

	 friend ostream& operator<<(ostream& output, const Cell& outCell);
	 friend istream& operator>>(istream& input, Cell& outCell);

	 friend bool operator ==(const Cell& first, const Cell& second);
	 friend bool operator !=(const Cell& first, const Cell& second);

};

