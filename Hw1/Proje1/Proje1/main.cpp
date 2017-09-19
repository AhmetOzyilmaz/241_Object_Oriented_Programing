/*Connected Four Game */
/*AHMET ÖZYILMAZ 111044014 HOMEWORK 1*/
#include"main.h"
//TODO
/***/

int CheckLeftUpCross() {
	return 0;
}
int CheckLeftDownCross() {
	return 0;

}
int CheckRightUpCross() {
	return 0;

}
int CheckRightDownCross() {
	return 0;

}
int CheckLeft() {
	return 0;

}
int CheckRight() {
	return 0;

}
int CheckUp() {
	return 0;

}
int CheckDown() {
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

	while (1) {

		if (ONE_PLAYER_VERSUS_COMPUTER == GameMode) {
			//first move  player 1
			AllMoveOperation(1);
			//second player 2
			AllMoveOperation(3);
		}
		else if (TWO_PLAYER == GameMode) {
			// first play player 1 
			AllMoveOperation(1);
			//second play player 2
			AllMoveOperation(2);
		}
	}
	
}
/*
*	Desciription : This function for one player doing all move operation
*
*
*	Input		   : Interger for which player playing 
*
*	Return Value   : if return false re take move from user again
*
*/
bool AllMoveOperation(int PlayerID){
	CurrentPlayerId = PlayerID;
	bool flag = false;

	CurrentMove = TakeMove();
	flag = MoveInputCheck();
	if (flag) {
		//if flag true this can true input i will checking position is playable
		if (IsPositionPlayable()) {
			// play move
			MovePlayer();
		}
		else {
			return false;
		}
	}
	
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
void MovePlayer() {

	int player_id = CurrentPlayerId;
	if (CurrentPlayerId == 1)
		CurrentComparor = USER1;
	else if (CurrentPlayerId == 1)
		CurrentComparor = USER2;

	int column = static_cast<int> (CurrentMove - 'A');

	
	for (auto j = SizeOfGame; j > 0; --j)
	{
		if (GameBoard[column][j] == EMTHY) {
			GameBoard[column][j] = CurrentComparor;
			IsGameOver();
			break;
		}
		else {
			//TODO bu sütün için hamle bitmiþ baþka hamle istenmeli;

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
void MoveComputer() {
	//TODO

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

bool IsPositionPlayable() {
	//TODO

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

	if (IsGameOverOneSide(USER1)){
		return 1;
	}
	else if (IsGameOverOneSide(USER2)) {
		return 2;
	}
	return -1;
}

/*
*	Desciription : This function checking is game ended for one side
*
*	Input		   : no input
*
*	Return Value : return interger if 1 user one won if  2 user2 won  if -1 game is not ender
*
*/
bool IsGameOverOneSide(char User) {
	//TODO

	LeftUpCross();
	LeftDownCross();
	RightUpCross();
	RightDownCross();
	Left();
	Right();
	Up();
	Down();
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
		cout << "Enter Game size \n" << "Game board size should be ->  \n  <  6x6, 8x8, 10x10,  ... , 20x20 >.\n";
		cin >> SizeOfGame;

		if (cin.fail()) {
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cout << "Wrong input enter integer \n";
		}
		else {
			if (!(SizeOfGame % 2)) {
				if(SizeOfGame >=6 && SizeOfGame<=20)
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

	for (auto i = 0; i < SizeOfGame; i++)
		for (auto j = 0; j < SizeOfGame; j++)
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
		cin >> CurrentMove;
		if (MoveInputCheck())
			break;
	}

	if (flag)
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

	if (CurrentMove >= 'A' + SizeOfGame || CurrentMove < 'A')
		return false;
	if (!isalpha(CurrentMove))
		return false;

	return true;
}



int main() {


	InputValidator();
	InitialBoard();
	PrintGameBoard();
	Play();

	while (1);
	return 0;
}
