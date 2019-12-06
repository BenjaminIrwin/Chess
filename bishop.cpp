#include "bishop.h"
#include <iostream>

using namespace std;

char Bishop::getSymbol(){

		if(this->side == White)
		{
			return 'b';
		}
		else
		{
			return 'B';
		}

}

std::string Bishop::getName()
{
	return "bishop";
}

bool Bishop::isMoveValid(int originColumn, int originRow, int destinationColumn,
													int destinationRow){

		//Can't move sideways or backwards
		//If its first move then can move two forward.
		//Otherwise just one.
		//If destination is an enemy then can move diagonal.

	if(abs(originRow - destinationRow) != abs(originColumn - destinationColumn))//If not diagonal
	{
				return false;
	}

	if(!(diagonalCheck(originRow, originColumn, destinationRow, destinationColumn)))
	{
//		std::cout << "Something in the way of Bishop!" << std::endl;
		return false;
	}


		return true;
}
