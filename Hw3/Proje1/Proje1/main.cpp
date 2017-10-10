/*Connected Four Game */
/*AHMET ÖZYILMAZ 111044014 HOMEWORK 2*/
#include "ConnectFour.h"




int main() {
	char command = '.';
	while (1) {

	/*InputValidator();
	InitialBoard();
	PrintGameBoard();
	Play();*/

	cout << "if you want to quit enter q or enter different character" << endl;
	cin >> command;
	if (command == 'q' || command == 'Q')
	break;
	}
return 0;
}