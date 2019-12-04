#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "knight.h"

class Knight : public Piece {
public:

//Knight constructor
	Knight(colour side)	: Piece(side) {};

//Knight destructor
	~Knight() {};

//Symbol getter for print
	char getSymbol();

	bool isMoveValid(int originColumn, int originRow, int destinationColumn,
														int destinationRow);
};

#endif
