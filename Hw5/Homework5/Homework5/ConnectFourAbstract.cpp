#include "ConnectFourAbstract.h"
/*
*	Desciription : This function take row and column
*					Cheking game mode  should be 1 or 2
*	Input		 : no input parameter
*	Return Value : no return value */
void  Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::playGame() {
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
			setColumn(column);
			setRow(row);
			break;
		}
	}

}
Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::ConnectFourAbstract() {
	InitialBoard();
	PrintBoard();
	while (1) {
		cout << "Please Enter Game mode Player | Computer  - > P | C" << endl;
		char mode = ' ';
		cin >> mode;
		if (mode == 'P' || mode == 'p' || mode == 'C' || mode == 'c') {
			setMode(mode);
			break;
		}
		else
		{
			cout << "<-----> Error mode Enter Correct Mode <-----> " << endl;
		}
	}
}
Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::~ConnectFourAbstract()
{
	for (int i = 0; i < getRow(); ++i) {
		delete[] gameCells[i];
		gameCells[i] = nullptr;
	}
	delete[] gameCells;
	gameCells = nullptr;
}
/*
*	Desciription Why wrote ? : To play 1 round of the game
*	Input		   : no input
*	Return Value   : if return true game is over if return false game is not ended
*/
void Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::Play() {
	int control = 0;
	while (1) {
		if (1 == GetWhoIsWillPlay()) {
			control = MakeMove(USER1PLAYERID);
			SetWhoIsWillPlay(2);
			PrintBoard();
			if (true ==IsEnd()) {
				setGameisEnded(true);
				break;
			}
		}
		if (2 == GetWhoIsWillPlay()) {
			if ('P' == GetGameMode())
				control = MakeMove(USER2PLAYERID);
			else if ('C' == GetGameMode())
				control = MakeMove(COMPUTERPLAYERID);
			if (control == true) {
				SetWhoIsWillPlay(1);
				PrintBoard();
			}
			else if (true == IsEnd()) {
				setGameisEnded(true);
				break;
			}
		}
	}
}
/*
*	Desciription : This function loading saved gameboard from file
*	Input		   : conts string file name
*	Return Value   : no return value
*/
void Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::ParseFirstLine(const string& line, int& mode, int& row, int& column, int& play) {
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
void Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::ReSizeGameBoard(const int& row, const int& column) {

	gameCells = new Cell*[row];
	for (int i = 0; i < row; i++)
		gameCells[i] = new Cell[column];
	setRow(row);//2.deðiþken oyunun size ý
	setColumn(column);//2.deðiþken oyunun size ý

	cout << endl << " New Game Size " << getRow() << " X " << getColumn() << endl;
}
/*
*	Desciription : This function initial board
*	Input		   : taking row and column value and resize game table
*	Return Value : no return value
*/
void Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::InitialBoard(const int& row, const int& column) {
	ReSizeGameBoard(row, column);
}
/*
*	Desciription : This function initial board before ask user
*	Input		   : no input parameter
*	Return Value : no return value
*/
void Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::InitialBoard() {
	playGame();
	ReSizeGameBoard(getRow(), getColumn());
}

void Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::LoadFileNew(const string& filename, const int useles) {
	cout << "Starting Loading file " << endl;
	ifstream myReadFile;
	myReadFile.open(filename);
	string line = "";
	Cell copy;
	int size = 0;
	if (myReadFile.is_open()) {
		int column = 0, row = 0, WillPlay = 0, mode = 0;
		getline(myReadFile, line);

		if (false == myReadFile.eof()) {
			while (false == myReadFile.eof()) {

				++row;
				if (line.size() > column)
					column = line.size();

				getline(myReadFile, line);

			}
			//cout << row << " " << column;
			ReSizeGameBoard(row, column);
			int wait;
			myReadFile.close();
			myReadFile.open(filename);
			getline(myReadFile, line);
			int i = 0;
			while (!myReadFile.eof()) {
				for (int j = 0; j < column; ++j) {
					copy.SetPosColumn(j);
					copy.SetPosRow(i);
					copy.SetCellValue(line[j]);
					SetGameBoard(copy);
				}
				++i;
				getline(myReadFile, line);
			}

			myReadFile.close();

			PrintBoard();
			//cout << "Loading success " << endl;
			//cout << "Game Board Loaded Correctly\nNew Game Board is " << endl;
		}
		else
			cerr << "<--->ILLEGAL<---> File is EMTHY  Please enter new file or keep going game " << endl;
	}

}
void Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::LoadFile(const string& filename) {
	ifstream myReadFile;
	myReadFile.open(filename);
	string line = "";
	Cell copy;
	int go;
	int size = 0;
	if (myReadFile.is_open()) {
		int column = 0, row = 0, WillPlay = 0, mode = 0;
		getline(myReadFile, line);
		if (!myReadFile.eof()) {
			if (line.size() >= 6) {

				ParseFirstLine(line, mode, row, column, WillPlay);
				setMode(mode);//ilk eleman oyun modu
				SetWhoIsWillPlay(WillPlay);//3.değişken oyunu şimdi kimin oynaması gerektiği	
				ReSizeGameBoard(row, column);
			}

			row = 0;
			while (!myReadFile.eof()) {
				getline(myReadFile, line);
				for (int column = 0; column < getColumn(); ++column) {
					copy.SetPosColumn(column);
					copy.SetPosRow(row);
					copy.SetCellValue(line[column]);
					SetGameBoard(copy);
				}
				++row;
			}
			cout << "Game Board Loaded Correctly\nNew Game Board is " << endl;
			PrintBoard();
		}
		else
			cerr << "<--->ILLEGAL<---> File is EMTHY  Please enter new file or keep going game " << endl;
	}
	myReadFile.close();
}
/*
*Desciription : This function saving gameboard status
*	Input : conts string file name
*	Return Value : no return value
*/
void Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::SaveFile(const string& filename) {
	ofstream myfile;
	myfile.open(filename, std::ofstream::out | std::ofstream::app);
	if (myfile.is_open()) {
		//Oyun modu 1 se  user vs user 2 ise user vs computer 
		//ikinci eleman oyunun size ı 
		myfile << GetGameMode() << " " << getRow() << " " << getColumn() << " " << WhoIsWillPlay << endl;
		for (int row = 0; row < getRow(); ++row) {
			for (int column = 0; column < getColumn(); ++column)
				myfile << getCell(row, column).GetCellValue();
			if (row < getRow() - 1)
				myfile << "\n";
		}
		myfile.close();
	}
	else cerr << " <--->ILLEGAL<---> Unable to open file";
	//cout << "Game Board Saved Correctly" << endl;
}
void Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::PrintBoard()
{
	char a = 'A', b = 'A';
	int row = getRow();
	int column = getColumn();

	cout << "GameBoard row -> " << row << endl;
	cout << "GameBoard column -> " << column << endl;
	
	while (a < b + column) {
		cout << "  " << a << " ";
		a++;
	}
	cout << endl;

	for (auto i = 0; i < row; i++) {
		for (auto j = 0; j < column; j++)
			cout << "  " << getCell(i, j).GetCellValue() << " ";
		cout << "\n";
	}

}

/*
*	Desciription : This function managing all player move operation
*	Input		   : Interger for which player playing
*	Return Value   : if return integer if return 2 is load or save operation if return -1 wrong input if zero moving true
*/
bool Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::MakeMove(const int& PlayerID) {
	bool flag = false;
	if (PlayerID != 3) {
		char move = TakeMove(PlayerID);
		while (move == '0') {
			move = TakeMove(PlayerID);
		}
		if (true == PlayMove(move, PlayerID))
			return true;
	}
	else if (PlayerID == 3) {
		return PlayMove();
	}
	return false;
}
bool Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::IsEnd()
{
	if (false == AnyMoveMore()) {
		cout << "Game is Ended " << endl;
		cout << "Game is draw play new game" << endl;
		return true;
	}
	if (IsEndOneSide(USER1, USER2)) {
		cout << "<---------------->Player 1 WON<---------------->" << endl;
		return true;
	}
	if (IsEndOneSide(USER2, USER1)) {
		cout << "<---------------->Player 2 WON<----------------> " << endl;
		return true;
	}
	cout << "Game is not ended " << endl;
	return false;
}
char Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::TakeMove(const int& PlayerID) {
	bool flag = false;
	string command = "", command2 = "";
		cout << "\n\nGAME " << getGameID() << endl;
		PrintBoard();
		cout << "if want to Save Gameboard enter 'SAVE FILE.txt' \n "
			<< "if you want to  load gameboard  from file enter 'LOAD FILE.txt' \n "
			<< "Enter one grater letter  move A , B, C ...\n"
			<< "\t For : Player " << PlayerID << endl;
		cin >> command;

		if (cin.eof()) {
			exit(-31);//input from file ended
		}
		cout <<"***** Command --> "<< command << endl;
		if (command.size() > 3) { // "LOAD X.txt" minumum kabul edilen kýsým 
			cin >> command2;
			command2 = command + " " + command2;
			CommandSelector(command2);
			return '0';
		}
		else {
			cout << command.size() << endl;
			if (command.size() == 1) {
				//cout << command << endl;
				if (true == MoveInputCheck(command[0])) {
					//cout << MoveInputCheck(command[0]) << endl;
					return command[0];
				}

			}
			else
				cerr << "<--->ILLEGAL<---> ERROR COMMAND ENTER NEW  COMMAND " << endl;
		}
	return '0';
}
/*
*	Desciription :
*	Input		   : no parameter
*	Return Value   : return bool if make move return true if no return false
*/
bool  Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::PlayMove() {
	NeigborEnemy MaxEnem;
	MaxEnem.posX = 0;
	MaxEnem.posY = 0;
	MaxEnem.NeighborEnemyCounter = "00000000";
	int  control = 0, MaxControl = 0, index = 0;
	const int rowSize = getColumn();
	const int columnSize = getColumn();
	bool flag = true, isPlayeable = true;
	char pos;
	string controller = "00000000";
	for (int column = columnSize - 1; column >= 0; --column) {
		if (getCell(rowSize - 1, column).GetCellValue() == USER2) {
			flag = false;
			break;
		}
	}
	if (flag) {//First Move in game
		pos = MoveComputer();
		int column = static_cast<int> (pos - 'A');
		for (int row = rowSize - 1; row >= 0; --row) {
			if (getCell(row, column).GetCellValue() == EMTHY || getCell(row, column).GetCellValue() == SPECIALEMTHY) {
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
					control = OneCounter(controller);
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
		cout << endl << MaxControl << " MaxEnem.posX "
			<< MaxEnem.posX << " MaxEnem.posY " << MaxEnem.posY
			<< " MaxEnem.NeighborEnemyCounter\t"
			<< MaxEnem.NeighborEnemyCounter << endl;

		if (MaxEnem.posX - 1 >= 0 && gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == EMTHY || gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == SPECIALEMTHY)
			if (getCell(MaxEnem.posX - 1, MaxEnem.posY).GetCellValue() == USER1 &&  isPlayeable)
				isPlayeable = PlayIsPlayeable(1, isPlayeable, MaxEnem, MaxEnem.posX - 1, MaxEnem.posY);

		if (MaxEnem.posX - 1 >= 0 && MaxEnem.posY - 1 >= 0 && gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == EMTHY || gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == SPECIALEMTHY)
			if (getCell(MaxEnem.posX - 1, MaxEnem.posY - 1).GetCellValue() == USER1 &&  isPlayeable)
				isPlayeable = PlayIsPlayeable(2, isPlayeable, MaxEnem, MaxEnem.posX - 1, MaxEnem.posY - 1);
		if (MaxEnem.posY - 1 >= 0 && gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == EMTHY || gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == SPECIALEMTHY)
			if (getCell(MaxEnem.posX, MaxEnem.posY - 1).GetCellValue() == USER1 &&  isPlayeable)
				isPlayeable = PlayIsPlayeable(3, isPlayeable, MaxEnem, MaxEnem.posX, MaxEnem.posY - 1);
		if (MaxEnem.posY + 1 < columnSize && gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == EMTHY || gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == SPECIALEMTHY)
			if (getCell(MaxEnem.posX, MaxEnem.posY + 1).GetCellValue() == USER1 &&  isPlayeable)
				isPlayeable = PlayIsPlayeable(4, isPlayeable, MaxEnem, MaxEnem.posX, MaxEnem.posY + 1);
		if (true == isPlayeable) {
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
					if (gameCells[row][column].GetCellValue() == EMTHY && gameCells[row][column].GetCellValue() != ' ' || gameCells[row][column].GetCellValue() == SPECIALEMTHY) {
						gameCells[row][column].SetCellValue(USER2);
						cout << "Movement For Computer " << "Position is row ->  " << row << "\tColumn is " << column << endl;
						isPlayeable = false;
						return true;
						break;
					}
				}
				if (isPlayeable == false)
					return true;
			}

		}
	}

	return false;
}
bool Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::PlayMove(char move, const int& PlayerID) {
	bool flag = false;
	flag = MoveInputCheck(move);
	if (flag) {
		//if flag true this can true input i will checking position is playable
		if (IsPositionPlayable(PlayerID, move)) {// play move
			MovePlayer(PlayerID, move);
			return true;
		}
		else {
			cerr << " <--->ILLEGAL<---> Position Cannot play enter another move " << endl;
			return false;
		}
	}
	else
		cerr << "<--->ILLEGAL<---> MoveInputCheck function return false\n\n\n PLEASE ENTER CORRECT MOVE";
	return false;
}
void Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::SetStartPlayer()
{
	cout << "Player | Computer: ";
	char choise = ' ';
	cin >> choise;

	setMode(choise);
	if (cin.fail()) {
		cin.clear(); //This corrects the stream.
		cin.ignore(); //This skips the left over stream data.
		cerr << " <--->ILLEGAL<---> Wrong choise for who start to play enter 'P' or 'C' \n";
	}
}
/*
*	Desciription : //This game has 2 type command Load and Save
*	Input		   : const string& taking command from user
*	Return Value   : If a valid file operation its returns true, is not return false
*/
bool Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::CommandSelector(const string& command) {
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

void Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::NewGame() {
	InitialBoard(BoardRow, BoardColumn);
	PrintBoard();
	SetWhoIsWillPlay(USER1PLAYERID);
}
/*
*	Desciription : This function computer automatic playin move
*	Input		   : no parameter
*	Return Value   : returnin if u find placable positon or returning '.' for error
*/
char Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::MoveComputer() {
	char pos;
	while (1) {
		srand(time(NULL));
		pos = 'A' + rand() % getColumn();
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
bool Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::PlayIsPlayeable(const int& direction, bool isPlayeable, const NeigborEnemy& MaxEnem, int row, int column) {
	const int rowSize = getColumn(), columnSize = getColumn();

	for (; ; ) {
		cout << "Sonsuz" << endl;
		if (row < 0 || row >= rowSize)
			break;
		if (column < 0 || column >= columnSize)
			break;
		if (direction != 4) {//özel durum
			if (getCell(row, column).GetCellValue() == EMTHY || getCell(row, column).GetCellValue() == SPECIALEMTHY) {
				SetGameBoard(row, column, USER2);
				cout << "***** Movement For Computer " << "Position is row ->  " << row << "Column is " << column << endl;
				return false;
			}
		}
		else if (direction == 4) {
			if (MaxEnem.posX + 1 < rowSize && MaxEnem.posX + 1 >= 0) {
				if (getCell(MaxEnem.posX, column).GetCellValue() == EMTHY && getCell(MaxEnem.posX + 1, column).GetCellValue() != EMTHY) {
					if (getCell(MaxEnem.posX, column).GetCellValue() == SPECIALEMTHY && getCell(MaxEnem.posX + 1, column).GetCellValue() != SPECIALEMTHY)
					{
						//SetGameBoard(MaxEnem.posX, column, USER2);
						cout << "Movement For Computer " << "Position is row ->  " << MaxEnem.posX << "Column is " << column << endl;
						return false;
					}

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

bool Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::AnyMoveMore() {
	int row = getColumn();
	int column = getColumn();
	for (int i = row - 1; i >= 0; --i) {
		for (int j = column - 1; j >= 0; --j) {
			if (getCell(i, j).GetCellValue() == EMTHY || getCell(i, j).GetCellValue() == SPECIALEMTHY)
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
string Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::PartnerCheck(const int direction, const int& posX, const int& posY, const char& comparator, const char& othercomparator, const int& WinCounter, const bool& flag) {
	int row = getColumn();
	int column = getColumn();
	auto counter = 0, i = 0, j = 0, l = 0;
	decltype(i) k = 0;
	for (i = posX, j = posY; ;) {
		if (i < 0 || i >= row)
			break;
		if (j < 0 || j >= column)
			break;
		counter = CheckCounter(comparator, counter, i, j);
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
				PrintBoard();
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
*	Desciription : This function returnin number of '1' in your string
*	Input		   : const string& s1
*	Return Value   : intger counter of "1"
*/
int Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::OneCounter(const string& s1) {
	int counter = 0;
	string temp = "1";
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == temp[0])
			++counter;
	}
	return counter;
}
int Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::CheckCounter(const int& CurComp, int count, int row, int column) {
	if (getCell(row, column).GetCellValue() == CurComp)
		++count;
	else
		count = 0;
	return count;
}
/*
*	Desciription : This function checking move legal ol illegal
*	Input		   : position
*	Return Value : if return true position is legal if false its illegal
*/
bool Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::IsPositionPlayable(const int& player_id, const char& pos) {
	for (int i = getColumn() - 1; i >= 0; --i) {
		if (getCell(i, pos - 'A').GetCellValue() == EMTHY || getCell(i, pos - 'A').GetCellValue() == SPECIALEMTHY)
			return true;
	}
	return false;
}
/*
*	Desciription	: This function checking input function
*	Input			: char move = entered move
*	Return Value	: if move is legal  return true  or return false
*/
bool Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::MoveInputCheck(char command) {
	if (command >= 'A' + getColumn() || command < 'A')
		return false;
	if (!isalpha(command))
		return false;
	return true;
}

/*
*	Desciription : This function taking one move without computer and make a move
*	Input		   : int curren player id
*					  const char& current move to make a move
*	Return Value   : No return value
*/
void Ozyilmaz_Ahmet_111044014::ConnectFourAbstract::MovePlayer(const int& player_id, const char& CurrentMove) {
	const int rowSize = getColumn();
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
		if (CurrentMove >= 'A' &&  CurrentMove <= ('A' + getColumn() - 1)) {
			int column = static_cast<int> (CurrentMove - 'A');
			for (auto i = rowSize - 1; i >= 0; --i) {
				if (getCell(i, column).GetCellValue() == EMTHY || getCell(i, column).GetCellValue() == SPECIALEMTHY) {
					Cell temp(column, i, CurrentComparor);
					SetGameBoard(temp);
					break;
				}
			}
		}
	}
}
