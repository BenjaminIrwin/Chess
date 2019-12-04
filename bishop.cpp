#include "bishop.h"

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

bool Bishop::isMoveValid(int originColumn, int originRow, int destinationColumn,
													int destinationRow){

		//Can't move sideways or backwards
		//If its first move then can move two forward.
		//Otherwise just one.
		//If destination is an enemy then can move diagonal.

		//If moved backwards
		if((destinationRow < originRow))
			return false;

		//If column shift is more than 1
	  if((originColumn % destinationColumn) > 1)
			return false;

	  //If moves sideways
		if((originColumn % destinationColumn) && !(originRow % destinationRow))
			return false;

	  //If moved more than one space forward on non-first move
		if((destinationRow - originRow > 1) && !(hasMoved))
			return false;

		return true;
}
