#include "ConnectFour.h"


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
				myfile << GameBoard[row][column];
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
				for (int column = 0; column < line.size(); ++column)
					GameBoard[row][column] = line[column];
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
			cout << "  " << GameBoard[i][j] << " ";
		cout << "\n";
	}
}
