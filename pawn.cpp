#include "pawn.h"
#include <iostream>
#include <cstdlib>
using namespace std;

char Pawn::getSymbol(){

		if(this->side == White)
		{
			return 'p';
		}
		else
		{
			return 'P';
		}
}

bool Pawn::isMoveValid(int originColumn, int originRow, int destinationColumn,
													int destinationRow){

	cout << "CHECKING MOVE VALIDITY..." << abs(destinationRow - originRow) << endl;

	//Can't move sideways or backwards
	//If its first move then can move two forward.
	//Otherwise just one.
	//If destination is an enemy then can move diagonal.

	//If moved backwards
	if(((this->side == White) && (destinationRow > originRow))
				|| ((this->side == Black) && (destinationRow < originRow)))
	{
		cout << "1." << endl;
		return false;
	}

	//If column shift is more than 1
  if(abs(destinationColumn - originColumn) > 1)
	{
		cout << "2." << endl;
		return false;
	}

  //If moves sideways
	if((abs(originColumn - destinationColumn)) && !(abs(originRow - destinationRow)))
	{
		cout << "3." << endl;
		return false;
	}

	//If moved more than 2 rows forward
	if(abs(destinationRow - originRow) > 2)
		return false;

  //If moved more than one space forward on non-first move
	if((abs(originRow - destinationRow) == 2) && !(hasMoved))
	{
		cout << "4." << endl;
		return false;
	}

	cout << "MOVE VALID" << endl;

	return true;
}
