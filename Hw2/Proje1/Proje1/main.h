
#include<iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

const int MAXSIZE = 20; // Game board max size 
const int USER1PLAYERID = 1;
const int USER2PLAYERID = 2;
const int COMPUTERPLAYERID = 3;
int SizeOfGame = 0;
int GameMode = 0;
const int TWO_PLAYER = 2;
const int ONE_PLAYER_VERSUS_COMPUTER = 1;
const char USER1 = 'X';
const char USER2 = 'O';
const char EMTHY = '.';

char GameBoard[MAXSIZE][MAXSIZE];
char CurrentMove = '\0';
int CurrentPlayerId = 0;
char CurrentComparor = '\0';
char OtherComparor = '\0';


struct NeigborEnemy
{
	int posX;
	int posY;
	string NeighborEnemyCounter;
};

void SaveFile(const string& filename);
void LoadFile(const string& filename);


bool AnyMoveMore();

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

void Play();

bool AllMoveOperation(const int& PlayerID);

void MovePlayer(const int&);

char MoveComputer();
void FindComputerMove();


bool IsPositionPlayable(const int& player_id, const char& pos);

int IsGameOver();

bool IsGameOverOneSide(const char& User, const char& other);

void InputValidator();
void InitialBoard();
void PrintGameBoard();
char TakeMove();
bool MoveInputCheck();