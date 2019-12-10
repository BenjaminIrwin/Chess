#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "knight.h"

class Knight : public Piece {
public:
	Knight(colour side, ChessBoard* board_) : Piece(side, board_)  {};

	~Knight() {};

	std::string getName();

	bool isMoveValid(int originColumn, int originRow, int destinationColumn,
				int destinationRow);
};

#endif
