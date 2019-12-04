#ifndef PAWN_H
#define PAWN_H

#include "helper.h"
#include "piece.h"

class ChessBoard;

class Pawn : public Piece {
public:
	ChessBoard* board;

//Pawn constructor
	Pawn(colour side, ChessBoard* board) : Piece(side), board(board) {};

//Pawn destructor
	~Pawn() {};

//Symbol getter for print
	char getSymbol();

	bool isMoveValid(int originColumn, int originRow, int destinationColumn,
														int destinationRow);
};

#endif
