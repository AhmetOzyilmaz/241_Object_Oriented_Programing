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



int CheckLeftUpCross();
int CheckLeftDownCross();
int CheckRightUpCross();
int CheckRightDownCross();
int CheckLeft();
int CheckRight();
int CheckUp();
int CheckDown();

void Play();

bool AllMoveOperation(int PlayerID);

void MovePlayer();

void MoveComputer();
bool IsPositionPlayable();
int IsGameOver();

bool IsGameOverOneSide(char User);

void InputValidator();
void InitialBoard();
void PrintGameBoard();
char TakeMove();
bool MoveInputCheck();