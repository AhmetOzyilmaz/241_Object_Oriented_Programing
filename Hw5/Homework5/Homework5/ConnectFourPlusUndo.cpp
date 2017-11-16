#include "ConnectFourPlusUndo.h"

/*
*	Desciription : //This game has 3 type -> Load , Save and UNDO
*	Input		   : const string& taking command from user
*	Return Value   : If a valid file operation its returns true, is not return false
*/
bool Ozyilmaz_Ahmet_111044014::ConnectFourPlusUndo::CommandSelector(const string& command) {
	string filename = command.substr(5, command.size());
	if (command.substr(0, 4).compare("SAVE") == 0) {
		SaveFile(filename);
		return true;
	}
	else if (command.substr(0, 4).compare("LOAD") == 0) {
		LoadFile(filename);
		return true;
	}
	else if (command.substr(0, 4).compare("UNDO") == 0) {
		UndoMove();
		return true;
	}
	return false;
}
/*
*	Desciription : //This game has 2 type command Load and Save
*	Input		   : const string& taking command from user
*	Return Value   : If a valid file operation its returns true, is not return false
*/
void Ozyilmaz_Ahmet_111044014::ConnectFourPlusUndo::UndoMove()
{

}

