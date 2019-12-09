#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "helper.h"

class Bishop : public Piece {
public:

	//Bishop constructor
	Bishop(colour side, ChessBoard* board_) : Piece(side, board_) {};

	//Bishop destructor
	~Bishop() {};

	//Symbol getter for print
	char getSymbol();
	
	//Return name
	std::string getName();
	
	bool isMoveValid(int originColumn, int originRow, int destinationColumn,
				int destinationRow);//Do I need this?

};


#endif
