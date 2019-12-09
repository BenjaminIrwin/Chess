#ifndef PAWN_H
#define PAWN_H

#include "helper.h"
#include "piece.h"

class ChessBoard;

class Pawn : public Piece {
public:
	Pawn(colour side, ChessBoard* board_) : Piece(side, board_)  {};

	~Pawn() {};

	char getSymbol();

	std::string getName();

	bool isMoveValid(int originColumn, int originRow, int destinationColumn, 
							int destinationRow);
};

#endif
