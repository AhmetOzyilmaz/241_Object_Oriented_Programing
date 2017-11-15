#include "Cell.h"

//Operator == for cell
bool operator ==(const Ozyilmaz_Ahmet_111044014::Cell& first, const Ozyilmaz_Ahmet_111044014::Cell& second) {
	if (first.GetCellValue() == second.GetCellValue()) {
		cout << "First Cell equal Second cell" << endl;
		return true;
	}
	cout << "First Cell not equal Second cell" << endl;
	return false;
}
//Operator != for cell
bool operator !=(const Ozyilmaz_Ahmet_111044014::Cell& first, const Ozyilmaz_Ahmet_111044014::Cell& second) {
	return !(first == second);
}
Ozyilmaz_Ahmet_111044014::Cell Ozyilmaz_Ahmet_111044014::Cell::operator++()//�nce
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
Ozyilmaz_Ahmet_111044014::Cell Ozyilmaz_Ahmet_111044014::Cell::operator++(int)//sonra
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
ostream & operator<<(ostream & output, const Ozyilmaz_Ahmet_111044014::Cell& outCell)
{
	output << "This Cell Row" << outCell.GetPosRow() << endl;
	output << "This Cell Column" << outCell.GetPosColumn() << endl;
	output << "This Cell Value" << outCell.GetCellValue() << endl;
	return output;
}
istream & operator>>(istream & input, Ozyilmaz_Ahmet_111044014::Cell & outCell)
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
