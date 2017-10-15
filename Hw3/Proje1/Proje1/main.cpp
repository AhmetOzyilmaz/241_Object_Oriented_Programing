/*Connected Four Game */
/*AHMET ÖZYILMAZ 111044014 HOMEWORK 3*/
#include "ConnectFour.h"

int ConnectFour::CellCounter = 0;
int ConnectFour::GameCount = 0;

int main() {

	ConnectFour GameOne;
	ConnectFour GameTwo(5, 10);
	ConnectFour GameThree(8, 8, 2);
	ConnectFour GameFour(4, 7, 2);


	cout << "Cell Counter " << ConnectFour::GetCellCounter() << endl;
	GameOne.Play();

	cout << "Cell Counter " << ConnectFour::GetCellCounter() << endl;
	GameTwo.Play();

	cout << "Cell Counter " << ConnectFour::GetCellCounter() << endl;
	GameTwo.Play();

	cout << "Cell Counter " << ConnectFour::GetCellCounter() << endl;
	GameTwo.Play();

	cout << "Cell Counter " << ConnectFour::GetCellCounter() << endl;
	GameTwo.Play();


return 0;
}