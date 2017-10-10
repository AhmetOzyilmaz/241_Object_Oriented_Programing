#include <iostream>
#include<iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


class ConnectFour
{

public:
	ConnectFour():ConnectFour(4) {	/*Can Be Emthy	*/ }
	ConnectFour(int size):GameCurrentSize(size) {	/*Can Be Emthy	*/ }
	//TODO at least 3 constructors

	inline void SetGameCurrentSize(const int size) { GameCurrentSize = size; }
	inline const int GetGameCurrentSize() { return GameCurrentSize; }

	inline void SetGameMode(const int mode) { GameMode = mode; }
	inline const int GetGameMode() { return GameMode; }

	//File Operation
	void SaveFile(const string& filename);
	void LoadFile(const string& filename);
	//End File Operation
	void PrintGameBoard();	

private:
	class Cell
	{
	public:
		Cell() :PosColumn('A'), PosRow(0) {	/*Can Be Emthy	*/}	
		Cell(char PosC, int PosR) :PosColumn(PosC), PosRow(PosR) {/*Can Be Emthy*/	}

		inline void SetPosRow(const int row) { PosRow = row; }
		inline void SetPosColumn(const char col) { PosColumn = col; }
		inline const int GetPosRow() { return PosRow ; }
		inline const char GetPosColumn() { return PosColumn; }
		inline void SetCellValue(const char col) { CellValue = col; }
		inline const char GetCellValue() { return CellValue; }

	private:
		char PosColumn = 'A';
		int  PosRow    =  0;
		char CellValue = '.';
	};

	static int CellCounter;
	vector< vector<Cell> > gameCells;
	int GameCurrentSize = 4; //default size
	int GameMode = 1; //default game mode
	
};

