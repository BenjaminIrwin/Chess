#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "helper.h"

class Rook : public Piece {
public:

//Rook constructor
	Rook(colour side, ChessBoard* board_) : Piece(side, board_)  {};

//Rook destructor
	~Rook() {};

	char getSymbol();

	std::string getName();

	bool isMoveValid(int originColumn, int originRow, int destinationColumn,
														int destinationRow);
};

#endif
