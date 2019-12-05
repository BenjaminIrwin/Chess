#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "helper.h"

class Bishop : public Piece {
public:

//Piece constructor
	Bishop(colour side, ChessBoard* board_) : Piece(side, board_) {};

	~Bishop() {};

//Symbol getter for print
	char getSymbol();

	std::string getName();


	bool isMoveValid(int originColumn, int originRow, int destinationColumn,
														int destinationRow);

};


#endif
