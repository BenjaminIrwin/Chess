#ifndef KING_H
#define KING_H

#include "piece.h"
#include "helper.h"

class King : public Piece {
public:
	std::string name = "King";

//Piece constructor
	King(colour side) : Piece(side) {};

	~King() {};

//Symbol getter for print
		char getSymbol();

		bool isMoveValid(int originColumn, int originRow, int destinationColumn,
															int destinationRow);
};


#endif
