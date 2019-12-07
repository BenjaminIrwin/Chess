#include "king.h"
#include <iostream>

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

bool King::getSpecialStatus()
{
	return castle;
}

bool King::isMoveValid(int originColumn, int originRow, int destinationColumn, int destinationRow){

		//Can't move sideways or backwards
		//If its first move then can move two forward.
		//Otherwise just one.
		//If destination is an enemy then can move diagonal.


		/*castling conditions: 
		     1) King has not moved
		     2) King is attempting to moved leftwards/rightwards 2 squares. This is the only way to trigger a castle
		     3) The 2 squares leftwards/rightwards are unoccupied */
	
	if(hasMoved == false)
	{
		if((abs(originRow - destinationRow) == 0) && 
		((abs(originColumn - destinationColumn) == 2) || (abs(originColumn - destinationColumn) == 3)))
		{
			if(straightCheck(originRow, originColumn, destinationRow, destinationColumn))
			{		
				//castle = true;
				board_->signalCastle();
				return true;
			}
		}
	}
		

		if(abs(originColumn - destinationColumn) > 1 || abs(originRow - destinationRow) > 1)
			return false;

		return true;
}
