#include"Config.h"

struct NeigborEnemy
{
	int posX;
	int posY;
	string NeighborEnemyCounter;
};

void InputValidator();
void PrintGameBoard();
bool MoveInputCheck(const string& command);
char TakeMove(const int& PlayerID);
bool CommandSelector(const string& command);

int MyStringCompare(const string& s1);
int CheckCounter(const int& CurComp, const int& OtherComp, int count, const int& i, const int& j);

string PartnerCheck(const int direction, const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag = false);

bool IsPositionPlayable(const int& player_id, const char& pos);
bool IsGameOverOneSide(const char& User, const char& other);
int IsGameOver();
bool AllMoveOperation(const int& PlayerID);




void SaveFile(const string& filename);
void LoadFile(const string& filename);


bool AnyMoveMore();

void Play();

void MovePlayer(const int&,const char&);
char MoveComputer();
void FindComputerMove();

void InitialBoard();
