#include "king.h"
#include <iostream>

using namespace std;

char King::getSymbol()
{

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
			int destinationRow)
{
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
		

	if(abs(originColumn - destinationColumn) > 1 || 
		abs(originRow - destinationRow) > 1)
		return false;

	return true;
}
