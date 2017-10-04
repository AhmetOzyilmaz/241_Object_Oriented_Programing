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
const int TWO_PLAYER = 1;
const int ONE_PLAYER_VERSUS_COMPUTER = 2;
const char USER1 = 'X';
const char USER2 = 'O';
const char EMTHY = '.';
char GameBoard[MAXSIZE][MAXSIZE];
int WhoIsWillPlay = 1;