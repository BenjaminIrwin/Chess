#ifndef PIECE_H
#define PIECE_H

#include "helper.h"

class Piece {
public:
	colour side;
	bool hasMoved;

//Piece constructor
	Piece(colour side) : side(side), hasMoved(false) {};

//Piece destructor
//	virtual ~Piece{};

//PURE virtual
	virtual char getSymbol() = 0;
	virtual bool isMoveValid(int originColumn, int originRow, int destinationColumn,
														int destinationRow) = 0;

//	std::string getPossibleMoves();

};


#endif
