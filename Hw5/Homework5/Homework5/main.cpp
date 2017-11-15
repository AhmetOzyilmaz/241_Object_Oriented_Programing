#include <iostream>
#include "ConnectFourPlusUndo.h"
#include "ConnectFourDiag.h"

using namespace Ozyilmaz_Ahmet_111044014;

int main() {
	char choise = ' ';
	cout << "Enter Character for Game " << endl;
	cout << " P (plus), D (diag) ve U (undo) " << endl;
	cin >> choise;
	if (choise == 'P') {
		ConnectFourPlus cp;
		cp.Play();
	}
	else if (choise == 'D') {
		ConnectFourDiag cd;
		cd.Play();

	}else if (choise == 'U') {
		ConnectFourPlusUndo cu;
		cu.Play();
	}

	int a; 
	cin >> a;

	return 0;
}