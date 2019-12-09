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

	/*Checks for any interposing pieces on a diagonal line between the 
	moving (origin piece and its ultimate destination).
	Returns false if an obstacle is encountered.*/
	bool diagonalCheck(int originRow, int originColumn, int destinationRow, 
				int destinationColumn);

	/*Checks for any interposing pieces on a straight line between the 
	moving (origin piece and its ultimate destination).
	Returns false if an obstacle is encountered.*/
	bool straightCheck(int originRow, int originColumn, int destinationRow, 
				int destinationColumn);
public:
	/*Piece constructor:
	Initialises piece colour, hasMoved and a pointer to the board*/
	Piece(colour side, ChessBoard* board_) : side(side), hasMoved(false), 
						board_(board_) {};
	//Virtual piece destructor
	virtual ~Piece(){};

	//Pure virtual: returns symbol for print
	virtual char getSymbol() = 0;

	/*Pure virtual checks move validity with respect to:
	1. The range of the relevant piece.
	2. Whether there are any obstructions in its path (knight exempt).*/
	virtual bool isMoveValid(int originColumn, int originRow, 
				int destinationColumn, int destinationRow) = 0;

	//Pure virtual: returns name in form of string
	virtual std::string getName() = 0;

	//Returns side (Black or White) in form of colour enum
	colour getSide() const {return side;} 

	//Returns side (Black or White) in form of string 
	std::string printSide();

	//Returns boolean variable 'hasMoved' to show if a piece has previously 
	//moved.
	bool getMoved() const {return hasMoved;} 


	//Sets 'hasMoved' to true after a piece's first and subsequent moves
	void setMoved();


};


#endif
