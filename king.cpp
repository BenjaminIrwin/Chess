#include "king.h"

using namespace std;

char King::getSymbol(){

		if(this->side == White)
		{
			return 'k';
		}
		else
		{
			return 'K';
		}
}

std::string King::getName()
{
	return "king";
}

bool King::isMoveValid(int originColumn, int originRow, int destinationColumn,
													int destinationRow){

		//Can't move sideways or backwards
		//If its first move then can move two forward.
		//Otherwise just one.
		//If destination is an enemy then can move diagonal.

		if(abs(originColumn - destinationColumn) > 1 || abs(originRow - destinationRow) > 1)
			return false;

		return true;
	}
