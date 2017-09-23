/*Connected Four Game */
/*AHMET ÖZYILMAZ 111044014 HOMEWORK 1*/
#include"main.h"

//TODO
/***/


int CheckCounter(const int& CurComp, const int& OtherComp , int count,const int& i,const int& j) {

	if (GameBoard[i][j] == CurComp)
		++count;
	if (GameBoard[i][j] == OtherComp)
		count = 0;
	return count;
}
int CheckLeftUpCross(const int& posX,const int& posY, const char& comparator , const char& othercomparator) {
	int counter = 0;
	int i = 0, j = 0,k = 0 , l = 0;
	for ( i = posX , j = posY; i >= 0 , j >= 0; --i , --j)
	{
		if (i < 0 || j < 0)
			return 0;

			counter = CheckCounter(comparator, othercomparator,counter,i,j);

			if (counter == 4) {
				cout << "\n  sol yukarý hamle kazandý\n";
				for (int t = 0; t < 4; ++t) {
					GameBoard[i+t][j+t] = comparator + 32;
					//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
				}
				PrintGameBoard();
				return 1;
			}
	}
	return 0;
}
int CheckLeftDownCross(const int& posX, const int& posY, const char& comparator, const char& othercomparator) {
	int counter = 0;
	int i = 0, j = 0;

	for (i = posX, j = posY; i < SizeOfGame, j >= 0; ++i, --j)
	{
		if (i >= SizeOfGame || j < 0)
			return 0;

		counter = CheckCounter(comparator, othercomparator, counter,i,j);

		if (counter == 4) {
			cout << "\n  sol aþaðý hamle kazandý\n";
			for (int t = 0; t < 4; ++t) {
				GameBoard[i - t][j + t] = comparator + 32;//asci lower status
				//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
			}
			PrintGameBoard();
			return 1;
		}
	}
	return 0;
}
int CheckRightUpCross(const int& posX, const int& posY, const char& comparator, const char& othercomparator) {
	int counter = 0;
	int i = 0, j = 0;
	for (i = posX, j = posY; i >= 0, j < SizeOfGame; --i, ++j)
	{
		if (i < 0 || j >= SizeOfGame)
			return 0;

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == 4) {
			cout << "\n  aþaðý up kazandý\n";
			for (int t = 0; t < 4; ++t) {
				GameBoard[i + t][j - t] = comparator + 32;
				//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
			}
			PrintGameBoard();
			return 1;
		}
	}
	return 0;
}
int CheckRightDownCross(const int& posX, const int& posY, const char& comparator, const char& othercomparator) {
	int counter = 0;
	int i = 0, j = 0;
	for (i = posX, j = posY; i < SizeOfGame , j < SizeOfGame; ++i, ++j)
	{
		if (i >= SizeOfGame || j >= SizeOfGame)
			return 0;

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == 4) {
			cout << "\n  saðaþaðý hamle kazandý\n";
			for (int t = 0; t < 4; ++t) {
				GameBoard[i - t][j - t] = comparator + 32;
				//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
			}
			PrintGameBoard();
			return 1;
		}
	}
	return 0;
}
int CheckUp(const int& posX, const int& posY, const char& comparator, const char& othercomparator) {
	int counter = 0;
	int i = 0, j = 0;
	for (i = posX , j = posY; i >= 0; --i)
	{
		if (i < 0 )
			return 0;

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == 4) {
			cout << "\n  yukarý hamle kazandý\n";
			for (int t = 0; t < 4; ++t) {
				GameBoard[i + t][j] = comparator + 32;
				//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
			}
			PrintGameBoard();
			return 1;
		}
	}
	return 0;
}

int CheckDown(const int& posX, const int& posY, const char& comparator, const char& othercomparator) {
	int counter = 0;
	int i = 0, j = 0;
	for (i = posX, j = posY; i < SizeOfGame; ++i)
	{
		if (i <= SizeOfGame)
			return 0;

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == 4) {
			cout << "\n  aþaðý hamle kazandý\n";
			for (int t = 0; t < 4; ++t) {
				GameBoard[i - t][j] = comparator + 32;
				//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
			}
			PrintGameBoard();
			return 1;
		}
	}
	return 0;
}
int CheckLeft(const int& posX, const int& posY, const char& comparator, const char& othercomparator) {
	int counter = 0;
	int i = 0, j = 0;
	for (i = posX, j = posY; j >= 0; --j)
	{
		if (j < 0 )
			return 0;

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == 4) {
			cout << "\n  sola hamle kazandý\n";
			for (int t = 0; t < 4; ++t) {
				GameBoard[i][j + t] = comparator + 32;
				//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
			}
			PrintGameBoard();
			return 1;
		}
	}
	return 0;
}
int CheckRight(const int& posX, const int& posY, const char& comparator, const char& othercomparator) {
	int counter = 0;
	int i = 0, j = 0;
	for (i = posX, j = posY; j < SizeOfGame; ++j)
	{
		if (j >= SizeOfGame)
			return 0;

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == 4) {
			cout << "\n  aþaðý hamle kazandý\n";
			for (int t = 0; t < 4; ++t) {
				GameBoard[i][j - t] = comparator + 32;
				//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
			}
			PrintGameBoard();
			return 1;
		}
	}
	return 0;
}

