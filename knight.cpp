#include "knight.h"

using namespace std;

std::string Knight::getName()
{
	return "Knight";
}

bool Knight::isMoveValid(int originColumn, int originRow, int destinationColumn,
				int destinationRow)
{

	if((abs(originColumn - destinationColumn) != 1) || 
					(abs(originRow - destinationRow) != 2))
	{
		if((abs(originColumn - destinationColumn) != 2) || 
					(abs(originRow - destinationRow) != 1))
		{
			return false;
		}
	}
	return true;
}

