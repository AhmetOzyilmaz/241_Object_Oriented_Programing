/*Connected Four Game */
/*AHMET ÖZYILMAZ 111044014 HOMEWORK 2*/
#include"main.h"
/*
*	This input file first line 1 element is game mode 
*	second element is game board size and 
*	3 element is which player will play  after loading game*/

/*
*	Desciription : This function saving gameboard status
*	Input		   : conts string file name
*	Return Value   : no return value
*/
void SaveFile(const string& filename) {
	ofstream myfile;
	myfile.open(filename, std::ofstream::out | std::ofstream::app);
	if (myfile.is_open()){
		//Oyun modu 1 se  user vs user 2 ise user vs computer 
		//ikinci eleman oyunun size ı 
		//TODO hamle kimde kaldıysa onun idsi CurrenPlayerID olarak atanıcak

		myfile << GameMode << " " << SizeOfGame<<" "<< WhoIsWillPlay <<endl;
		for (int row = 0; row < SizeOfGame; ++row){
			for (int column = 0; column < SizeOfGame; ++column)
				myfile << GameBoard[row][column];
			if(row < SizeOfGame -1)
				myfile << "\n";
		}
		myfile.close();
	}
	else cerr << "Unable to open file";
	//cout << "Game Board Saved Correctly" << endl;
}
/*
*	Desciription : This function loading saved gameboard from file
*	Input		   : conts string file name
*	Return Value   : no return value
*/
// TODO yanlış dosya yükleme,
void LoadFile(const string& filename) {
	ifstream myReadFile;
	myReadFile.open(filename);
	string line = "";
	int size = 0;
	if (myReadFile.is_open()) {
		int column = 0,row = 0;
		getline(myReadFile, line);
		//cout << line<<endl;
		if (!myReadFile.eof()) {
			if (line.size() >= 5) {
				GameMode = line[0] - '0';//ilk eleman oyun modu
				SizeOfGame = line[2] - '0';//2.değişken oyunun size ı
				WhoIsWillPlay = line[4] - '0';//3.değişken oyunu şimdi kimin oynaması gerektiği		
			}			
			while (!myReadFile.eof()) {
				getline(myReadFile, line);
				for (int column = 0; column < line.size(); ++column)
					GameBoard[row][column] = line[column];
				++row;
			}
			SizeOfGame = row;
			cout << "Game Board Loaded Correctly\nNew Game Board is " << endl;
			PrintGameBoard();
		}
		else 
			cerr << "File is EMTHY \ Please enter new file or keep going game " << endl;	
	}
	myReadFile.close();
}
/*
*	Desciription : This function playing game respectively until one of the player win or moveable 
*					position when end
*	Input		   : no input
*	Return Value   : no return value
*/
void Play() {
	int control = 0, check = 0;
	while (1) {
		if (WhoIsWillPlay == 1){
			//Player1
			control = AllMoveOperation(USER1PLAYERID);
			if(control != 2)
				WhoIsWillPlay = 2;
		}
		 else if (WhoIsWillPlay == 2 ) {
			if(ONE_PLAYER_VERSUS_COMPUTER == GameMode)
				control = AllMoveOperation(COMPUTERPLAYERID);
			else if( TWO_PLAYER == GameMode)
				control = AllMoveOperation(USER2PLAYERID);
			WhoIsWillPlay = 1;
		}
		check = IsGameOver();
		PrintGameBoard();
		if (check == -1)
			break;
	}
}
/*
*	Desciription : //This game has 2 type command Load and Save 
*	Input		   : const string& taking command from user 
*	Return Value   :  doing operation correctly returning true else returning false
*/
bool CommandSelector(const string& command) {
	 string filename = command.substr(5, command.size());
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
*	Desciription : This function managing all player move operation 
*	Input		   : Interger for which player playing
*	Return Value   : if return integer if return 2 is load or save operation if return -1 wrong input if zero moving true
*/
int AllMoveOperation(const int& PlayerID) {
	bool flag = false;
	string command = "" ;
	if (PlayerID != 3) {
		command = TakeMove(PlayerID);
		if (command[0] == '+')
			return 2;// 
		flag = MoveInputCheck(command);
	}
	else if (PlayerID == 3) {
		FindComputerMove();
		return 0;
	}
	if (flag) {
		cout << "MoveInputCheck is correct\n";
		//if flag true this can true input i will checking position is playable
		if (IsPositionPlayable(PlayerID, command[0])) {// play move
			MovePlayer(PlayerID, command[0]);
		}
		else {
			cerr << "Position Cannot play enter another move " << endl;
			return -1;
		}
	}
	else
		cerr << "MoveInputCheck function return false\n\n\n PLEASE ENTER CORRECT MOVE";
	return -1;
}
/*
*	Desciription : This function taking one move without computer and make a move
*	Input		   : int curren player id
*					  const char& current move to make a move
*	Return Value   : No return value
*/
void MovePlayer(const int& player_id,const char& CurrentMove) {
	char CurrentComparor = '\0', OtherComparor = '\0';
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
			for (auto j = SizeOfGame - 1; j >= 0; --j){
				if (GameBoard[j][column] == EMTHY) {
					GameBoard[j][column] = CurrentComparor;
					break;
				}
			}
		}
	}
}
/*
*	Desciription : This function computer automatic playin move
*	Input		   : no parameter
*	Return Value   : returnin if u find placable positon or returning '.' for error
*/
char MoveComputer() {
	char pos;
	while (1) {
		srand(time(NULL));
		pos = 'A' + rand() % SizeOfGame;
		if (IsPositionPlayable(COMPUTERPLAYERID, pos))
			return pos;
	}
	return '.';
}

