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
			int destinationRow)
{
	//Diagonal movement
	if(abs(originRow - destinationRow) == abs(originColumn 
						- destinationColumn))
	{
		if(!(diagonalCheck(originRow, originColumn, destinationRow, 
					destinationColumn)))
		{
			return false;
		}

		return true;

	}
	
	//Straight movement
	if(originColumn == destinationColumn || originRow == destinationRow)
	{
		if(!(straightCheck(originRow, originColumn, destinationRow, 
				destinationColumn)))
		{
			return false;
		}

		return true;

	}


	return false;

}
