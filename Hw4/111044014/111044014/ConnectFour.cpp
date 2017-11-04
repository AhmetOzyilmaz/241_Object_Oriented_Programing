#include "ConnectFour.h"
/*
*	This input file first line 1 element is game mode
*	second element is game board size and
*	3 element is which player will play  after loading game*/

ConnectFour::ConnectFour() {
	++GameCount;
	setGameID(GameCount);
	cout << "\n\nGame " << getGameID() << endl;
	InitialBoard(5, 5);
	PrintGameBoard();
}
ConnectFour::ConnectFour(int row, int column, int mode) : gameSizeRow(row), gameSizeColumn(column), GameMode(mode) {
	++GameCount;
	setGameID(GameCount);
	cout << "\n\nGame " << getGameID() << endl;
	InitialBoard(gameSizeRow, gameSizeColumn); /*Can Be Emthy	*/
	PrintGameBoard();
}
ConnectFour::ConnectFour(const string& FileName) {
	LoadFile(FileName);
}
/*
*	Desciription : This function saving gameboard status
*	Input		   : conts string file name
*	Return Value   : no return value
*/
void ConnectFour::Play() {
	char command = '.';
	bool isEnded = GameManager();
	if (isEnded) {
		cout << "if you want to quit enter q or enter different character" << endl;
		cin >> command;
		if (command == 'q' || command == 'Q')
			--GameCount;
		else {
			cout << "\n\n************************************New Game*******************\\n" << endl;
			NewGame();
		}
	}
}
/*
*	Desciription : This function playing game respectively until one of the player win or moveable
*					position when end
*	Input		   : no input
*	Return Value   : if return true game is over if return false game is not ended
*/
bool ConnectFour::GameManager() {
	int control = 0, check = 0;
	while (1) {

	if (GetWhoIsWillPlay() == 1) {
		//Player1
		control = AllMoveOperation(USER1PLAYERID);
		if (control != 2 && control != -1)
			SetWhoIsWillPlay(2);
	}
	else if (GetWhoIsWillPlay() == 2) {
		//cout << "GetGameMode\t" << GetGameMode()<< endl;
		//cout << "GetWhoIsWillPlay()\t" << GetWhoIsWillPlay() << endl;
		if (ONE_PLAYER_VERSUS_COMPUTER == GetGameMode())
			control = AllMoveOperation(COMPUTERPLAYERID);
		else if (TWO_PLAYER == GetGameMode())
			control = AllMoveOperation(USER2PLAYERID);
		if (control != 2 && control != -1)
			SetWhoIsWillPlay(1);
	}
	check = IsGameOver();
	if (check == -1) {
		setGameisEnded(true);
		break;
		return true;
	}
	PrintGameBoard();

	}
	return false;
}
/*
*	Desciription : This function managing all player move operation
*	Input		   : Interger for which player playing
*	Return Value   : if return integer if return 2 is load or save operation if return -1 wrong input if zero moving true
*/
int ConnectFour::AllMoveOperation(const int& PlayerID) {
	bool flag = false;
	string move = "";
	if (PlayerID != 3) {
		move = TakeMove(PlayerID);
		while (move[0] == '-' || move[0] == '+')
			move = TakeMove(PlayerID);
		return PlayMove(move, PlayerID);
	}
	else if (PlayerID == 3) {
		return PlayMove();
	}
	return -1;
}
/*
*	Desciription : This function taking move
*	Input		   : no input
*	Return Value   : returing legal move if return '-' move is not legal taking new move
*/
char ConnectFour::TakeMove(const int& PlayerID) {
	bool flag = false;
	string command = "", command2 = "";
	while (1) {

		cout << "\n\nGAME " << getGameID() << endl;
		PrintGameBoard();
		cout << "if want to Save Gameboard enter 'SAVE FILE.txt' \n "
			<< "if you want to  load gameboard  from file enter 'LOAD FILE.txt' \n "
			<< "Enter one grater letter  move A , B, C ...\n"
			<< "\t For : USER" << PlayerID << endl;
		cin >> command;
		if (command.size() > 3) { // "LOAD X.txt" minumum kabul edilen kýsým 
			cin >> command2;
			command2 = command + " " + command2;
			CommandSelector(command2);
			return '+';
		}
		else {
			if (command.size() == 1) {
				if (MoveInputCheck(command))
					return command[0];
			}
			else
				cerr << "<--->ILLEGAL<---> ERROR COMMAND ENTER NEW  COMMAND " << endl;
		}
	}
	return '-';
}
/*
*	Desciription : This function it dont take parameter playing for computer is taking parameter will play for user
*	Input		   : no parameter
*	Return Value   : no return value
*/
int  ConnectFour::PlayMove() {
	NeigborEnemy MaxEnem;
	MaxEnem.posX = 0;
	MaxEnem.posY = 0;
	MaxEnem.NeighborEnemyCounter = "00000000";
	int  control = 0, MaxControl = 0, index = 0;
	const int rowSize = getGameSizeRow(); 
	const int columnSize = getGameSizeColumn();
	bool flag = true, isPlayeable = true;
	char pos;
	string controller = "00000000";
	for (int column = columnSize - 1; column >= 0; --column) {
		if (GetGameBoard(rowSize - 1, column).GetCellValue() == USER2) {
			flag = false;
			break;
		}
	}
	if (flag) {//First Move in game
		pos = MoveComputer();
		int column = static_cast<int> (pos - 'A');
		for (int row = rowSize - 1; row >= 0; --row) {
			if (GetGameBoard(row, column).GetCellValue() == EMTHY) {
				SetGameBoard(row, column, 'O');
				cout << "Movement For Computer " << "Position is row ->  " << row << "\tColumn is " << column << endl;
				break;
			}
		}
	}
	else {
		for (int row = 0; row < rowSize; ++row) {
			for (int column = 0; column < columnSize; ++column) {
				for (int i = 3; i >= 2; --i) {
					controller = "";
					for (int direction = 1; direction <= 8; ++direction)//8 is number of direction
						controller += PartnerCheck(direction, row, column, 'X', 'O', i, false);
					control = MyStringCompare(controller);
					if (control > MaxControl) {
						MaxControl = control;
						MaxEnem.posX = row;
						MaxEnem.posY = column;
						MaxEnem.NeighborEnemyCounter = controller;
						setCurrentElementCounter(i);
						break;
					}
				}
			}
		}
		int row = 0, column = 0;
		cout <<endl<< MaxControl << " MaxEnem.posX " 
			<< MaxEnem.posX << " MaxEnem.posY " << MaxEnem.posY 
			<< " MaxEnem.NeighborEnemyCounter\t" 
			<< MaxEnem.NeighborEnemyCounter << endl;

		if (MaxEnem.posX - 1 >= 0 && gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue()==EMTHY)
			if (GetGameBoard(MaxEnem.posX - 1, MaxEnem.posY).GetCellValue() == USER1 &&  isPlayeable)
				isPlayeable = PlayIsPlayeable(1, isPlayeable, MaxEnem, MaxEnem.posX - 1, MaxEnem.posY);

		if (MaxEnem.posX - 1 >= 0 && MaxEnem.posY - 1 >= 0 &&  gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == EMTHY)
			if (GetGameBoard(MaxEnem.posX - 1, MaxEnem.posY - 1).GetCellValue() == USER1 &&  isPlayeable)
				isPlayeable = PlayIsPlayeable(2, isPlayeable, MaxEnem, MaxEnem.posX - 1, MaxEnem.posY - 1);
		if (MaxEnem.posY - 1 >= 0 && gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == EMTHY)
			if (GetGameBoard(MaxEnem.posX, MaxEnem.posY - 1).GetCellValue() == USER1 &&  isPlayeable)
				isPlayeable = PlayIsPlayeable(3, isPlayeable, MaxEnem, MaxEnem.posX, MaxEnem.posY - 1);
		if (MaxEnem.posY + 1 < columnSize && gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == EMTHY)
			if (GetGameBoard(MaxEnem.posX, MaxEnem.posY + 1).GetCellValue() == USER1 &&  isPlayeable)
				isPlayeable = PlayIsPlayeable(4, isPlayeable, MaxEnem, MaxEnem.posX, MaxEnem.posY + 1);
		if (true == isPlayeable ) {
			int  column = 0;
			time_t t;
			srand(time(0));
			while (1) {
				cout << "While" << endl;
				column = rand() % columnSize;
				if (column < 0)
					column *= -1;

				for (int row = rowSize - 1; ; --row) {

					if (column < 0 || column >= columnSize || row < 0) {
						break;
					}
					if (gameCells[row][column].GetCellValue() == EMTHY && gameCells[row][column].GetCellValue() != ' ') {
						gameCells[row][column].SetCellValue(USER2);
						cout << "Movement For Computer " << "Position is row ->  " << row << "\tColumn is " << column << endl;
						isPlayeable = false;
						break;
					}
				
				}
				if (isPlayeable == false)
					break;
			}
		
		}
	}

	return 0;
}
int ConnectFour::PlayMove(const string& move, const int& PlayerID) {
	bool flag = false;
	if (move[0] == '+')
		return 2;// 
	flag = MoveInputCheck(move);
	if (flag) {
		cout << "MoveInputCheck is correct\n";
		//if flag true this can true input i will checking position is playable
		if (IsPositionPlayable(PlayerID, move[0])) {// play move
			MovePlayer(PlayerID, move[0]);
			return 0;
		}
		else {
			cerr << " <--->ILLEGAL<---> Position Cannot play enter another move " << endl;
			return -1;
		}
	}
	else
		cerr << "<--->ILLEGAL<---> MoveInputCheck function return false\n\n\n PLEASE ENTER CORRECT MOVE";
}
/*
*	Desciription : //This game has 2 type command Load and Save
*	Input		   : const string& taking command from user
*	Return Value   :  doing operation correctly returning true else returning false
*/
bool ConnectFour::CommandSelector(const string& command) {
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
*	Desciription : This function saving gameboard status
*	Input		   : conts string file name
*	Return Value   : no return value
*/
bool ConnectFour::IsBetter(ConnectFour& one, ConnectFour& two) {
	if (one.getCurrentElementCounter() > two.getCurrentElementCounter())
		return true;
	return false;
}
ConnectFour::~ConnectFour()
{
	for (int i = 0; i < getGameSizeRow(); ++i) {
			delete[] gameCells[i];
			gameCells[i] = nullptr;
	}
	delete[] gameCells;
	gameCells = nullptr;
}
void ConnectFour::CopyConnectedFour(const ConnectFour& other) {
	gameSizeRow = other.gameSizeRow;
	gameSizeColumn = other.gameSizeColumn;
	WhoIsWillPlay = other.WhoIsWillPlay;
	GameMode = other.GameMode;
	CurrentElementCounter = other.CurrentElementCounter;
	isEnded = other.isEnded;
	GameID = other.GameID;

	ReSizeGameBoard(gameSizeRow, gameSizeColumn);

	for (int i = 0; i < gameSizeRow; ++i) {
		for (int j = 0; j < gameSizeColumn; ++j) {
			gameCells[i][j] = other.gameCells[i][j];
		}
	}
}
ConnectFour::ConnectFour(const ConnectFour & other)
{
	CopyConnectedFour(other);
}

ConnectFour & ConnectFour::operator=(const ConnectFour& other)
{
	for (int i = 0; i < gameSizeRow; ++i) 
		delete[] gameCells[i];
	delete[]gameCells;
	CopyConnectedFour(other);
	return *this;
}


bool ConnectFour::operator==(const ConnectFour & other)
{
	if (gameSizeRow != other.gameSizeRow)
		return false;
	if (gameSizeColumn != other.gameSizeColumn)
		return false;
	for (int i = 0; i < gameSizeRow; ++i) {
		for (int j = 0; j < gameSizeColumn; ++j) {
			if (gameCells[i][j].GetCellValue() != other.gameCells[i][j].GetCellValue())
				return false;
		}
	}
	return true;
}

bool ConnectFour::operator!=(const ConnectFour & other)
{
	return !(*this == other);
}

void ConnectFour::ReSizeGameBoard(const int& row, const int& column) {

	
	gameCells = new Cell*[row];
	for (int i = 0; i < row; i++)
		gameCells[i] = new Cell[column];

	setGameSizeRow(row);//2.değişken oyunun size ı
	setGameSizeColumn(column);//2.değişken oyunun size ı

	cout << "New Game Size" << getGameSizeRow() << " X " << getGameSizeColumn() << endl; 
}
void ConnectFour::NewGame() {
	playGame();
	InitialBoard(gameSizeRow, gameSizeColumn);
	PrintGameBoard();
	SetWhoIsWillPlay(USER1PLAYERID);
}
/*
*	Desciription : This function computer automatic playin move
*	Input		   : no parameter
*	Return Value   : returnin if u find placable positon or returning '.' for error
*/
char ConnectFour::MoveComputer() {
	char pos;
	while (1) {
		srand(time(NULL));
		pos = 'A' + rand() % getGameSizeColumn();
		if (IsPositionPlayable(COMPUTERPLAYERID, pos))
			return pos;
	}
	return '.';
}
/*
*	Desciription : returning isPlaceable
*	Input		   : no input parameter
*	Return Value : if return false means move is played
*/
bool ConnectFour::PlayIsPlayeable(const int& direction, bool isPlayeable, const NeigborEnemy& MaxEnem, int row, int column) {
	const int rowSize = getGameSizeRow(), columnSize = getGameSizeColumn();

	for (; ; ) {
		cout << "Sonsuz" << endl;
		if (row < 0 || row >= rowSize)
			break;
		if (column < 0 || column >= columnSize)
			break;
		if (direction != 4) {//özel durum
			if (GetGameBoard(row, column).GetCellValue() == EMTHY) {
				SetGameBoard(row, column, USER2);
				cout << "***** Movement For Computer " << "Position is row ->  " << row << "Column is " << column << endl;
				return false;
			}
		}
		else if (direction == 4) {
			if (MaxEnem.posX + 1 < rowSize && MaxEnem.posX + 1 >= 0) {
				if (GetGameBoard(MaxEnem.posX, column).GetCellValue() == EMTHY && GetGameBoard(MaxEnem.posX + 1, column).GetCellValue() != EMTHY) {
					SetGameBoard(MaxEnem.posX, column, USER2);
					cout << "Movement For Computer " << "Position is row ->  " << MaxEnem.posX << "Column is " << column << endl;
					return false;
				}
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
		else if (direction == 5) {}
	}
	return true;
}
/*
*	Desciription : This function checking is game ended or not
*	Input		   : no input
*	Return Value : return interger if 1 user one won if  2 user2 won  if -1 game is not ender
*/
int ConnectFour::IsGameOver() {
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
bool ConnectFour::AnyMoveMore() {
	int row = getGameSizeRow();
	int column = getGameSizeColumn();
	for (int i = row - 1; i >= 0; --i) {
		for (int j = column - 1; j >= 0; --j) {
			if (GetGameBoard(i, j).GetCellValue() == EMTHY)
				return true;
		}
	}
	return false;
}
/*
*	Desciription	: This function controlling given direction and size of element
*	Input			:
*	Return Value	: return string 1 or 0
*/
string ConnectFour::PartnerCheck(const int direction, const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& WinCounter, const bool& flag) {
	int row = getGameSizeRow();
	int column = getGameSizeColumn();
	auto counter = 0, i = 0, j = 0, l = 0;
	decltype(i) k = 0;
	for (i = posX, j = posY; ;) {
		if (i < 0 || i >= row)
			break;
		if (j < 0 || j >= column)
			break;
		counter = CheckCounter(comparator, othercomparator, counter, i, j);
		if (counter == WinCounter) {
			if (flag) {
				int t = 0;
				switch (direction) {
				case 1:
					for (; t < WinCounter; ++t)
						SetGameBoard(i + t, j + t, comparator + 32);
				case 2:
					for (; t < WinCounter; ++t)
						SetGameBoard(i - t, j + t, comparator + 32);
					break;
				case 3:
					for (; t < WinCounter; ++t)
						SetGameBoard(i + t, j - t, comparator + 32);
					break;
				case 4:
					for (; t < WinCounter; ++t)
						SetGameBoard(i - t, j - t, comparator + 32);
					break;
				case 5:
					for (; t < WinCounter; ++t)
						SetGameBoard(i + t, j, comparator + 32);
					break;
				case 6:
					for (; t < WinCounter; ++t)
						SetGameBoard(i - t, j, comparator + 32);
					break;
				case 7:
					for (; t < WinCounter; ++t)
						SetGameBoard(i, j + t, comparator + 32);
					break;
				case 8:
					for (; t < WinCounter; ++t)
						SetGameBoard(i, j - t, comparator + 32);
					break;
				default:
					break;
				}
				PrintGameBoard();
			}
			return "1";
		}
		switch (direction) {
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
*	Desciription : This function checking is game ended for one side
*	Input		   : no input
*	Return Value : return interger if 1 user one won if  2 user2 won  if -1 game is not ender
*/
bool ConnectFour::IsGameOverOneSide(const char& User, const char& other) {
	int row = getGameSizeRow();
	int column = getGameSizeColumn();
	string controller = "";
	for (int i = row - 1; i >= 0; --i) {
		for (int j = column - 1; j >= 0; --j) {
			controller = "";
			for (int direction = 1; direction <= 8; direction++)//8 is number of direction
				controller += PartnerCheck(direction, i, j, User, other, 4, true);
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
int ConnectFour::MyStringCompare(const string& s1) {
	int counter = 0;
	string temp = "1";
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == temp[0])
			++counter;
	}
	return counter;
}
int ConnectFour::CheckCounter(const int& CurComp, const int& OtherComp, int count, const int& i, const int& j) {
	if (GetGameBoard(i, j).GetCellValue() == CurComp)
		++count;
	if (GetGameBoard(i, j).GetCellValue() == OtherComp)
		count = 0;
	return count;
}
/*
*	Desciription : This function checking move legal ol illegal
*	Input		   : position
*	Return Value : if return true position is legal if false its illegal
*/
bool ConnectFour::IsPositionPlayable(const int& player_id, const char& pos) {
	for (int i = getGameSizeRow() - 1; i >= 0; --i) {
		if (GetGameBoard(i, pos - 'A').GetCellValue() == EMTHY)
			return true;
	}
	return false;
}
/*
*	Desciription	: This function checking input function
*	Input			: char move = entered move
*	Return Value	: if move is legal  return true  or return false
*/
bool ConnectFour::MoveInputCheck(const string& command) {
	if (command[0] >= 'A' + getGameSizeColumn() || command[0] < 'A')
		return false;
	if (!isalpha(command[0]))
		return false;
	return true;
}
/*	Desciription : Printing screen current status of game board
*	Input		 : no input parameter
*	Return Value : no return value
*/
void ConnectFour::PrintGameBoard() {
	char a = 'A', b = 'A';
	int row = getGameSizeRow();
	int column = getGameSizeColumn();
	//cout << "GameBoard row -> " << row << endl;
	//cout << "GameBoard column -> " << column << endl;
	while (a < b + column) {
		cout << "  " << a << " ";
		a++;
	}
	cout << endl;
	for (auto i = 0; i < row; i++) {
		for (auto j = 0; j < column; j++)
			cout << "  " << GetGameBoard(i, j).GetCellValue() << " ";
		cout << "\n";
	}
}
/*
*	Desciription : This function initial board
*	Input		   : no input parameter
*	Return Value : no return value
*/
void ConnectFour::InitialBoard(const int& row, const int& column) {
	ReSizeGameBoard(row, column);
}
/*
*	Desciription : This function loading saved gameboard from file
*	Input		   : conts string file name
*	Return Value   : no return value
*/
void ConnectFour::ParseFirstLine(const string& line, int& mode, int& row, int& column, int& play) {
	string s = "";
	mode = line[0] - '0';
	int i = 2;
	cout << "line->" << line.size();
	for (int t = 0; t < 2; ++t) {
		s = "";
		while (1) {
			s += line[i];
			++i;
			if (line[i] == ' ')
				break;
		}
		if (t == 0)
			row = stoi(s);
		else if (t == 1)
			column = stoi(s);
		++i;
	}
	play = line[line.size() - 1] - '0';

}
void ConnectFour::LoadFile(const string& filename) {
	ifstream myReadFile;
	myReadFile.open(filename);
	string line = "";
	Cell copy;
	int size = 0;
	if (myReadFile.is_open()) {
		int column = 0, row = 0, WillPlay = 0, mode = 0;
		getline(myReadFile, line);
		if (!myReadFile.eof()) {
			if (line.size() >= 6) {
				ParseFirstLine(line, mode, row, column, WillPlay);
				SetGameMode(mode);//ilk eleman oyun modu
				SetWhoIsWillPlay(WillPlay);//3.değişken oyunu şimdi kimin oynaması gerektiği	
				ReSizeGameBoard(row, column);
			}
			row = 0;
			while (!myReadFile.eof()) {
				getline(myReadFile, line);
				for (int column = 0; column < getGameSizeColumn(); ++column) {
					copy.SetPosColumn(column);
					copy.SetPosRow(row);
					copy.SetCellValue(line[column]);
					SetGameBoard(copy);
				}
				++row;
			}
			cout << "Game Board Loaded Correctly\nNew Game Board is " << endl;
			PrintGameBoard();
		}
		else
			cerr << "<--->ILLEGAL<---> File is EMTHY  Please enter new file or keep going game " << endl;
	}
	myReadFile.close();
}
/*
*	Desciription : This function saving gameboard status
*	Input		   : conts string file name
*	Return Value   : no return value
*/
void ConnectFour::SaveFile(const string& filename) {
	ofstream myfile;
	myfile.open(filename, std::ofstream::out | std::ofstream::app);
	if (myfile.is_open()) {
		//Oyun modu 1 se  user vs user 2 ise user vs computer 
		//ikinci eleman oyunun size ı 
		myfile << GetGameMode() << " " << getGameSizeRow() << " " << getGameSizeColumn() << " " << WhoIsWillPlay << endl;
		for (int row = 0; row < getGameSizeRow(); ++row) {
			for (int column = 0; column < getGameSizeColumn(); ++column)
				myfile << GetGameBoard(row, column).GetCellValue();
			if (row < getGameSizeRow() - 1)
				myfile << "\n";
		}
		myfile.close();
	}
	else cerr << " <--->ILLEGAL<---> Unable to open file";
	//cout << "Game Board Saved Correctly" << endl;
}
/*
*	Desciription : This function checking game board size and game mode
*					Cheking interger or not and for size 6x6, 8x8, 10x10, 20x20
*					Cheking game mode  should be 1 or 2
*	Input		 : no input parameter
*	Return Value : no return value */
void ConnectFour::playGame() {
	int row = 0, column = 0;
	while (1) {
		cout << "Enter Game Row Size  \n" << "Game board can be any size \n";
		cin >> row;
		cout << "Enter Game Column Size  \n" << "Game board can be any size \n";
		cin >> column;
		if (cin.fail()) {
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cerr << " <--->ILLEGAL<---> Wrong input enter integer \n";
		}
		else {
			setGameSizeColumn(column);
			setGameSizeRow(row);
			break;
		}
	}
	int mode = 0;
	while (1) {
		cout << "Enter Game mode \n" << "Game mode  1 : two player game \n 2: User versus computer game \n";
		cin >> mode;
		if (cin.fail()) {
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cerr << " <--->ILLEGAL<---> Wrong input enter integer \n";
		}
		else {
			if (mode == 1 || mode == 2) {
				SetGameMode(mode);
				break;
			}
			else
				cerr << "<--->ILLEGAL<---> Wrong Game Mode \n";
		}
	}
	return;
}
/*
*	Desciription : This function taking one move without computer and make a move
*	Input		   : int curren player id
*					  const char& current move to make a move
*	Return Value   : No return value
*/
void ConnectFour::MovePlayer(const int& player_id, const char& CurrentMove) {
	const int rowSize = getGameSizeRow();
	char CurrentComparor = '\0', OtherComparor = '\0';
	if (player_id == USER1PLAYERID) {
		CurrentComparor = USER1;
		OtherComparor = USER2;
	}
	else if (player_id == USER2PLAYERID) {
		CurrentComparor = USER2;
		OtherComparor = USER1;
	}
	if (player_id != COMPUTERPLAYERID) {
		if (CurrentMove >= 'A' &&  CurrentMove <= ('A' + getGameSizeColumn() - 1)) {
			int column = static_cast<int> (CurrentMove - 'A');
			for (auto i = rowSize - 1; i >= 0; --i) {
				if (GetGameBoard(i, column).GetCellValue() == EMTHY) {
					Cell temp(column, i, CurrentComparor);
					SetGameBoard(temp);
					break;
				}
			}
		}
	}
}