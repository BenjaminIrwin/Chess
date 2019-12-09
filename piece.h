#ifndef PIECE_H
#define PIECE_H

#include "helper.h"
#include "ChessBoard.h"
#include<string>

class ChessBoard;

class Piece {
protected:
	colour side;
	bool hasMoved;
	ChessBoard* board_;

	bool diagonalCheck(int originRow, int originColumn, int destinationRow, 
				int destinationColumn);

	bool straightCheck(int originRow, int originColumn, int destinationRow, 
				int destinationColumn);
public:
	//Piece constructor
	Piece(colour side, ChessBoard* board_) : side(side), hasMoved(false), 
						board_(board_) {};

	//Piece destructor
	virtual ~Piece(){};

	virtual char getSymbol() = 0;

	virtual bool isMoveValid(int originColumn, int originRow, 
				int destinationColumn, int destinationRow) = 0;

	virtual std::string getName() = 0;

	colour getSide() const {return side;} 

	std::string printSide();

	void setMoved();

	bool getMoved() const {return hasMoved;} 

};


#endif
