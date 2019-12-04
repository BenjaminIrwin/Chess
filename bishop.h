#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "helper.h"

class Bishop : public Piece {
public:

//Piece constructor
	Bishop(colour side) : Piece(side) {};

	~Bishop() {};

//Symbol getter for print
	char getSymbol();

	bool isMoveValid(int originColumn, int originRow, int destinationColumn,
														int destinationRow);

};


#endif
