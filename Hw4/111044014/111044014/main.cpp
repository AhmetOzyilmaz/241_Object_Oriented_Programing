/*Connected Four Game */
/*AHMET ÖZYILMAZ 111044014 HOMEWORK 3*/
#include "ConnectFour.h"

int ConnectFour::CellCounter = 0;
int ConnectFour::GameCount = 0;

int main() {

	// First Mode 
	char mode;
	while (1) {
		cout << "Enter Play Mode" << endl;
		cin >> mode;

		if (mode == 'S') {
			ConnectFour mode1;
			cout << "Enter Game Mode" << endl;
			cin >> mode;
	
			if (mode1.getGameisEnded() == false)
				mode1.Play();
		}
		else if (mode == 'M') {
			ConnectFour GameOne;
			ConnectFour GameTwo(5, 10);
			ConnectFour GameThree("input1.txt");
			ConnectFour GameFour(4, 7, 2);
			ConnectFour GameFive;

			while (ConnectFour::GetGameCounter() > 0) {
				cout << "Game Counter " << ConnectFour::GetGameCounter() << endl;
				cout << "Cell Counter " << ConnectFour::GetCellCounter() << endl;
				if (GameOne.getGameisEnded() == false)
					GameOne.Play();

				cout << "Cell Counter " << ConnectFour::GetCellCounter() << endl;
				if (GameTwo.getGameisEnded() == false)
					GameTwo.Play();

				cout << "Cell Counter " << ConnectFour::GetCellCounter() << endl;
				if (GameThree.getGameisEnded() == false)
					GameThree.Play();

				cout << "Cell Counter " << ConnectFour::GetCellCounter() << endl;
				if (GameFour.getGameisEnded() == false)
					GameFour.Play();

				cout << "Game Counter " << ConnectFour::GetGameCounter() << endl;
				cout << "Cell Counter " << ConnectFour::GetCellCounter() << endl;

				if (GameFour.getGameisEnded() == false)
					GameFive.Play();

				bool result = GameOne.IsBetter(GameTwo, GameThree);
				if (result)
					cout << " GameTwo is better than GameThree " << endl;
				else
					cout << " GameTwo is worse than GameThree " << endl;
			}
		}
	}

	return 0;
}