/*
*	Desciription : This function finding computer move and moving 
*	Input		   : no parameter
*	Return Value   : no return value
*/
void FindComputerMove() {
	NeigborEnemy MaxEnem;
	MaxEnem.posX = 0;
	MaxEnem.posY = 0;
	MaxEnem.NeighborEnemyCounter = "00000000";
	int  control = 0, MaxControl = 0, index = 0;
	bool flag = true ,isPlayeable = true;
	char pos;
	string controller = "00000000";
	for (int column = SizeOfGame - 1; column >= 0; --column){
		if (GameBoard[SizeOfGame - 1][column] == USER2) {
			flag = false;
			break;
		}
	}
	if (flag) {//First Move in game
		pos = MoveComputer();
		int column = static_cast<int> (pos - 'A');
		for (int row = SizeOfGame - 1; row >= 0; --row){
			if (GameBoard[row][column] == EMTHY) {
				GameBoard[row][column] = 'O';
				cout << "First Movement For Computer " << endl;
				break;
			}
		}
	}
	else {
		for (int row = 0; row < SizeOfGame; ++row){
			for (int column = 0; column < SizeOfGame; ++column){
				for (int i = 3; i >= 2; --i){
					controller = "";
					for (int direction = 1; direction <= 8; direction++)//8 is number of direction
						controller += PartnerCheck(direction,row, column, 'X', 'O', SizeOfGame, i, false);
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
		int row = 0, column = 0;
		//cout << MaxControl << " MaxEnem.posX "<< MaxEnem.posX << " MaxEnem.posY " << MaxEnem.posY <<" MaxEnem.NeighborEnemyCounter\t" << MaxEnem.NeighborEnemyCounter  << endl;
		if (GameBoard[MaxEnem.posX - 1][MaxEnem.posY] == USER1 &&  isPlayeable) {
			isPlayeable=PlayIsPlayeable(1, isPlayeable, MaxEnem, MaxEnem.posX - 1, MaxEnem.posY);
		}
		if (GameBoard[MaxEnem.posX - 1][MaxEnem.posY - 1] == USER1 &&  isPlayeable) {
			isPlayeable = PlayIsPlayeable(2, isPlayeable, MaxEnem, SizeOfGame, MaxEnem.posY - 1);
		}
		if (GameBoard[MaxEnem.posX][MaxEnem.posY - 1] == USER1 &&  isPlayeable) {
			isPlayeable = PlayIsPlayeable(3, isPlayeable, MaxEnem, MaxEnem.posX, MaxEnem.posY - 1);
		}
		if (GameBoard[MaxEnem.posX][MaxEnem.posY + 1] == USER1 &&  isPlayeable) {
			isPlayeable = PlayIsPlayeable(4, isPlayeable, MaxEnem, MaxEnem.posX, MaxEnem.posY + 1);
		}
		if (true == isPlayeable) {
			int  column = 0;
			time_t t;
			srand(time(0));
			while (1) {
				column = rand() % SizeOfGame;
				if (column < 0)
					column *= -1;
				for (int row = SizeOfGame - 1; row >= 0, column >= 0, column < SizeOfGame; --row) {
					if (row < 0){
						row = SizeOfGame - 1;
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
*	Desciription : returning isPlaceable
*	Input		   : no input parameter
*	Return Value : no return value
*/
bool PlayIsPlayeable(const int& direction,bool isPlayeable, const NeigborEnemy& MaxEnem, int row,int column) {
	for (; ; ){
		if (row < 0 || row >= SizeOfGame ) 
			break;
		if (column < 0 || column >= SizeOfGame)
			break;
		if (direction != 4) {//özel durum
			if (GameBoard[row][column] == EMTHY) {
				GameBoard[row][column] = USER2;
				cout << "Movement For Computer " << "Position is row ->  " << row << "Column is " << column << endl;
				return false;
			}
		}
		else {
			if (GameBoard[MaxEnem.posX][column] == EMTHY && GameBoard[MaxEnem.posX + 1][column] != EMTHY) {
				GameBoard[MaxEnem.posX][column] = USER2;
				cout << "Movement For Computer " << "Position is row ->  " << MaxEnem.posX << "Column is " << column << endl;
				return false;
			}
		}
		if (direction == 1)
			--row;
		else if (direction == 2)
			--row, --column;
		else if (direction == 3)
			--column;
		else if (direction == 4)
			++column;
		else if (direction == 5){}
	}
	return true;
}
/*
*	Desciription : This function initial board
*	Input		   : no input parameter
*	Return Value : no return value
*/
void InitialBoard() {
	for (auto i = 0; i < SizeOfGame; ++i)
		for (auto j = 0; j < SizeOfGame; ++j)
			GameBoard[i][j] = EMTHY;
}

/*
*	Desciription : This function checking is game ended or not
*	Input		   : no input
*	Return Value : return interger if 1 user one won if  2 user2 won  if -1 game is not ender
*/
int IsGameOver() {
	if (false == AnyMoveMore()) {
		cout << "Game is Ended " << endl;
		cout << "Game is draw play new game" << endl;
		return -1;
	}
	if (IsGameOverOneSide(USER1, USER2)) {
		cout << "<---------------->USER1 WON<---------------->" << endl;
		return -1;
	}
	if (IsGameOverOneSide(USER2, USER1)) {
		cout << "<---------------->USER2 WON<----------------> " << endl;
		return -1;
	}
	cout << "Game is not ended " << endl;
	return 0;
}
bool AnyMoveMore() {
	for (int i = SizeOfGame - 1; i >= 0; --i){
		for (int j = SizeOfGame - 1; j >= 0; --j){
			if (GameBoard[i][j] == EMTHY) 
				return true;
		}
	}
	return false;
}
/*
*	Desciription : This function checking is game ended for one side
*	Input		   : no input
*	Return Value : return interger if 1 user one won if  2 user2 won  if -1 game is not ender
*/
bool IsGameOverOneSide(const char& User, const char& other) {
	string controller = "";
	for (int i = SizeOfGame - 1; i >= 0; --i){
		for (int j = SizeOfGame - 1; j >= 0; --j){
			controller = "";
			for (int direction = 1; direction <= 8; direction++)//8 is number of direction
				controller += PartnerCheck(direction, i, j, User, other, SizeOfGame, 4, true);
			if (controller != "00000000")
				return true;
		}
	}
	return false;
}
/*
*	Desciription : This function returnin number of '1' in your string
*	Input		   : const string& s1
*	Return Value   : intger counter of "1"
*/
int MyStringCompare(const string& s1) {
	int counter = 0;
	string temp = "1";
	for (int i = 0; i < s1.size(); i++){
		if (s1[i] == temp[0]) 
			++counter;
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
/*
*	Desciription	: This function controlling given direction and size of element
*	Input			: 
*	Return Value	: return string 1 or 0
*/
string PartnerCheck(const int direction,const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& size, const int& WinCounter, const bool& flag) {
	auto counter = 0, i = 0, j = 0, l = 0;
	decltype(i) k = 0;
	for (i = posX, j = posY; ;){
		if (i < 0 || i >= size)
			break;
		if (j < 0 || j >= size)
			break;
		counter = CheckCounter(comparator, othercomparator, counter, i, j);
		if (counter == WinCounter) {
			if (flag) {
				int t = 0;
				switch (direction){
				case 1:
					for( ; t < WinCounter; ++t)
						GameBoard[i + t][j + t] = comparator + 32;
				case 2:
					for (; t < WinCounter; ++t)
						GameBoard[i - t][j + t] = comparator + 32;//asci lower status
					break;
				case 3:
					for (; t < WinCounter; ++t) 
						GameBoard[i + t][j - t] = comparator + 32;
					break;
				case 4:
					for (; t < WinCounter; ++t)
						GameBoard[i - t][j - t] = comparator + 32;
					break;
				case 5:
					for (; t < WinCounter; ++t)
						GameBoard[i + t][j] = comparator + 32;
					break;
				case 6:
					for (; t < WinCounter; ++t)
						GameBoard[i - t][j] = comparator + 32;
					break;
				case 7:
					for (; t < WinCounter; ++t)
						GameBoard[i][j + t] = comparator + 32;
					break;
				case 8:
					for (; t < WinCounter; ++t)
						GameBoard[i][j - t] = comparator + 32;
					break;
				default:
					break;
				}
				PrintGameBoard();
			}
			return "1";
		}
		switch (direction){
		case 1://LeftUpCross
			--i, --j;
		case 2://LeftDownCross
			++i, --j;
			break;
		case 3://RightUpCross
			--i, ++j;
			break;
		case 4://RightDownCross
			++i, ++j;
			break;
		case 5://Up
			--i;
			break;
		case 6://Down
			++i;
			break;
		case 7://Left
			--j;
			break;
		case 8://Right
			++j;
			break;
		default:
			break;
		}
	}
	return "0";
}
/*
*	Desciription : This function checking move legal ol illegal
*	Input		   : position
*	Return Value : if return true position is legal if false its illegal
*/

bool IsPositionPlayable(const int& player_id, const char& pos) {
	for (int i = SizeOfGame - 1; i >= 0; --i){
		if (GameBoard[i][pos - 'A'] == EMTHY)
			return true;
	}
	return false;
}

/*
*	Desciription	: This function checking input function
*	Input			: char move = entered move
*	Return Value	: if move is legal  return true  or return false
*/

bool MoveInputCheck(const string& command) {
	if (command[0] >= 'A' + SizeOfGame || command[0] < 'A')
		return false;
	if (!isalpha(command[0]))
		return false;
	return true;
}
/*
*	Desciription : This function taking move
*	Input		   : no input
*	Return Value   : returing legal move if return '-' move is not legal taking new move
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
			else 
				cerr << "ERROR COMMAND ENTER NEW  COMMAND " << endl;
		}
	}
	return '-';
}
/*	Desciription : Printing screen current status of game board
*	Input		 : no input parameter
*	Return Value : no return value
*/
void PrintGameBoard() {
	char a = 'A',b = 'A';
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
*					Cheking interger or not and for size 6x6, 8x8, 10x10, 20x20
*					Cheking game mode  should be 1 or 2
*	Input		 : no input parameter
*	Return Value : no return value */
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
			else 
				cerr << "Wrong input for game size \n";
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
			else 
				cerr << "Wrong Game Mode \n";
		}
	}
	return;
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