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

std::string Pawn::getName()
{
	return "pawn";
}

bool Pawn::isMoveValid(int originColumn, int originRow, int destinationColumn,
													int destinationRow){

	cout << "CHECKING MOVE VALIDITY..." << abs(destinationRow - originRow) << endl;

//ERROR HERE!!!!!! DO FIRST THING

	//IF pawn moves forwards once
	//IF pawn moves forwards twice (without blocking and with first move)


	//If moved backwards
	if(((this->side == Black) && (destinationRow > originRow))
				|| ((this->side == White) && (destinationRow < originRow)))
	{
		cout << "PAWN MOVES BACKWARDS" << endl;
		return false;
	}

	//If column shift is more than 1
  if(abs(destinationColumn - originColumn) > 1)
	{
		cout << "PAWN MOVES TOO FAR ALONG" << endl;
		return false;
	}

  //If moves sideways
	if((abs(originColumn - destinationColumn)) && !(abs(originRow - destinationRow)))
	{
		cout << "PAWN MOVES SIDEWAYS" << endl;
		return false;
	}

	if(!(board_->isPositionEmpty(destinationColumn, destinationRow)))
	{
			if((abs(originRow - destinationRow) != 1) && (abs(originColumn - destinationColumn) != 1))
			 	return false;
	}
			return false;

	//If moved more than 2 rows forward
	if(abs(destinationRow - originRow) > 2)
		return false;

  //If moved more than one space forward on non-first move
	if((abs(originRow - destinationRow) == 2) && hasMoved)
	{
		cout << "PAWN MOVED MORE THAN ONE SPACE FORWARD ON FIRST MOVE" << endl;
		hasMoved = false;
		return false;
	}

	//Can only move diagonally if there is an enemy piece in the destination

	//if(straightCheck(originRow, originColumn, destinationRow, destinationColumn))
	//	return true;

	cout << "PAWN MOVE VALID" << endl;

	return true;
}
