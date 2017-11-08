#include "ConnectFour.h"

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

void ConnectFour::LoadFileNew(const string& filename, const int useles) {
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

			PrintGameBoard();
			//cout << "Loading success " << endl;
			//cout << "Game Board Loaded Correctly\nNew Game Board is " << endl;
		}
		else
			cerr << "<--->ILLEGAL<---> File is EMTHY  Please enter new file or keep going game " << endl;
	}

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
				SetWhoIsWillPlay(WillPlay);//3.deðiþken oyunu þimdi kimin oynamasý gerektiði	
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
		//ikinci eleman oyunun size ý 
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