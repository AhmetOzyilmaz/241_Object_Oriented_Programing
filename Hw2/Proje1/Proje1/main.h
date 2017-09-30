#include"Lib.h"

struct NeigborEnemy
{
	int posX;
	int posY;
	string NeighborEnemyCounter;
};


void InputValidator();
void PrintGameBoard();
bool MoveInputCheck();
char TakeMove(const int& PlayerID);


int MyStringCompare(const string& s1);
int CheckCounter(const int& CurComp, const int& OtherComp, int count, const int& i, const int& j);

string CheckLeftUpCross(const int& posX, const int& posY, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag = false);
string CheckLeftDownCross(const int& posX, const int& posY, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag = false);
string CheckRightUpCross(const int& posX, const int& posY, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag = false);
string CheckRightDownCross(const int& posX, const int& pos, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag = false);


string CheckLeft(const int& posX, const int& posY, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag = false);
string CheckRight(const int& posX, const int& posY, const char&, const char& othercomparato, const int& size, const int& WinCounterr, const bool& flag = false);
string CheckUp(const int& posX, const int& posY, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag = false);
string CheckDown(const int& posX, const int& posY, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag = false);
bool IsPositionPlayable(const int& player_id, const char& pos);
bool IsGameOverOneSide(const char& User, const char& other);
int IsGameOver();
bool AllMoveOperation(const int& PlayerID);




void SaveFile(const string& filename);
void LoadFile(const string& filename);


bool AnyMoveMore();

void Play();

void MovePlayer(const int&);
char MoveComputer();
void FindComputerMove();

void InitialBoard();
