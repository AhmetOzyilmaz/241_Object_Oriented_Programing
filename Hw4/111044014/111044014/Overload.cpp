#include "ConnectFour.h"

ConnectFour & ConnectFour::operator=(const ConnectFour& other)
{
	for (int i = 0; i < gameSizeRow; ++i)
		delete[] gameCells[i];
	delete[]gameCells;
	CopyConnectedFour(other);
	return *this;
}
bool ConnectFour::operator==(const ConnectFour & other)
{
	if (gameSizeRow != other.gameSizeRow)
		return false;
	if (gameSizeColumn != other.gameSizeColumn)
		return false;
	for (int i = 0; i < gameSizeRow; ++i) {
		for (int j = 0; j < gameSizeColumn; ++j) {
			if (gameCells[i][j].GetCellValue() != other.gameCells[i][j].GetCellValue())
				return false;
		}
	}
	return true;
}
bool ConnectFour::operator!=(const ConnectFour & other)
{
	return !(*this == other);
}
