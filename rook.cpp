#include "rook.h"

using namespace std;
#include <iostream>

char Rook::getSymbol(){

		if(this->side == White)
		{
			//cerr << "White..." << endl;
			return 'r';
		}
		else
		{
			//cerr << "Black..." << endl;
			return 'R';
		}
}

std::string Rook::getName()
{
	return "rook";
}


bool Rook::isMoveValid(int originColumn, int originRow, int destinationColumn,
													int destinationRow){

		//Can ONLY move sideways OR backwards
		//If its first move then can move two forward.
		//Otherwise just one.

		if((abs(originColumn - destinationColumn)) && (abs(originRow - destinationRow)))
		{
			cout << "ROOK MOVED NON-STRAIGHT." << endl;
			return false;
		}

		if(!(straightCheck(originRow, originColumn, destinationRow, destinationColumn)))
		{
			cout << "Something in the way!" << endl;
			return false;
		}

		return true;

	}
