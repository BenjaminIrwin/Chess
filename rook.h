#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "helper.h"

class Rook : public Piece {
public:

//Rook constructor
	Rook(colour side)	: Piece(side) {};

//Rook destructor
	~Rook() {};

	char getSymbol();

	bool isMoveValid(int originColumn, int originRow, int destinationColumn,
														int destinationRow);
};

#endif
