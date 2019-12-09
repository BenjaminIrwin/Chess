#include <iostream>

#include "helper.h"
#include "errors.h"
#include <string>

using namespace std;

void checkError(int error)
{
	switch(error) {
		case NO_ERROR:
			return;
		case PARAMETERS_OUT_OF_BOUNDS:
			cout << "Error: parameters invalid." << endl;
			break;
		case ORIGIN_SAME_AS_DESTINATION:
			cout << "Error: destination is the same as origin." << endl;
			break;
		case ORIGIN_SPACE_EMPTY: 
			cout << "Error: origin space empty." << endl;
			break;
		case MOVING_OPPOSING_PIECE: 
			cout << "Error: moving opposing piece." << endl;
			break;
		case MOVING_ONTO_OWN_PIECE:
			cout << "Error: moving onto own piece." << endl;
			break;
		case INVALID_MOVE: 
			cout << "Error: invalid move." << endl;
			break;
		case MOVING_INTO_CHECK:
			cout << "Error: moving into check position." << endl;
			break;
	}
}

int input_check (string origin, string destination)
{

	if(origin == destination)
	{
		return 2;

	}

	if(origin.length() != 2)
	{
		return 1;
	}

	if(destination.length() != 2)
	{
		return 1;
	}

	return 0;
}

bool rangeCheck (int number)
{
	if(number >= 0 && number < NUM_ROWS)
		return true;
	else
		return false;

}
