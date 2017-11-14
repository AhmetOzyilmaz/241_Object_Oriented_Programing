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


	void CopyConnectedFour(const ConnectFour& other);
public:

	ConnectFour();
	ConnectFour(int row, int column, char mode);
	ConnectFour(int row, int column) :ConnectFour(row, column, 'S') {
		//automaticly starting with PLAYER VS COMPUTER
	}
	
	//inline const Cell** GetCell() { return gameCells; }



	
	void Play();
	void playGame();
	void ParseFirstLine(const string& line, int& mode, int& row, int& column, int& play);
	void ReSizeGameBoard(const int& row, const int& column);
	void InitialBoard(const int& row, const int& column);
	void InitialBoard();

	//End File Operation
	void PrintBoard();
	bool MoveInputCheck(const string& command);
	char TakeMove(const int& PlayerID);
	bool CommandSelector(const string& command);
	int MyStringCompare(const string& s1);
	int CheckCounter(const int& CurComp, const int& OtherComp, int count, const int& i, const int& j);
	string PartnerCheck(const int direction, const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& WinCounter, const bool& flag = false);
	bool PlayIsPlayeable(const int& direction, bool isPlayeable, const NeigborEnemy& MaxEnem, int row, int column);
	bool IsPositionPlayable(const int& player_id, const char& pos);
	bool IsEndOneSide(const char& User, const char& other);
	int IsEnd();
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

