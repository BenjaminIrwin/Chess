#ifndef KING_H
#define KING_H

#include "piece.h"
#include "helper.h"

class King : public Piece {
public:
	King(colour side, ChessBoard* board_) : Piece(side, board_)  {};

	~King() {};

	std::string getName();

	bool isMoveValid(int originColumn, int originRow, int destinationColumn,
				int destinationRow);
};

#endif
