#include "queen.h"
#include <iostream>

using namespace std;

char Queen::getSymbol(){

		if(this->side == White)
		{
			return 'q';
		}
		else
		{
			return 'Q';
		}
}

std::string Queen::getName()
{
	return "queen";
}

bool Queen::isMoveValid(int originColumn, int originRow, int destinationColumn,
													int destinationRow){

		if(abs(originRow - destinationRow) == abs(originColumn - destinationColumn))//If diagonal
		{
			if(!(diagonalCheck(originRow, originColumn, destinationRow, destinationColumn)))
			{
//				std::cout << "Something in the way of Queen!" << std::endl;
				return false;
			}

			return true;

		}

		if(originColumn == destinationColumn || originRow == destinationRow)//If on the same row or same column
		{
			if(!(straightCheck(originRow, originColumn, destinationRow, destinationColumn)))
			{
//				cout << "Something in the way of Queen!" << endl;
				return false;
			}

			return true;

		}


		return false;

}
