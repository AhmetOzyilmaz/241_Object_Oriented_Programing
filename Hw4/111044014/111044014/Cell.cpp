#include "ConnectFour.h"

//Operator == for cell
 bool operator ==( const ConnectFour::Cell& first,const ConnectFour::Cell& second){
	 if (first.GetCellValue() == second.GetCellValue())
		 return true;
	return false;
}
 //Operator != for cell
 bool operator !=(const ConnectFour::Cell& first, const ConnectFour::Cell& second) {
	 return !(first == second);
 }