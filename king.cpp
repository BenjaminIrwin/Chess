#include "king.h"
#include <iostream>

using namespace std;

std::string King::getName()
{
	return "King";
}

bool King::isMoveValid(int originColumn, int originRow, int destinationColumn, 
			int destinationRow)
{
	//If king attempts castling
	if(hasMoved == false)
	{
		if((abs(originRow - destinationRow) == 0) && 
		((abs(originColumn - destinationColumn) == 2) || 
			(abs(originColumn - destinationColumn) == 3)))
		{
			if(straightCheck(originRow, originColumn, 
					destinationRow, destinationColumn))
			{		
				board_->signalCastle();
				return true;
			}
		}
	}
		
	//If king moves more than one in any direction
	if(abs(originColumn - destinationColumn) > 1 || 
		abs(originRow - destinationRow) > 1)
		return false;

	return true;
}
