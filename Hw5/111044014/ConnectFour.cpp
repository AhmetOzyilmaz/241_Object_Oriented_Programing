#include "ConnectFour.h"

/*
*	Desciription : This function take row and column
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
			setBoardColumn(row);
			break;
		}
	}
	return;
}

/*
*	Desciription Why wrote ? : To play 1 round of the game
*	Input		   : no input
*	Return Value   : if return true game is over if return false game is not ended
*/
bool ConnectFour::Play() {
	int control = 0;		
	if (1 == GetWhoIsWillPlay()) {
		control = MakeMove(USER1PLAYERID);
		SetWhoIsWillPlay(2);
		PrintBoard();
		if (IsEnd()) {
			setGameisEnded(true);
			return true;
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
		else if (IsEnd()) {
			setGameisEnded(true);
			return true;
		}
	}
	return false;
}

/*
*	Desciription : This function managing all player move operation
*	Input		   : Interger for which player playing
*	Return Value   : if return integer if return 2 is load or save operation if return -1 wrong input if zero moving true
*/
bool ConnectFour::MakeMove(const int& PlayerID) {
	bool flag = false;
	if (PlayerID != 3) {
		char move = TakeMove(PlayerID);
		if (true == PlayMove(move, PlayerID))
			return true;			
	}
	else if (PlayerID == 3) {
		return PlayMove();
	}
	return false;
}
char ConnectFour::TakeMove(const int& PlayerID) {
	bool flag = false;
	string command = "", command2 = "";
	while (1) {
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
		if (command.size() > 3) { // "LOAD X.txt" minumum kabul edilen kýsým 
			cin >> command2;
			command2 = command + " " + command2;
			CommandSelector(command2);
			return '-1';
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
	}
	return '-1';
}
/*
*	Desciription :
*	Input		   : no parameter
*	Return Value   : return bool if make move return true if no return false
*/
bool  ConnectFour::PlayMove() {
	NeigborEnemy MaxEnem;
	MaxEnem.posX = 0;
	MaxEnem.posY = 0;
	MaxEnem.NeighborEnemyCounter = "00000000";
	int  control = 0, MaxControl = 0, index = 0;
	const int rowSize = getBoardColumn();
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
			if (GetGameBoard(row, column).GetCellValue() == EMTHY || GetGameBoard(row, column).GetCellValue() == SPECIALEMTHY) {
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
			if (GetGameBoard(MaxEnem.posX - 1, MaxEnem.posY).GetCellValue() == USER1 &&  isPlayeable)
				isPlayeable = PlayIsPlayeable(1, isPlayeable, MaxEnem, MaxEnem.posX - 1, MaxEnem.posY);

		if (MaxEnem.posX - 1 >= 0 && MaxEnem.posY - 1 >= 0 && gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == EMTHY || gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == SPECIALEMTHY)
			if (GetGameBoard(MaxEnem.posX - 1, MaxEnem.posY - 1).GetCellValue() == USER1 &&  isPlayeable)
				isPlayeable = PlayIsPlayeable(2, isPlayeable, MaxEnem, MaxEnem.posX - 1, MaxEnem.posY - 1);
		if (MaxEnem.posY - 1 >= 0 && gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == EMTHY || gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == SPECIALEMTHY)
			if (GetGameBoard(MaxEnem.posX, MaxEnem.posY - 1).GetCellValue() == USER1 &&  isPlayeable)
				isPlayeable = PlayIsPlayeable(3, isPlayeable, MaxEnem, MaxEnem.posX, MaxEnem.posY - 1);
		if (MaxEnem.posY + 1 < columnSize && gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == EMTHY || gameCells[MaxEnem.posX][MaxEnem.posY].GetCellValue() == SPECIALEMTHY)
			if (GetGameBoard(MaxEnem.posX, MaxEnem.posY + 1).GetCellValue() == USER1 &&  isPlayeable)
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
bool ConnectFour::PlayMove(char move, const int& PlayerID) {
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
void ConnectFour::SetStartPlayer()
{
	cout << "Player | Computer: ";
	char choise=' ';
	cin >> choise;

	SetGameMode(choise);
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
void ConnectFour::CopyConnectedFour(const ConnectFour& other) {
	BoardColumn = other.BoardColumn;
	gameSizeColumn = other.gameSizeColumn;
	WhoIsWillPlay = other.WhoIsWillPlay;
	GameMode = other.GameMode;
	CurrentElementCounter = other.CurrentElementCounter;
	isEnded = other.isEnded;
	GameID = other.GameID;

	ReSizeGameBoard(BoardColumn, gameSizeColumn);

	for (int i = 0; i < BoardColumn; ++i) {
		for (int j = 0; j < gameSizeColumn; ++j) {
			gameCells[i][j] = other.gameCells[i][j];
		}
	}
}
void ConnectFour::NewGame() {
	InitialBoard(BoardColumn, gameSizeColumn);
	PrintBoard();
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
	const int rowSize = getBoardColumn(), columnSize = getGameSizeColumn();

	for (; ; ) {
		cout << "Sonsuz" << endl;
		if (row < 0 || row >= rowSize)
			break;
		if (column < 0 || column >= columnSize)
			break;
		if (direction != 4) {//özel durum
			if (GetGameBoard(row, column).GetCellValue() == EMTHY || GetGameBoard(row, column).GetCellValue() == SPECIALEMTHY) {
				SetGameBoard(row, column, USER2);
				cout << "***** Movement For Computer " << "Position is row ->  " << row << "Column is " << column << endl;
				return false;
			}
		}
		else if (direction == 4) {
			if (MaxEnem.posX + 1 < rowSize && MaxEnem.posX + 1 >= 0) {
				if (GetGameBoard(MaxEnem.posX, column).GetCellValue() == EMTHY && GetGameBoard(MaxEnem.posX + 1, column).GetCellValue() != EMTHY) {
					if (GetGameBoard(MaxEnem.posX, column).GetCellValue() == SPECIALEMTHY && GetGameBoard(MaxEnem.posX + 1, column).GetCellValue() != SPECIALEMTHY)
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
/*
*	Desciription : This function checking is game ended or not
*	Input		   : no input
*	Return Value : If the game is over, it returns false if it is not done returns true
*/
bool ConnectFour::IsEnd() {
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
	return false;
}
bool ConnectFour::AnyMoveMore() {
	int row = getBoardColumn();
	int column = getGameSizeColumn();
	for (int i = row - 1; i >= 0; --i) {
		for (int j = column - 1; j >= 0; --j) {
			if (GetGameBoard(i, j).GetCellValue() == EMTHY || GetGameBoard(i, j).GetCellValue() == SPECIALEMTHY)
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
	int row = getBoardColumn();
	int column = getGameSizeColumn();
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
*	Desciription : This function checking is game ended for one side
*	Input		   : no input
*	Return Value : return interger if 1 user one won if  2 user2 won  if -1 game is not ender
*/
bool ConnectFour::IsEndOneSide(const char& User, const char& other) {
	int row = getBoardColumn();
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
int ConnectFour::OneCounter(const string& s1) {
	int counter = 0;
	string temp = "1";
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == temp[0])
			++counter;
	}
	return counter;
}
int ConnectFour::CheckCounter(const int& CurComp, int count, int row, int column) {
	if (GetGameBoard(row, column).GetCellValue() == CurComp)
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
bool ConnectFour::IsPositionPlayable(const int& player_id, const char& pos) {
	for (int i = getBoardColumn() - 1; i >= 0; --i) {
		if (GetGameBoard(i, pos - 'A').GetCellValue() == EMTHY || GetGameBoard(i, pos - 'A').GetCellValue() == SPECIALEMTHY)
			return true;
	}
	return false;
}
/*
*	Desciription	: This function checking input function
*	Input			: char move = entered move
*	Return Value	: if move is legal  return true  or return false
*/
bool ConnectFour::MoveInputCheck(char command) {
	if (command >= 'A' + getGameSizeColumn() || command < 'A')
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
void ConnectFour::MovePlayer(const int& player_id, const char& CurrentMove) {
	const int rowSize = getBoardColumn();
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
				if (GetGameBoard(i, column).GetCellValue() == EMTHY || GetGameBoard(i, column).GetCellValue() == SPECIALEMTHY) {
					Cell temp(column, i, CurrentComparor);
					SetGameBoard(temp);
					break;
				}
			}
		}
	}
}
