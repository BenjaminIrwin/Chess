#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "helper.h"

class Queen : public Piece {
public:
	Queen(colour side, ChessBoard* board_) : Piece(side, board_)  {};

	~Queen() {};

	char getSymbol();

	std::string getName();

	bool isMoveValid(int originColumn, int originRow, int destinationColumn,
				int destinationRow);
};


#endif
