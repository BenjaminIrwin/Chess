#include "rook.h"

using namespace std;
#include <iostream>

char Rook::getSymbol(){

		if(this->side == White)
		{
			return 'r';
		}
		else
		{
			return 'R';
		}
}

std::string Rook::getName()
{
	return "rook";
}


bool Rook::isMoveValid(int originColumn, int originRow, int destinationColumn,
			int destinationRow)
{

	//If non-straight move
	if((abs(originColumn - destinationColumn)) && (abs(originRow - destinationRow)))
	{
		return false;
	}

	//If obstacle encountered
	if(!(straightCheck(originRow, originColumn, destinationRow, destinationColumn)))
	{
		return false;
	}

	return true;

}
