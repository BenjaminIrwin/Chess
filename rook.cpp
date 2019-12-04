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


bool Rook::isMoveValid(int originColumn, int originRow, int destinationColumn,
													int destinationRow){

		cout << "CHECKING MOVE VALIDITY..." << abs(destinationRow - originRow) << endl;

		//Can ONLY move sideways OR backwards
		//If its first move then can move two forward.
		//Otherwise just one.

		if((abs(originColumn - destinationColumn)) && (abs(originRow - destinationRow)))
			return false;

		cout << "MOVE VALID" << endl;

		return true;

	}
