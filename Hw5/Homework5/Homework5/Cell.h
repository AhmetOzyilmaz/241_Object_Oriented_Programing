#include <iostream>
#include <cstdlib>     /* srand, rand */
#include <ctime>
#include <string>
#include <fstream>

using namespace std;

const char USER1 = 'X';
const char USER2 = 'O';
const char EMTHY = '.';

class Cell
{
public:
	Cell() :Cell(0, 0, '.') {	/*Can Be Emthy	*/ }
	Cell(int PosC, int PosR, char val) :PosColumn(PosC), PosRow(PosR), CellValue(val) { /*Can Be Emthy*/ }
	Cell(const Cell& cell) :PosColumn(cell.PosColumn), PosRow(cell.PosRow), CellValue(cell.CellValue) {/*Can Be Emthy*/ }

	inline void SetPosRow(const int& row) { PosRow = row; }
	inline void SetPosColumn(const int& col) { PosColumn = col; }
	inline int GetPosRow() const { return PosRow; }
	inline int GetPosColumn() const { return PosColumn; }
	inline void SetCellValue(const char& col) { CellValue = col; }
	inline char GetCellValue()const { return CellValue; }

	Cell operator++(); // prefix  önce arttır 
	Cell operator++(int);// post fix sonra arttır 
private:
	int PosColumn = 0;
	int  PosRow = 0;
	char CellValue = '.';
};
