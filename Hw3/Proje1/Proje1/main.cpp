﻿/*Connected Four Game */
/*AHMET ÖZYILMAZ 111044014 HOMEWORK 2*/
#include "ConnectFour.h"

int ConnectFour::CellCounter = 0;

int main() {
	ConnectFour GameOne;
	cout << "Cell Counter " << ConnectFour::GetCellCounter() << endl;
	GameOne.Play();

return 0;
}