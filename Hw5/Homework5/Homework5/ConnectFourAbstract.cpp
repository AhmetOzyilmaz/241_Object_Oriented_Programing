#include "ConnectFourAbstract.h"

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

		if (!myReadFile.eof()) {
			while (!myReadFile.eof()) {

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
				myfile << GetCell(row, column).GetCellValue();
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
	//cout << "GameBoard row -> " << row << endl;
	//cout << "GameBoard column -> " << column << endl;
	while (a < b + column) {
		cout << "  " << a << " ";
	}
	cout << endl;
	a++;

	for (auto i = 0; i < row; i++) {
		for (auto j = 0; j < column; j++)
			cout << "  " << GetCell(i, j).GetCellValue() << " ";
		cout << "\n";
	}
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
				myfile << GetCell(row, column).GetCellValue();
			if (row < getRow() - 1)
				myfile << "\n";
		}
		myfile.close();
	}
	else cerr << " <--->ILLEGAL<---> Unable to open file";
	//cout << "Game Board Saved Correctly" << endl;
}