/*
*	Desciription : This function playing game while one side won
*
*
*	Input		   : no input
*
*	Return Value   : no return value
*
*/

void Play() {
	int control = 0;
	int check = 0;
	while (1) {
		if (ONE_PLAYER_VERSUS_COMPUTER == GameMode) {
			//first move  player 1
			AllMoveOperation(USER1PLAYERID);
			PrintGameBoard();
			check = IsGameOver();

			if (check == -1)
				break;
			else
				PrintGameBoard();

			//second player 2
			AllMoveOperation(USER2PLAYERID);
			PrintGameBoard();
			 check = IsGameOver();
			 if (check == -1)
				 break;
			
		}
		else if (TWO_PLAYER == GameMode) {
			// first play player 1 
			AllMoveOperation(USER1PLAYERID);
			PrintGameBoard();
			check = IsGameOver();
			 if (check == -1)
				 break;
			

			//second play player 2
			AllMoveOperation(COMPUTERPLAYERID);
			PrintGameBoard();
			check = IsGameOver();
			 if (check == -1)
				 break;
			

		}
	}
	
}
/*
*	Desciription : This function for one player doing all move operation
*					if player id 1 is user1 if  player id  2 user2 if player id 3 is computer game
*
*	Input		   : Interger for which player playing 
*
*	Return Value   : if return false re take move from user again
*
*/
bool AllMoveOperation(const int& PlayerID){
	bool flag = false;

	if (PlayerID != 3) {
		CurrentMove = TakeMove();
		flag = MoveInputCheck();
	}
	else if (PlayerID == 3) {
		MovePlayer(PlayerID);
		return true;
	}
	if (flag) {
		cout << "MoveInputCheck is correct\n";
		//if flag true this can true input i will checking position is playable
		if (IsPositionPlayable(PlayerID,CurrentMove)) {
			// play move
			//cout << "is position playable " << CurrentMove << "\n";

			MovePlayer(PlayerID);
		}
		else {
			cout << "Position Cannot play enter another move " << endl;
			return false;
		}
	}
	else
		cout << "MoveInputCheck func return false\n";

	//cout << "AllMoveOperation func return false\n";

	return false;
}
/*
*	Desciription : This function play one move 
*
*
*	Input		   : 
*
*	Return Value   :
*
*/
void MovePlayer(const int& player_id) {

	if (player_id == USER1PLAYERID) {
		CurrentComparor = USER1;
		OtherComparor   = USER2;
	}

	else if (player_id == USER2PLAYERID) {
		CurrentComparor = USER2;
		OtherComparor   = USER1;
	}
   
	if(player_id == COMPUTERPLAYERID) {
		CurrentComparor = USER2;
		OtherComparor = USER1;
		CurrentMove = MoveComputer();
	}

	if (CurrentMove >= 'A' &&  CurrentMove <= 'Z') {
		int column = static_cast<int> (CurrentMove - 'A');

		for (auto j = SizeOfGame - 1; j >= 0; --j)
		{
			if (GameBoard[j][column] == EMTHY) {
				GameBoard[j][column] = CurrentComparor;
				break;
			}
			else {
				//TODO bu sütün için hamle bitmiþ baþka hamle istenmeli;

			}
		}
	}
}

/*
*	Desciription : This function computor automatic playin move
*
*
*	Input		   : 
*
*	Return Value   : 
*
*/
char MoveComputer() {
	//TODO
	char pos;
	/*easy mode */
	while (1) {
		srand(time(NULL));
		pos = 'A' + rand() % SizeOfGame;
		cout <<"Computer Position " << pos << endl;
		if (IsPositionPlayable(COMPUTERPLAYERID, pos)) {
			return pos;
		}
	}
	/*hard mode */
		//todo
	return '.';
}


/*
*	Desciription : This function checking move legal ol illegal
*					
*					
*	Input		   : position
*
*	Return Value : if return true position is legal if false its illegal
*
*/

bool IsPositionPlayable(const int& player_id,const char& pos) {
	//TODO
	cout << pos << endl;
	for (int i = SizeOfGame-1; i >= 0 ; --i)
	{
		if (GameBoard[i][pos - 'A'] == EMTHY)
			return true;

	}
		

	return false;
}
/*
*	Desciription : This function checking is game ended or not 
*
*	Input		   : no input
*
*	Return Value : return interger if 1 user one won if  2 user2 won  if -1 game is not ender
*
*/
int IsGameOver() {

	if (IsGameOverOneSide(USER1,USER2)){
		cout << "USER1 WON " << endl;
		return -1;
	}
	if (IsGameOverOneSide(USER2,USER1)) {
		cout << "USER2 WON " << endl;
		return -1;

	}
	cout << "Game is not ended " << endl;
	return 0;

}

