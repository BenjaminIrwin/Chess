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

	//If pawn move backwards
	if(((this->side == Black) && (destinationRow > originRow))
		|| ((this->side == White) && (destinationRow < originRow)))
		return false;

	//If pawn captures diagonally
	if(((abs(destinationRow - originRow) == 1) && 
	(abs(destinationColumn - originColumn) == 1)) &&
	!(board_->isPositionEmpty(destinationRow, destinationColumn)))
	{
			if((abs(originRow - destinationRow) == 1) || 
				(abs(originColumn - destinationColumn) == 1))
				return true;
	}

	//If pawn moves one forwards
	if(abs(destinationRow - originRow) == 1 && 
	abs(destinationColumn - originColumn) == 0 &&
	board_->isPositionEmpty(destinationRow, destinationColumn))
		return true;

	//Pawn moves two forwards on first move to an empty square
	if((abs(destinationRow - originRow) == 2) && 
	abs(destinationColumn - originColumn) == 0 &&
	!(this->hasMoved) && 
	(board_->isPositionEmpty(destinationRow, destinationColumn)) && 
	straightCheck(originRow, originColumn, destinationRow, destinationColumn))
		return true;
	
	return false;
}
