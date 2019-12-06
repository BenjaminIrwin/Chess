#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "helper.h"
#include "piece.h"

class Piece;

class ChessBoard {

public:
	Piece *board[NUM_ROWS][NUM_COLS];
	bool white_turn = true;

	ChessBoard();

	~ChessBoard() {};

//sets up board and pieces in position for start.
	void initChessBoard();

	void printBoard();

	void printFrame(int row);

	void printRow(int row);

//Parse a move, and make it if legal
	void submitMove(std::string origin, std::string destination);

	void move(int originRow, int originColumn, int destinationRow, int destinationColumn);

	void configureShadowboard();

	bool isPositionEmpty(int row, int column);

//	std::string getSide(int row, int column);

	bool check();

	bool checkMove(int originRow, int originColumn, int destinationRow, int destinationColumn);

	bool checkDetect(int originRow, int originColumn, int destinationRow, int destinationColumn);

	bool canKingMove();

	void locateKing(int& column, int& row);

/*
//Tests whether a square contains no chess piece
	isEmpty();

//Frees the whole board
	freeChessBoard();

//Switches turns
	switchTurns();

//Tests whether a move is legal
	isLegal();

//check if the proposed move is coming from the right person whose turn it is and that they are using one of their own pieces
	isTurnAndPieceValid();

//check if the destination square is a valid square on the chess board either unoccupied or occupied by an enemy piece
	isDestinationSquareValid();

//Check if proposed move would place the player themselves into check.
	isSelfCheck()

//Provides move info to standard output stream
	printMove();

//return the name of the opponent piece that the player is capturing (if any)
	isOpponentPieceCaptured();

//Undo the move from source to destination
	undoMove();

//Check if a given player is in check
	isInCheck();

//Check for stalemate
	isStalemate();

//Check if no more moves can be made
	isGameOver();
*/

/*
FOR LATER:
canCastle —> Check if a king can castle

legalCastle —> Checks if a king passes through check during castling

friend class King —> For castling
*/

};

#endif
