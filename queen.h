#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "helper.h"

class Queen : public Piece {
public:

//Queen constructor
	Queen(colour side, ChessBoard* board_) : Piece(side, board_)  {};
//Queen destructor
	~Queen() {};

//Symbol getter for print
	char getSymbol();

	std::string getName();


	bool isMoveValid(int originColumn, int originRow, int destinationColumn,
														int destinationRow);
};


#endif