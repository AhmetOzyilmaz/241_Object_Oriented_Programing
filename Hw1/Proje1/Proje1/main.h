#pragma once

#include<iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>
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
	int NeighborEnemyCounter;
};

int CheckCounter(const int& CurComp, const int& OtherComp, int count, const int& i, const int& j);
int CheckLeftUpCross(const int& posX,const int& posY, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag);
int CheckLeftDownCross(const int& posX, const int& posY, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag);
int CheckRightUpCross(const int& posX, const int& posY, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag);
int CheckRightDownCross(const int& posX, const int& pos, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag);


int CheckLeft(const int& posX, const int& posY, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag);
int CheckRight(const int& posX, const int& posY, const char&, const char& othercomparato, const int& size, const int& WinCounterr, const bool& flag);
int CheckUp(const int& posX, const int& posY, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag);
int CheckDown(const int& posX, const int& posY, const char&, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag);

void Play();

bool AllMoveOperation(const int& PlayerID);

void MovePlayer(const int&);

char MoveComputer();
void FindMaxEnemy();


bool IsPositionPlayable(const int& player_id, const char& pos);

int IsGameOver();

bool IsGameOverOneSide(const char& User, const char& other);

void InputValidator();
void InitialBoard();
void PrintGameBoard();
char TakeMove();
bool MoveInputCheck();