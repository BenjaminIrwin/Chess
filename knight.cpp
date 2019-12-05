#include "knight.h"

using namespace std;

char Knight::getSymbol(){

		if(this->side == White)
		{
			return 'n';
		}
		else
		{
			return 'N';
		}
}

bool Knight::isMoveValid(int originColumn, int originRow, int destinationColumn,
													int destinationRow){

		if((abs(originColumn - destinationColumn) != 1) || (abs(originRow - destinationRow) != 2))
		{
			if((abs(originColumn - destinationColumn) != 2) || (abs(originRow - destinationRow) != 1))
			{
				return false;
			}
		}
		return true;
	}


std::string Knight::getName()
{
	return "knight";
}
