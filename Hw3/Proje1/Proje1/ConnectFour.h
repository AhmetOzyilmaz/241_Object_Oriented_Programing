#pragma once

int ConnectFour:: CellCounter = 0;

class ConnectFour
{

public:
	ConnectFour();
	~ConnectFour();


private:
	static int CellCounter;
	class Cell
	{
	public:
		Cell() :PosColumn('A'), PosRow(0) {
			//Can Be Emthy
		}	
		Cell(char PosC, int PosR) :PosColumn(PosC), PosRow(PosR) {
			//Can Be Emthy

		}

		inline void SetPosRow(const int row) { PosRow = row; }
		inline void SetPosColumn(const char col) { PosColumn = col; }
		inline int GetPosRow() { return PosRow ; }
		inline char GetPosColumn() { return PosColumn; }
		inline void SetCellValue(const char col) { CellValue = col; }
		inline char GetCellValue() { return CellValue; }

	private:
		char PosColumn = 'A';
		int  PosRow    =  0;
		char CellValue = '.'
	};

	
};

