/*Connected Four Game */
/*AHMET ÖZYILMAZ 111044014 HOMEWORK 3*/
#include "ConnectFour.h"

int ConnectFour::CellCounter = 0;
int ConnectFour::GameCount = 0;

int main() {
	ConnectFour GameThree("input1.txt");

	if (GameThree.getGameisEnded() == false)
		GameThree.Play();
	int a;
	cin >> a;
	return 0;
}