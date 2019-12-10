#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "helper.h"
#include "piece.h"

class Piece;

class ChessBoard {

private:
	Piece *board[NUM_ROWS][NUM_COLS];
	bool white_turn = true;
	bool inCheck = false;
	struct castleData
	{
		bool castle = false;
		int rookOriginRow = 0;
		int rookOriginColumn = 0;
		int rookDestinationRow = 0;
		int rookDestinationColumn = 0;
		
	} *castlingInfo;

	/* 'Moves' a piece from origin to destination. Origin square 
	set to NULL.*/
	void move(int originRow, int originColumn, int destinationRow, 
			int destinationColumn);
	
	/* Checks every piece opposing the current turn on the board. If
	one piece can reach the current player's king, returns truer, 
	otherwise, false. */
	bool check();

	/* Verifies the validity of a move before it is made. Checks:
		1. If requested move is within board range
		2. If origin is not empty
		3. If origin is of current turn side
		4. If destination is not empty
		5. If destination is piece of own side
		6. If move is valid with respect to the piece capabilities
		7. If castle is requested and if it is legitimate
		8. If move will result in check 
	Returns 0 if move is valid or relevant error code otherwise.*/
	int verifyMove(int originRow, int originColumn, int destinationRow, 
			int destinationColumn);

	/* Simulates a move to verify if it will cause a side to put him/
	herself into check */
	bool checkDetect(int originRow, int originColumn, int destinationRow, 
				int destinationColumn);

	/* Iterates through the board to locate the current side's king */
	void locateKing(int& column, int& row);

	/* Detects checkmate or stalemate by verifying if there are any
	remaining moves available to a side. Returns true if a side is 
	unable to move, and false if there is a move available. */
	bool mateDetect();

	/* Verifies the validity of a castling before it is made. Checks:
		1. That the relevant side is not in check
		2. Whether the proposed castling is kingside or queenside
		3. Whether the relevant rook has already moved
		4. If the king's proposed path will not lead it through check
	Returns true if castling is legitimate and false otherwise.*/
	bool verifyCastle(int originRow, int originColumn, 
				int destinationColumn);
public:
	/*Chessboard constructor initialises 2d array of pointers to pieces
	and a dynamic struct containing castling information */
	ChessBoard();

	/*Chessboard destructor deallocates dynamically allocated pieces in
	board 2d array */
	~ChessBoard();

	/* Resets the turn to white and resets all elements in the 2d 
	board array to NULL, before setting up the board pieces */ 
	void resetBoard();

	/* Executes a move by:
		1. Converting the given parameters to integers
		2. Checking validity of a move
		3. printing the outcome
		4. If move is valid, executing it. 
	Following this, switchs the turn and checks for check, checkmate 
	and stalemate*/
	void submitMove(std::string origin, std::string destination);

	/* Checks if a board position is empty. Returns true if empty, false
	otherwise */
	bool isPositionEmpty(int row, int column);

	/* Switches the castle boolean variable in an initialised castleData
	struct to true, signalling that a castle is being attempted */
	void signalCastle();
};

#endif
