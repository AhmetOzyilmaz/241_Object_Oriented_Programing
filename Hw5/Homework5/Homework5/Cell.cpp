#include "Cell.h"

//Operator == for cell
bool operator ==(const Cell& first, const Cell& second) {
	if (first.GetCellValue() == second.GetCellValue()) {
		cout << "First Cell equal Second cell" << endl;
		return true;
	}
	cout << "First Cell not equal Second cell" << endl;
	return false;
}
//Operator != for cell
bool operator !=(const Cell& first, const Cell& second) {
	return !(first == second);
}
Cell Cell::operator++()//önce
{
	if (GetCellValue() == EMTHY) {
		SetCellValue(USER1);
	}
	else if (GetCellValue() == USER1) {
		SetCellValue(USER2);
	}
	else if (GetCellValue() == USER2) {
		SetCellValue(EMTHY);
	}
	return *this;
}
Cell Cell::operator++(int)//sonra
{
	Cell temp = *this;

	if (GetCellValue() == EMTHY) {
		SetCellValue(USER1);
	}
	else if (GetCellValue() == USER1) {
		SetCellValue(USER2);
	}
	else if (GetCellValue() == USER2) {
		SetCellValue(EMTHY);
	}
	return temp;
}
ostream & operator<<(ostream & output, const Cell& outCell)
{
	output << "This Cell Row" << outCell.GetPosRow() << endl;
	output << "This Cell Column" << outCell.GetPosColumn() << endl;
	output << "This Cell Value" << outCell.GetCellValue() << endl;
	return output;
}
istream & operator>>(istream & input, Cell & outCell)
{
	int value;
	char val;
	cout << "Enter integer Row Value For Cell " << endl;
	input >> value;
	outCell.SetPosRow(value);
	cout << "Enter integer Column Value For Cell " << endl;
	input >> value;
	outCell.SetPosColumn(value);
	cout << "Enter Value For Cell " << endl;
	input >> val;
	outCell.SetPosColumn(val);
	cout << "Filled Cell " << endl;

	return input;
}
