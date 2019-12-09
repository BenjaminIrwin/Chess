#ifndef KING_H
#define KING_H

#include "piece.h"
#include "helper.h"

class King : public Piece {
public:

	//Piece constructor
	King(colour side, ChessBoard* board_) : Piece(side, board_)  {};

	~King() {};

	//Symbol getter for print
	char getSymbol();

	std::string getName();


	bool isMoveValid(int originColumn, int originRow, int destinationColumn,
				int destinationRow);

};

#endif
