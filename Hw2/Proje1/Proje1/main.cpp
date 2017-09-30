/*Connected Four Game */
/*AHMET ÖZYILMAZ 111044014 HOMEWORK 2*/
#include"main.h"

/*
*	Desciription : This function saving gameboard status
*
*
*	Input		   : conts string file name
*
*	Return Value   : no return value
*
*/
void SaveFile(const string& filename) {

	ofstream myfile;
	myfile.open(filename, std::ofstream::out | std::ofstream::app);

	if (myfile.is_open())
	{
		//Oyun modu 1 se  user vs user 2 ise user vs computer 
		//ikinci eleman oyunun size ı 

		myfile << GameMode << " " << SizeOfGame<< endl;

		for (int row = 0; row < SizeOfGame; ++row)
		{
			for (int column = 0; column < SizeOfGame; ++column)
			{
				myfile << GameBoard[row][column];
			}
			if(row < SizeOfGame -1)
			myfile << "\n";
		}
		myfile.close();

	}
	else cerr << "Unable to open file";

	cout << "Game Board Saved Correctly" << endl;

}

/*
*	Desciription : This function loading gameboard
*
*
*	Input		   : conts string file name
*
*	Return Value   : no return value
*
*/
// TODO yanlış dosya yükleme,
void LoadFile(const string& filename) {
	ifstream myReadFile;
	myReadFile.open(filename);
	string line = "";
	int size = 0;
	if (myReadFile.is_open()) {
		int column = 0,row = 0;

		if (!myReadFile.eof()) {
			getline(myReadFile, line);

			GameMode = line[0]- '0';//ilk eleman oyun modu
			SizeOfGame = line[2] - '0';//2.değişken oyunun size ı
			cout << "SizeOFgame -->" << SizeOfGame<<endl;
			cout << "GameMode -->" << GameMode << endl;

		}
			

		while (!myReadFile.eof()) {
			getline(myReadFile, line);

			for (int column = 0; column < line.size(); column++)
			{
				GameBoard[row][column] = line[column];
			}
			++row;
		}
			SizeOfGame = line.size();


	}
	cout << "Game Board Loaded Correctly" << endl;
	cout << "New Game Board is " << endl;
	PrintGameBoard();

	myReadFile.close();
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

		//first move  player 1
		AllMoveOperation(USER1PLAYERID);
		check = IsGameOver();
		PrintGameBoard();

		if (check == -1)
			break;

		if (ONE_PLAYER_VERSUS_COMPUTER == GameMode) {

			//second player 2
			AllMoveOperation(USER2PLAYERID);
			PrintGameBoard();
			check = IsGameOver();
			if (check == -1)
				break;
		}
		else if (TWO_PLAYER == GameMode) {
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
*	Desciription : 
*
*	Input		   : 
*
*	Return Value   : 
*
*/
bool CommandSelector(const string& command) {
	string filename = "";
	filename = command.substr(5, command.size());
	//cout << "File name->" << filename << endl;

	if (command.substr(0, 4).compare("SAVE") == 0) {
		SaveFile(filename);
		return true;
	}
	else if (command.substr(0, 4).compare("LOAD") == 0) {
		LoadFile(filename);
		return true;
	}


	return false;
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
bool AllMoveOperation(const int& PlayerID) {
	bool flag = false;
	string command = "" ;

	if (PlayerID != 3) {
		command = TakeMove(PlayerID);
	
		while (command[0] == '-' || command[0] == '+') {
			command = TakeMove(PlayerID);
		}

		flag = MoveInputCheck(command);
	}
	else if (PlayerID == 3) {
		FindComputerMove();
		return true;
	}
	if (flag) {
		cout << "MoveInputCheck is correct\n";
		//if flag true this can true input i will checking position is playable
		if (IsPositionPlayable(PlayerID, command[0])) {
			// play move
			//cout << "is position playable " << CurrentMove << "\n";

			MovePlayer(PlayerID, command[0]);
		}
		else {
			cerr << "Position Cannot play enter another move " << endl;
			return false;
		}
	}
	else
		cerr << "MoveInputCheck function return false\n";

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
void MovePlayer(const int& player_id,const char& CurrentMove) {
	char CurrentComparor = '\0';
	char OtherComparor = '\0';

	if (player_id == USER1PLAYERID) {
		CurrentComparor = USER1;
		OtherComparor = USER2;
	}

	else if (player_id == USER2PLAYERID) {
		CurrentComparor = USER2;
		OtherComparor = USER1;
	}


	if (player_id != COMPUTERPLAYERID){
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
}

/*
*	Desciription : This function computer automatic playin move
*
*
*	Input		   : no parameter
*
*	Return Value   : returnin if u find placable positon or returning '.' for error
*
*/
char MoveComputer() {
	//TODO
	char pos;
	/*easy mode */
	while (1) {
		srand(time(NULL));
		pos = 'A' + rand() % SizeOfGame;
		//cout <<"Computer Position " << pos << endl;
		if (IsPositionPlayable(COMPUTERPLAYERID, pos)) {
			return pos;
		}
	}
	/*hard mode */
	//todo
	return '.';
}

/*
*	Desciription : This function karþý rakibin taþýný bulucak ve oyun tahtasi içinde rakibin en uzun uzantýlý taþýnýn uzantý olan yere taþ koyucak
*
*
*	Input		   : no parameter
*
*	Return Value   : no return value
*
*/
void FindComputerMove() {

	NeigborEnemy enem[200];
	NeigborEnemy MaxEnem;
	int Sameness = 0, control = 0, MaxControl = 0;
	MaxEnem.posX = 0;
	MaxEnem.posY = 0;
	MaxEnem.NeighborEnemyCounter = "00000000";
	bool breakLoop = false;
	bool flag = true;
	char pos;
	int index = 0;
	string controller = "00000000";
	bool isPlayeable = true;


	//cout << "***************COMPUTUTER TIME " << endl;
	for (int column = SizeOfGame - 1; column >= 0; --column)
	{
		//cout << GameBoard[SizeOfGame - 1][column] << endl;
		if (GameBoard[SizeOfGame - 1][column] == USER2) {
			flag = false;
			break;
		}
	}

	if (flag) {//First Move in game
		pos = MoveComputer();
		int column = static_cast<int> (pos - 'A');
		for (int row = SizeOfGame - 1; row >= 0; --row)
		{
			if (GameBoard[row][column] == EMTHY) {
				GameBoard[row][column] = 'O';
				cout << "First Movement For Computer " << endl;
				break;
			}
		}
	}
	else {
		for (int row = 0; row < SizeOfGame; ++row)
		{
			for (int column = 0; column < SizeOfGame; ++column)
			{

				for (int i = 3; i >= 2; --i)
				{
					controller = "";

					controller += CheckLeftUpCross(row, column, 'X', 'O', SizeOfGame, i, false);
					controller += CheckLeftDownCross(row, column, 'X', 'O', SizeOfGame, i, false);
					controller += CheckRightUpCross(row, column, 'X', 'O', SizeOfGame, i, false);
					controller += CheckRightDownCross(row, column, 'X', 'O', SizeOfGame, i, false);
					controller += CheckLeft(row, column, 'X', 'O', SizeOfGame, i, false);
					controller += CheckRight(row, column, 'X', 'O', SizeOfGame, i, false);
					controller += CheckUp(row, column, 'X', 'O', SizeOfGame, i, false);
					controller += CheckDown(row, column, 'X', 'O', SizeOfGame, i, false);

					//cout <<" row "<< row << " Column " <<column <<"H\t" << h <<  "controller " << controller << endl;

					control = MyStringCompare(controller);

					if (control > MaxControl) {

						MaxControl = control;
						MaxEnem.posX = row;
						MaxEnem.posY = column;
						MaxEnem.NeighborEnemyCounter = controller;
						break;
					}
				}

			}
		}

		//cout << MaxControl << " MaxEnem.posX "<< MaxEnem.posX << " MaxEnem.posY " << MaxEnem.posY <<" MaxEnem.NeighborEnemyCounter\t" << MaxEnem.NeighborEnemyCounter  << endl;
		if (GameBoard[MaxEnem.posX - 1][MaxEnem.posY] == USER1 &&  isPlayeable) {
			//cout << "***********DEBUG1" << endl;
			//yukarý doðru
			for (int row = MaxEnem.posX - 1; row >= 0; --row)
			{
				if (GameBoard[row][MaxEnem.posY] == EMTHY) {
					GameBoard[row][MaxEnem.posY] = USER2;
					cout << "Movement For Computer " << "Position is row ->  " << row << "Column is " << MaxEnem.posY << endl;

					isPlayeable = false;
					//cout << "***********DEBUG2" << endl;
					break;
				}
			}
		}
		 if (GameBoard[MaxEnem.posX - 1][MaxEnem.posY - 1] == USER1 &&  isPlayeable) {
			//sol üst dogru
			//cout << "***********DEBUG2" << endl;
			int row = SizeOfGame;
			for (int column = MaxEnem.posY - 1; row >= 0, column >= 0; --row, --column)
			{
				if (GameBoard[row][column] == EMTHY) {
					GameBoard[row][column] = USER2;
					cout << "Movement For Computer " << "Position is row ->  " << row << "Column is " << column << endl;

					isPlayeable = false;
					//cout << "***********DEBUG2" << endl;
					break;
				}
			}
		}
		 if (GameBoard[MaxEnem.posX][MaxEnem.posY - 1] == USER1 &&  isPlayeable) {
			//sol dogru
			//cout << "***********DEBUG3" << endl;

			for (int column = MaxEnem.posY - 1; column >= 0; --column)
			{
				if (GameBoard[MaxEnem.posX][column] == EMTHY) {
					GameBoard[MaxEnem.posX][column] = USER2;
					cout << "Movement For Computer " << "Position is row ->  " << MaxEnem.posX << "Column is " << column << endl;

					isPlayeable = false;
					//cout << "***********DEBUG33" << endl;
					break;
				}
			}
		}
		 if (GameBoard[MaxEnem.posX][MaxEnem.posY + 1] == USER1 &&  isPlayeable) {
			//sağ dogru
			//cout << "***********DEBUG4" << endl;

			for (int column = MaxEnem.posY + 1; column < SizeOfGame; ++column)
			{
				if (GameBoard[MaxEnem.posX][column] == EMTHY && GameBoard[MaxEnem.posX+1][column] != EMTHY) {
					GameBoard[MaxEnem.posX][column] = USER2;
					cout << "Movement For Computer " << "Position is row ->  " << MaxEnem.posX << "Column is " << column << endl;

					isPlayeable = false;
					//cout << "***********DEBUG2" << endl;
					break;
				}
			}
		}
		 if (true == isPlayeable) {
			 //cout << "***************COMPUTUTER 11111 " << endl;
			int  column = 0;
			time_t t;
			srand(time(0));

			while (1) {
				column = rand() % SizeOfGame;
				if (column < 0)
					column *= -1;
				//cout << "DEBUG " << column << endl; 
				for (int row = SizeOfGame - 1; row >= 0, column >= 0, column < SizeOfGame; --row) {
					if (row < 0)
					{
						row = SizeOfGame - 1;
						//temp = false; 
						break;
					}
					if (GameBoard[row][column] == EMTHY) {
						GameBoard[row][column] = USER2;
						cout << "Movement For Computer " << "Position is row ->  " << row << "Column is " << column << endl;
						isPlayeable = false;
						return;
						break;
					}
				}
				if (isPlayeable == false)
					break;
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

int main() {
	char command = '.';
	while (1) {
		InputValidator();
		InitialBoard();
		PrintGameBoard();
		Play();

		cout << "if you want to quit enter q or enter different character" << endl;
		cin >> command;
		if (command == 'q' || command == 'Q')
			break;

	}

	return 0;
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

	if (false == AnyMoveMore()) {
		cout << "Game is Ended " << endl;
		cout << "Game is draw play new game" << endl;
		return -1;
	}
	if (IsGameOverOneSide(USER1, USER2)) {
		cout << "USER1 WON " << endl;
		return -1;
	}
	if (IsGameOverOneSide(USER2, USER1)) {
		cout << "USER2 WON " << endl;
		return -1;

	}
	cout << "Game is not ended " << endl;

	
	return 0;

}
bool AnyMoveMore() {
	for (int i = SizeOfGame - 1; i >= 0; --i)
	{
		for (int j = SizeOfGame - 1; j >= 0; --j)
		{
			if (GameBoard[i][j] == EMTHY) {
				return true;
			}
		}
	}
	return false;
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

	string controller = "";
	for (int i = SizeOfGame - 1; i >= 0; --i)
	{
		for (int j = SizeOfGame - 1; j >= 0; --j)
		{
			controller = "";

			controller += CheckLeftUpCross(i, j, User, other, SizeOfGame, 4, true);
			controller += CheckLeftDownCross(i, j, User, other, SizeOfGame, 4, true);
			controller += CheckRightUpCross(i, j, User, other, SizeOfGame, 4, true);
			controller += CheckRightDownCross(i, j, User, other, SizeOfGame, 4, true);
			controller += CheckLeft(i, j, User, other, SizeOfGame, 4, true);
			controller += CheckRight(i, j, User, other, SizeOfGame, 4, true);
			controller += CheckUp(i, j, User, other, SizeOfGame, 4, true);
			controller += CheckDown(i, j, User, other, SizeOfGame, 4, true);


			if (controller != "00000000") {

				//cout << "User " << CurrentPlayerId << "\t" << User << endl;
				return true;

			}


		}

	}

	return false;
}


/*
*	Desciription : This function comparing 2 string and returning number same element
*
*
*	Input		   : 2 const reference string
*
*	Return Value   : intger value
*
*/
int MyStringCompare(const string& s1) {
	int counter = 0;
	string temp = "1";
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] == temp[0]) {
			++counter;
		}
	}
	return counter;
}
int CheckCounter(const int& CurComp, const int& OtherComp, int count, const int& i, const int& j) {

	if (GameBoard[i][j] == CurComp)
		++count;
	if (GameBoard[i][j] == OtherComp)
		count = 0;
	return count;
}

string CheckLeftUpCross(const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag) {
	int counter = 0;
	auto i = 0, j = 0, l = 0;
	decltype(i) k = 0;

	for (i = posX, j = posY; i >= 0, j >= 0; --i, --j)
	{
		if (i < 0 || j < 0)
			return "0";

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == WinCounter) {
			if (flag) {
				cout << "\n Left Up Cross Won\n";
				for (int t = 0; t < WinCounter; ++t) {
					GameBoard[i + t][j + t] = comparator + 32;
					//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
				}
				PrintGameBoard();

			}

			return "1";
		}
	}
	return "0";
}
string CheckLeftDownCross(const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag) {
	int counter = 0;
	int i = 0, j = 0;

	for (i = posX, j = posY; i < size, j >= 0; ++i, --j)
	{
		if (i >= size || j < 0)
			return "0";

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == WinCounter) {
			if (flag) {
				cout << "\n  sol aþaðý hamle kazandý\n";

				for (int t = 0; t < WinCounter; ++t) {
					GameBoard[i - t][j + t] = comparator + 32;//asci lower status
															  //cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
				}
				PrintGameBoard();
			}

			return "1";
		}
	}
	return "0";
}
string CheckRightUpCross(const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag) {
	int counter = 0;
	int i = 0, j = 0;
	for (i = posX, j = posY; i >= 0, j < size; --i, ++j)
	{
		if (i < 0 || j >= size)
			return "0";

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == WinCounter) {
			if (flag) {
				cout << "\n  Right Up Cross Won\n";

				for (int t = 0; t < WinCounter; ++t) {
					GameBoard[i + t][j - t] = comparator + 32;
					//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
				}
				PrintGameBoard();

			}

			return "1";
		}
	}
	return "0";
}
string CheckRightDownCross(const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag) {
	int counter = 0;
	int i = 0, j = 0;
	for (i = posX, j = posY; i < size, j < size; ++i, ++j)
	{
		if (i >= size || j >= size)
			return "0";

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == WinCounter) {
			if (flag) {
				cout << "\n  Right Down Cross Won\n";
				for (int t = 0; t < WinCounter; ++t) {
					GameBoard[i - t][j - t] = comparator + 32;
					//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
				}
				PrintGameBoard();

			}

			return "1";
		}
	}
	return "0";
}
string CheckUp(const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag) {
	int counter = 0;
	int i = 0, j = 0;
	for (i = posX, j = posY; i >= 0; --i)
	{
		if (i < 0)
			return "0";

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == WinCounter) {
			if (flag) {
				cout << "\n  Up Move Won\n";
				for (int t = 0; t < WinCounter; ++t) {
					GameBoard[i + t][j] = comparator + 32;
					//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
				}
				PrintGameBoard();

			}

			return "1";
		}
	}
	return "0";
}
string CheckDown(const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag) {
	int counter = 0;
	int i = 0, j = 0;
	for (i = posX, j = posY; i < size; ++i)
	{
		if (i >= size)
			return "0";

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == WinCounter) {
			if (flag) {
				cout << "\n  Down Move Won\n";
				for (int t = 0; t < WinCounter; ++t) {
					GameBoard[i - t][j] = comparator + 32;
					//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
				}
				PrintGameBoard();

			}

			return "1";
		}
	}
	return "0";
}
string CheckLeft(const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag) {
	int counter = 0;
	int i = 0, j = 0;
	for (i = posX, j = posY; j >= 0; --j)
	{
		if (j < 0)
			return "0";

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == WinCounter) {
			if (flag) {
				cout << "\n  Left Move Won\n";
				for (int t = 0; t < WinCounter; ++t) {
					GameBoard[i][j + t] = comparator + 32;
					//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
				}
				PrintGameBoard();

			}
			return "1";
		}
	}
	return "0";
}
string CheckRight(const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag) {
	int counter = 0;
	int i = 0, j = 0;
	for (i = posX, j = posY; j < size; ++j)
	{
		if (j >= size)
			return "0";

		counter = CheckCounter(comparator, othercomparator, counter, i, j);

		if (counter == WinCounter) {
			if (flag) {
				cout << "\n  Down Move Won\n";
				for (int t = 0; t < WinCounter; ++t) {
					GameBoard[i][j - t] = comparator + 32;
					//cout << GameBoard[i + t][j + t] << "\t" << i+t << "\t" << j+t << endl;
				}
				PrintGameBoard();

			}

			return "1";
		}
	}
	return "0";
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

bool IsPositionPlayable(const int& player_id, const char& pos) {
	//TODO
	//cout << pos << endl;
	for (int i = SizeOfGame - 1; i >= 0; --i)
	{
		if (GameBoard[i][pos - 'A'] == EMTHY)
			return true;

	}


	return false;
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

bool MoveInputCheck(const string& command) {

	//cout << "Current MoveInputCheck " << CurrentMove << endl;
	if (command[0] >= 'A' + SizeOfGame || command[0] < 'A')
		return false;
	if (!isalpha(command[0]))
		return false;

	return true;
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
char TakeMove(const int& PlayerID ) {
	bool flag = false;
	string command = "",command2="";
	while (1) {

		cout << "if want to Save Gameboard enter 'SAVE FILE.txt' \n "
			<< "if you want to  load gameboard  from file enter 'LOAD FILE.txt' \n ";

		cout << "Enter one grater letter  move A , B, C ...\n";
		cout << "\t For : USER" << PlayerID << endl;

		cin >> command;

		if (command.size() > 3) { // "LOAD X.txt" minumum kabul edilen kýsým 
			cin >> command2;
			command2 = command + " " + command2;
			CommandSelector(command2);
			return '+';
		}
		else {
			 if (command.size()== 1) {
				if (MoveInputCheck(command));
				return command[0];
			}
			else {
				cerr << "ERROR COMMAND ENTER NEW  COMMAND " << endl;
			}
		}
	}
	return '-';
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
		cout << "  " << a << " ";
		a++;
	}
	cout << endl;
	for (auto i = 0; i < SizeOfGame; i++) {
		for (auto j = 0; j < SizeOfGame; j++)
			cout << "  " << GameBoard[i][j] << " ";
		cout << "\n";
	}
}


/*
*	Desciription : This function checking game board size and game mode
*					Cheking interger or not and for size 6x6, 8x8, 10x10,
, 20x20
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
			cerr << "Wrong input enter integer \n";
		}
		else {
			if (!(SizeOfGame % 2)) {
				if (SizeOfGame >= 4 && SizeOfGame <= 20)
					break;
			}
			else {
				cerr << "Wrong input for game size \n";
			}
		}
	}

	while (1) {
		cout << "Enter Game mode \n" << "Game mode  1 : two player game \n 2: User versus computer game \n";
		cin >> GameMode;
		if (cin.fail()) {
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cerr << "Wrong input enter integer \n";
		}
		else {
			if (GameMode >= 1 && GameMode <= 2) {
				break;
			}
			else {
				cerr << "Wrong Game Mode \n";
			}
		}
	}
	return;
}