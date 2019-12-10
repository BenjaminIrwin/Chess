#include "bishop.h"
#include <iostream>

using namespace std;

std::string Bishop::getName()
{
	return "Bishop";
}

bool Bishop::isMoveValid(int originColumn, int originRow, int destinationColumn,
				int destinationRow)
{
	//If bishop moves non-diagonally 
	if(abs(originRow - destinationRow) != abs(originColumn 
							- destinationColumn))
	{
		return false;
	}

	//If bishop encounters obstacle
	if(!(diagonalCheck(originRow, originColumn, destinationRow, 
				destinationColumn)))
	{
		return false;
	}

		return true;
}
