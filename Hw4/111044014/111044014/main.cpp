/*Connected Four Game */
/*AHMET ÖZYILMAZ 111044014 HOMEWORK 3*/
#include "ConnectFour.h"

int ConnectFour::CellCounter = 0;
int ConnectFour::GameCount = 0;

int main() {
	char mode;
	cout << "Enter Game Mode: " << endl;
	cout << "Multiplayer Mode -> 'M': " << endl;
	cout << "Single player Mode -> 'S': " << endl;
	cin >> mode;

	if (mode == 'S' || mode == 's') {
		ConnectFour mode1(mode);
		while (1) {
			if (mode1.getGameisEnded() == false) {
				mode1.Play();
			}
			else
				break;
		}
	}
	else	if (mode == 'M' || mode == 'm') {
	
		const int size = 5;
		ConnectFour* M = new ConnectFour[size]{ { mode } ,{ mode } ,{ mode } ,{ mode } ,{ mode } };
		int gameNum = 0;
		while (1) {
			cout << "Enter Game Number to  play : ";
			cin >> gameNum;
			gameNum -= 1;
			if (cin.fail()) {
				cin.clear(); //This corrects the stream.
				cin.ignore(); //This skips the left over stream data.
				cerr << " <--->ILLEGAL<---> Wrong input For game number \n";
			}
			if (M[gameNum].getGameisEnded() == false) {
				M[gameNum].Play();
			}
			if (ConnectFour::GetGameCounter()<= 0)
				break;
		}
	
	}
	return 0;
}
