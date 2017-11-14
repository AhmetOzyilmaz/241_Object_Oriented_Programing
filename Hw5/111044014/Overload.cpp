#include "ConnectFour.h"

ConnectFour & ConnectFour::operator=(const ConnectFour& other)
{
	for (int i = 0; i < BoardRow; ++i)
		delete[] gameCells[i];
	delete[]gameCells;
	CopyConnectedFour(other);
	return *this;
}
bool ConnectFour::operator==(const ConnectFour & other)
{
	if (BoardRow != other.BoardRow)
		return false;
	if (PrintBoard != other.PrintBoard)
		return false;
	for (int i = 0; i < BoardRow; ++i) {
		for (int j = 0; j < PrintBoard; ++j) {
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
