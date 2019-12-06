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

//ERROR HERE!!!!!! DO FIRST THING

	//IF pawn moves forwards once
	//IF pawn moves forwards twice (without blocking and with first move)


	//If moved backwards
	if(((this->side == Black) && (destinationRow > originRow))
				|| ((this->side == White) && (destinationRow < originRow)))
	{
//		cout << "PAWN MOVES BACKWARDS" << endl;
		return false;
	}

//If pawn captures diagonally
	if(((abs(destinationRow - originRow) == 1) && (abs(destinationColumn - originColumn) == 1)) &&
	!(board_->isPositionEmpty(destinationRow, destinationColumn)))
	//&& (this->getSide() != board_->getSide(destinationRow, destinationColumn)))
	{
			if((abs(originRow - destinationRow) == 1) || (abs(originColumn - destinationColumn) == 1))
				return true;
	}

//If pawn advances 1 square forwards
	if(abs(destinationRow - originRow) == 1 && abs(destinationColumn - originColumn) == 0
		&& board_->isPositionEmpty(destinationRow, destinationColumn))
	{
		return true;
	}

//If pawn advances 2 squares forwards if it has moved yet and the path is not blocked
	if((abs(destinationRow - originRow) == 2) && abs(destinationColumn - originColumn) == 0 &&
	!(this->hasMoved) && (straightCheck(originRow, originColumn, destinationRow, destinationColumn)))
		return true;

	return false;
}
