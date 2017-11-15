#include <iostream>
#include "ConnectFourPlus.h"
#include "ConnectFourPlusUndo.h"
#include "ConnectFourDiag.h"

using namespace std;
using namespace Ozyilmaz_Ahmet_111044014;

int main() {
	char choise = ' ';
	cout << "Enter Character for Game " << endl;
	cout << " P (plus), D (diag) ve U (undo) " << endl;
	cin >> choise;
	if (choise == 'P') {
		ConnectFourPlus cp;
	}
	else if (choise == 'D') {
		ConnectFourDiag cd;

	}else if (choise == 'U') {
		ConnectFourPlusUndo cu;

	}

	int a; 
	cin >> a;

	return 0;
}