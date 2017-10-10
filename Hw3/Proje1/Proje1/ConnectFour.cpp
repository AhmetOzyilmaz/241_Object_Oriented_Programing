#include "ConnectFour.h"


/*
*	Desciription : This function saving gameboard status
*	Input		   : conts string file name
*	Return Value   : no return value
*/
void ConnectFour::Play() {
	char command = '.';
	while (1) {
		InputValidator();
		InitialBoard();
		PrintGameBoard();
		GameManager();
		cout << "if you want to quit enter q or enter different character" << endl;
		cin >> command;
		if (command == 'q' || command == 'Q')
			break;
	}
}



/*
*	Desciription : This function playing game respectively until one of the player win or moveable
*					position when end
*	Input		   : no input
*	Return Value   : no return value
*/
void ConnectFour::GameManager() {
	int control = 0, check = 0;
	while (1) {
		if ( GetWhoIsWillPlay() == 1) {
			//Player1
			control = AllMoveOperation(USER1PLAYERID);
			if (control != 2)
			SetWhoIsWillPlay(2);
		}
		else if (GetWhoIsWillPlay() == 2) {
			if (ONE_PLAYER_VERSUS_COMPUTER == GameMode)
				control = AllMoveOperation(COMPUTERPLAYERID);
			else if (TWO_PLAYER == GameMode)
				control = AllMoveOperation(USER2PLAYERID);
			SetWhoIsWillPlay(1);
		}
		check = IsGameOver();
		PrintGameBoard();
		if (check == -1)
			break;
	}
}

/*
*	Desciription : This function initial board
*	Input		   : no input parameter
*	Return Value : no return value
*/
void ConnectFour::InitialBoard() {
	int size = GetGameCurrentSize();
	Cell c;//no parameter contructor 
	vector <vector<Cell> > temp(10);
	for (auto i = 0; i < size; ++i) {
		for (auto j = 0; j < size; ++j) {
			c.SetPosRow(i);
			c.SetPosColumn(j);
			temp[i].push_back(c);
		}
	}
	SetGameBoard(temp);
}
/*
*	Desciription : This function checking game board size and game mode
*					Cheking interger or not and for size 6x6, 8x8, 10x10, 20x20
*					Cheking game mode  should be 1 or 2
*	Input		 : no input parameter
*	Return Value : no return value */
void ConnectFour::InputValidator() {
	int size = 0;
	while (1) {
		cout << "Enter Game size \n" << "Game board size should be ->  \n  <  4 x 4 , 6x6, 8x8, 10x10,  ... , 20x20 >.\n";
		cin >> size;
		if (cin.fail()) {
			cin.clear(); //This corrects the stream.
			cin.ignore(); //This skips the left over stream data.
			cerr << " <--->ILLEGAL<---> Wrong input enter integer \n";
		}
		else {
			if (!(size % 2)) {
				if (size >= 4 && size <= 20) {
					SetGameCurrentSize(size);
					break;
				}
			}
			else
				cerr << " <--->ILLEGAL<---> Wrong input for game size \n";
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
*	Desciription : This function saving gameboard status
*	Input		   : conts string file name
*	Return Value   : no return value
*/
void ConnectFour::SaveFile(const string& filename) {
	ofstream myfile;
	myfile.open(filename, std::ofstream::out | std::ofstream::app);
	if (myfile.is_open()) {
		//Oyun modu 1 se  user vs user 2 ise user vs computer 
		//ikinci eleman oyunun size ý 
		//TODO hamle kimde kaldýysa onun idsi CurrenPlayerID olarak atanýcak

		myfile << GetGameMode() << " " << GetGameCurrentSize() << " " << WhoIsWillPlay << endl;
		for (int row = 0; row < GetGameCurrentSize(); ++row) {
			for (int column = 0; column < GetGameCurrentSize(); ++column)
				myfile << GetGameBoard(row,column).GetCellValue();
			if (row < GetGameCurrentSize() - 1)
				myfile << "\n";
		}
		myfile.close();
	}
	else cerr << " <--->ILLEGAL<---> Unable to open file";
	//cout << "Game Board Saved Correctly" << endl;
}
/*
*	Desciription : This function loading saved gameboard from file
*	Input		   : conts string file name
*	Return Value   : no return value
*/
// TODO yanlýþ dosya yükleme,
void ConnectFour::LoadFile(const string& filename) {
	ifstream myReadFile;
	myReadFile.open(filename);
	string line = "";
	Cell copy;
	int size = 0;
	if (myReadFile.is_open()) {
		int column = 0, row = 0;
		getline(myReadFile, line);
		if (!myReadFile.eof()) {
			if (line.size() >= 5) {
				GameMode = line[0] - '0';//ilk eleman oyun modu
				SetGameCurrentSize(line[2] - '0');//2.deðiþken oyunun size ý
				WhoIsWillPlay = line[4] - '0';//3.deðiþken oyunu þimdi kimin oynamasý gerektiði		
			}
			while (!myReadFile.eof()) {
				getline(myReadFile, line);
				for (int column = 0; column < line.size(); ++column) {
					copy.SetPosColumn(column);
					copy.SetPosRow(row);
					copy.SetCellValue(line[column]);
					SetGameBoard(copy);
				}
				++row;
			}
			SetGameCurrentSize(row);
			cout << "Game Board Loaded Correctly\nNew Game Board is " << endl;
			PrintGameBoard();
		}
		else
			cerr << "<--->ILLEGAL<---> File is EMTHY  Please enter new file or keep going game " << endl;
	}
	myReadFile.close();
}

/*	Desciription : Printing screen current status of game board
*	Input		 : no input parameter
*	Return Value : no return value
*/

void ConnectFour::PrintGameBoard() {
	char a = 'A', b = 'A';
	while (a < b + GetGameCurrentSize()) {
		cout << "  " << a << " ";
		a++;
	}
	cout << endl;
	for (auto i = 0; i < GetGameCurrentSize(); i++) {
		for (auto j = 0; j < GetGameCurrentSize(); j++)
			cout << "  " <<  GetGameBoard(i,j).GetCellValue() << " ";
		cout << "\n";
	}
}