/*
*	Desciription : This function checking is game ended for one side
*
*	Input		   : no input
*
*	Return Value : return interger if 1 user one won if  2 user2 won  if -1 game is not ender
*
*/
bool IsGameOverOneSide(const char& User, const char& other) {
	//TODO

	int controller = 0;
	for (int  i = SizeOfGame-1; i >= 0; --i)
	{
		for (int j = SizeOfGame - 1; j >= 0; --j)
		{
			controller = 0;

			controller +=CheckLeftUpCross( i,j, User, other);
			controller += CheckLeftDownCross(i, j, User, other);
			controller += CheckRightUpCross(i, j, User, other);
			controller += CheckRightDownCross(i, j, User, other);
			controller += CheckLeft(i, j, User, other);
			controller += CheckRight(i, j, User, other);
			controller += CheckUp(i, j, User, other);
			controller += CheckDown(i, j, User, other);


			if (controller != 0) {
				cout << "User " << CurrentPlayerId << "\t" << User << endl;
				return true;

			}
		}
		
	}

	return false;
}
/*
*	Desciription : This function checking game board size and game mode 
*					Cheking interger or not and for size 6x6, 8x8, 10x10, …, 20x20
*					Cheking game mode  should be 1 or 2
*	Input		   : no input parameter
* 
*	Return Value : no return value
*
*/

void InputValidator() {

	while (1) {
		cout << "Enter Game size \n" << "Game board size should be ->  \n  <  4 x 4 , 6x6, 8x8, 10x10,  ... , 20x20 >.\n";
		cin >> SizeOfGame;

		if (cin.fail()) {
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cout << "Wrong input enter integer \n";
		}
		else {
			if (!(SizeOfGame % 2)) {
				if(SizeOfGame >=4 && SizeOfGame<=20)
					break;
			}
			else {
				cout << "Wrong input for game size \n";
			}
		}
	}

	while (1) {
		cout << "Enter Game mode \n" << "Game mode  1 : two player game \n 2: User versus computer game \n";
		cin >> GameMode;
		if (cin.fail()) {
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cout << "Wrong input enter integer \n";
		}
		else {
			if (GameMode>= 1 && GameMode <= 2 ) {
				break;
			}
			else {
				cout << "Wrong Game Mode \n";
			}
		}
	}
	return;
}

/*
*	Desciription : This function initial board
*					
*	Input		   : no input parameter
*
*	Return Value : no return value
*
*/

void InitialBoard() {

	for (auto i = 0; i < SizeOfGame; ++i)
		for (auto j = 0; j < SizeOfGame; ++j)
			GameBoard[i][j] = EMTHY;
}

/*
*	Desciription : Printing screen current status of game board
*
*	Input		   : no input parameter
*
*	Return Value : no return value
*
*/

void PrintGameBoard() {

	char a = 'A';
	char b = 'A';
	while (a < b + SizeOfGame) {
		cout << "  " <<a<< " ";
		a++;
	}
	cout << endl;
	for (auto i = 0; i < SizeOfGame; i++) {
		for (auto j = 0; j < SizeOfGame; j++)
			cout <<"  " << GameBoard[i][j] << " ";
		cout << "\n";
	}
}

/*
*	Desciription : This function taking move
*
*
*	Input		   : no input
*
*	Return Value   : returing legal move if return '-' move is not legal taking new move
*
*/
char TakeMove() {
	bool flag = false;
	while (1) {
		cout << "Enter one grater letter  move A , B, C ...\n";
		cout << "\t For : USER" << CurrentPlayerId << endl;
		cin >> CurrentMove;
		if (MoveInputCheck())
			break;
	}

	if (!flag)
		return CurrentMove
		;
	else
		return '-';
}

/*
*	Desciription : This function checking input function
*
*
*	Input		   : char move = entered move
*
*	Return Value   : if move is legal  return true  or return false
*
*/

bool MoveInputCheck() {

	//cout << "Current MoveInputCheck " << CurrentMove << endl;
	if (CurrentMove >= 'A' + SizeOfGame || CurrentMove < 'A')
		return false;
	if (!isalpha(CurrentMove))
		return false;

	return true;
}



int main() {
	char command = '.';
	while (1) {
		InputValidator();
		InitialBoard();
		PrintGameBoard();
		Play();

		cout << "if you want to quit enter q or enter differen character" << endl;
		cin >> command;
		if (command == 'q' || command == 'Q')
			break;

	}
		
	cin >> command;
	return 0;
}
