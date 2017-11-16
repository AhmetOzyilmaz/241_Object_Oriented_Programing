#include "ConnectFourPlusUndo.h"


/*
*	Desciription : //This game has 2 type command Load and Save
*	Input		   : const string& taking command from user
*	Return Value   : If a valid file operation its returns true, is not return false
*/
void Ozyilmaz_Ahmet_111044014::ConnectFourPlusUndo::UndoMove()
{
	cout << "ALL MOVES -> " << allMoves << endl;

	allMoves.pop_back();
	char column = allMoves[allMoves.size() - 1];
	allMoves.pop_back();

	for (int i = 0; i < getRow(); ++i) {
		if (getCell(i, static_cast<int>(column - 65)).GetCellValue() != EMTHY) {
			SetGameBoard(i, static_cast<int>(column-65), '.');
			break;
		}
	}
	//ask please
	if (GetWhoIsWillPlay() == 1)
		SetWhoIsWillPlay(2);
	else
		SetWhoIsWillPlay(1);

}

