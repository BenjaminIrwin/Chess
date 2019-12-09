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

	void printBoard();

	void printFrame(int row);

	void printRow(int row);

	void move(int originRow, int originColumn, int destinationRow, 
			int destinationColumn);

	bool check();

	int verifyMove(int originRow, int originColumn, int destinationRow, 
			int destinationColumn);

	bool checkDetect(int originRow, int originColumn, int destinationRow, 
				int destinationColumn);

	void locateKing(int& column, int& row);

	bool mateDetect();

	bool verifyCastle(int originRow, int originColumn, int destinationRow, 
				int destinationColumn);
public:
	ChessBoard();

	~ChessBoard();

	void resetBoard();

	void submitMove(std::string origin, std::string destination);

	bool isPositionEmpty(int row, int column);

	void signalCastle();
};

#endif
