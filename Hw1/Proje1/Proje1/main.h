#pragma once

#include<iostream>

using namespace std;

const int MAXSIZE = 20; // Game board max size 
int SizeOfGame = 0;
int GameMode = 0;
const int TWO_PLAYER = 2;
const int ONE_PLAYER_VERSUS_COMPUTER = 1;
char USER1 = 'X';
char USER2 = 'O';
char EMTHY = '.';
char GameBoard[MAXSIZE][MAXSIZE];
char CurrentMove = '\0';
int CurrentPlayerId = 0;
char CurrentComparor = '\0';
char OtherComparor = '\0';

int CheckCounter(const int& CurComp, const int& OtherComp, int count, const int& i, const int& j);
int CheckLeftUpCross(const int& posX,const int& posY, const char&, const char& othercomparator);
int CheckLeftDownCross(const int& posX, const int& posY, const char&, const char& othercomparator);
int CheckRightUpCross(const int& posX, const int& posY, const char&, const char& othercomparator);
int CheckRightDownCross(const int& posX, const int& pos, const char&, const char& othercomparator);


int CheckLeft(const int& posX, const int& posY, const char&, const char& othercomparator);
int CheckRight(const int& posX, const int& posY, const char&, const char& othercomparator);
int CheckUp(const int& posX, const int& posY, const char&, const char& othercomparator);
int CheckDown(const int& posX, const int& posY, const char&, const char& othercomparator);

void Play();

bool AllMoveOperation(const int& PlayerID);

void MovePlayer(const int&);

void MoveComputer();
bool IsPositionPlayable();
int IsGameOver();

bool IsGameOverOneSide(const char& User, const char& other);

void InputValidator();
void InitialBoard();
void PrintGameBoard();
char TakeMove();
bool MoveInputCheck();