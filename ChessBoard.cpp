#include"ChessBoard.h"
#include "pawn.h"
#include "rook.h"
#include "queen.h"
#include "king.h"
#include "bishop.h"
#include "knight.h"
#include <string>
#include <iostream>

using namespace std;

ChessBoard::ChessBoard()
{
	castlingInfo = new castleData;
	for (int i = 0; i < NUM_ROWS; i++)
		for (int j = 0; j < NUM_COLS; j++)
			board[i][j] = NULL;
}

ChessBoard::~ChessBoard()
{
	delete castlingInfo;
	
	for (int i = 0; i < NUM_ROWS; i++)
		for (int j = 0; j < NUM_COLS; j++)
		{
			delete board[i][j];
			board[i][j] = NULL;
		}
}

void ChessBoard::resetBoard()
{
	cout << "New game beginning..." << endl;
	white_turn = true;

	for (int i = 0; i < NUM_ROWS; i++)
		for (int j = 0; j < NUM_COLS; j++)
			board[i][j] = NULL;


	//Set pawns 
	for (int j = 0; j < NUM_COLS; j++)
		board[6][j] = new Pawn(Black, this);

	for (int j = 0; j < NUM_COLS; j++)
		board[1][j] = new Pawn(White, this);

	//Set white pieces
	board[0][0] = new Rook(White, this);
	board[0][1] = new Knight(White, this);
	board[0][2] = new Bishop(White, this);
	board[0][3] = new Queen(White, this);
	board[0][4] = new King(White, this);
	board[0][5] = new Bishop(White, this);
	board[0][6] = new Knight(White, this);
	board[0][7] = new Rook(White, this);

	//Set black pieces
	board[7][0] = new Rook(Black, this);
	board[7][1] = new Knight(Black, this);
	board[7][2] = new Bishop(Black, this);
	board[7][3] = new Queen(Black, this);
	board[7][4] = new King(Black, this);
	board[7][5] = new Bishop(Black, this);
	board[7][6] = new Knight(Black, this);
	board[7][7] = new Rook(Black, this);

	printBoard();
}

void ChessBoard::submitMove(string origin, string destination)
{
	int error = input_check(origin, destination);
	if(error != 0)
	{
		checkError(error);
		return;
	}	

	int originColumn = static_cast<int>(origin[0]) - 65;
	int originRow = static_cast<int>(origin[1]) - 49;
	int destinationColumn = static_cast<int>(destination[0]) - 65;
	int destinationRow = static_cast<int>(destination[1]) - 49;

	error = verifyMove(originRow, originColumn, destinationRow, 
				destinationColumn);
	if(error != 0)
	{
		checkError(error);
		return;
	}	

	if(castlingInfo->castle)
	{

		cout << board[originRow][originColumn]->printSide() << " " 
		<< board[originRow][originColumn]->getName() 
		<< " executes castle." << endl;

		board[originRow][originColumn]->setMoved();
		board[castlingInfo->rookOriginRow]
				[castlingInfo->rookOriginColumn]->setMoved();

		move(originRow, originColumn, originRow, destinationColumn);
		move(castlingInfo->rookOriginRow, castlingInfo->rookOriginColumn, 
					castlingInfo->rookDestinationRow, 
					castlingInfo->rookDestinationColumn);

		castlingInfo->castle = false;

	}
	else
	{
		cout << board[originRow][originColumn]->printSide() << " " << 
		board[originRow][originColumn]->getName() << " moves from " 
		<< origin << " to " << destination << endl;

		if(board[destinationRow][destinationColumn] != NULL)
		{
			cout << board[originRow][originColumn]->printSide() 
			<< " takes " <<
			board[destinationRow][destinationColumn]->printSide()
			<< " " << board[destinationRow][destinationColumn]
			->getName() << endl;
		}

		move(originRow, originColumn, destinationRow, destinationColumn);
		board[destinationRow][destinationColumn]->setMoved();
	}

	this->white_turn = !(this->white_turn);

	if(check())
	{
		inCheck = true;
		if(white_turn)
			cout <<  "White in check";		
		else
			cout << "Black in check";

		if(mateDetect())
		{
			cout << "mate! Game over";
		}

		cout << "." << endl; 		
	} else
	{
		inCheck = false;
		if(mateDetect())
		{
			cout << "Stalemate! Game over." << endl;
		}
	}


	printBoard();

	cout << endl;

}

int ChessBoard::verifyMove(int originRow, int originColumn, int destinationRow, 
				int destinationColumn)
{
	if(!(rangeCheck(originRow) && rangeCheck(originColumn) && 
		rangeCheck(destinationRow) && rangeCheck(destinationColumn)))
		return 1;

	if(board[originRow][originColumn] == NULL)
	{
		return 3;
	}

	if((this->white_turn != board[originRow][originColumn]->getSide()))
	{
		return 4;

	}

	if(board[destinationRow][destinationColumn] != NULL)
	{
		if(board[destinationRow][destinationColumn]->getSide() == 
					board[originRow][originColumn]->getSide())
		{
			return 5;
		}
	}

	if(!(board[originRow][originColumn]->isMoveValid(originColumn, originRow,
					destinationColumn,
					destinationRow)))
	{
		return 6;
	}

	if(board[originRow][originColumn]->getName() == "king" 
							&& castlingInfo->castle)
	{
		if(verifyCastle(originRow, originColumn, destinationRow, 
				destinationColumn))
		{
			return 0;
		} else
		{
			castlingInfo->castle = false;
			return 6;
		}	
	} else if((!checkDetect(originRow, originColumn, destinationRow, 
				destinationColumn)))
		return 7;

	return 0;

}

bool ChessBoard::verifyCastle(int originRow, int originColumn, int destinationRow, 
				int destinationColumn)
{

	if(inCheck)
		return false;

	bool kingside;

	if(originColumn < destinationColumn)
	{
		kingside = true;
		if(!white_turn)
		{
			castlingInfo->rookOriginRow = NUM_ROWS - 1;
			castlingInfo->rookOriginColumn = NUM_COLS - 1;
			castlingInfo->rookDestinationRow = NUM_ROWS - 1;
			castlingInfo->rookDestinationColumn = NUM_COLS - 3;
		}

		if(white_turn)
		{
			castlingInfo->rookOriginRow = 0;
			castlingInfo->rookOriginColumn = NUM_COLS - 1;
			castlingInfo->rookDestinationRow = 0;
			castlingInfo->rookDestinationColumn = NUM_COLS - 3;
		}
	} else
	{
		kingside = false;
		if(!white_turn)
		{

			if(board[7][1] != NULL)
				return false;

			castlingInfo->rookOriginRow = NUM_ROWS - 1;
			castlingInfo->rookOriginColumn = 0;
			castlingInfo->rookDestinationRow = NUM_ROWS - 1;
			castlingInfo->rookDestinationColumn = 3;
		}

		if(white_turn)
		{
			if(board[0][1] != NULL)
				return false;

			castlingInfo->rookOriginRow = 0;
			castlingInfo->rookOriginColumn = 0; 
			castlingInfo->rookDestinationRow = 0;
			castlingInfo->rookDestinationColumn = 3;
		}
	}

	if(board[castlingInfo->rookOriginRow][castlingInfo->rookOriginColumn]
								->getMoved())
		return false;
	
	if(kingside)
	{
		int path = destinationColumn - 1;

		if(!checkDetect(originRow, originColumn, originRow, path))
			return false;

		if(!checkDetect(originRow, path, originRow, destinationColumn))
			return false;

	}

	if(!kingside)
	{
		int path = destinationColumn + 1;

		if(!checkDetect(originRow, originColumn, originRow, path))
			return false;

		if(!checkDetect(originRow, originColumn, originRow, 
				destinationColumn))
			return false;

	}

	return true;

}

bool ChessBoard::mateDetect()
{
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			if (board[i][j] != NULL && 
				(((board[i][j]->getSide() == Black) && 
				(white_turn == false)) || 
				((board[i][j]->getSide() == White) && 
				(white_turn == true))))
					{
						for(int k = 0; k < NUM_ROWS; 
									k++)
						{
							for(int l = 0; l < 	
								NUM_COLS; l++)
							{
								if(verifyMove
								(i, j, k, l) == 0)
								{
									return 
									false;
									
								}
							}
						}
					}
		}
	}

	return true;

}

bool ChessBoard::checkDetect(int originRow, int originColumn, int destinationRow, 
				int destinationColumn)
{
	Piece* temp = board[destinationRow][destinationColumn];

	move(originRow, originColumn, destinationRow, destinationColumn);

	if(check())
	{
		move(destinationRow, destinationColumn, originRow, originColumn);
		board[destinationRow][destinationColumn] = temp;
		return false;
	}

	move(destinationRow, destinationColumn, originRow, originColumn);
	board[destinationRow][destinationColumn] = temp;

	return true;
}

void ChessBoard::move(int originRow, int originColumn, int destinationRow, 
			int destinationColumn)
{
	board[destinationRow][destinationColumn] = board[originRow][originColumn];
	board[originRow][originColumn] = NULL;
}

void ChessBoard::locateKing(int& column, int& row)
{
	for(int i = 0; i < NUM_ROWS; i++)
		for(int j = 0; j < NUM_COLS; j++)
			if(board[i][j] != NULL && 
				board[i][j]->getSide() == white_turn && 
				board[i][j]->getName() == "king")
			{
				row = i;
				column = j;
			}
}

bool ChessBoard::check()
{

	int column;
	int row;

	locateKing(column, row);

	for(int i = 0; i < NUM_ROWS; i++)
		for(int j = 0; j < NUM_COLS; j++)
			if(board[i][j] != NULL && board[i][j]->getSide() 
								!= white_turn)
				if(board[i][j]->isMoveValid(j, i, column, row))
				{
					return true;
				}

	return false;
}

bool ChessBoard::isPositionEmpty(int row, int column)
{
	if(board[row][column] == NULL)
		return true;
	else
		return false;
}

void ChessBoard::signalCastle()
{
	castlingInfo->castle = true;
}	

void ChessBoard::printBoard() {
	cout << "    ";
	for (int r=0; r<NUM_ROWS; r++)
		cout << (char) ('A'+r) << "   ";
	cout << '\n';
	for (int r=0; r<NUM_ROWS; r++) {
		printFrame(r);
		printRow(r);
	}
	printFrame(NUM_ROWS);
}

void ChessBoard::printFrame(int row) {
	if (!(row % 8))
		cout << "  +===============================+" << '\n';
	else
		cout << "  +---+---+---+---+---+---+---+---+" << '\n';
}

void ChessBoard::printRow(int row) {
	cout << (char) ('1' + row) << " ";
	for (int i=0; i<NUM_COLS; i++) {
		cout << '|' << " ";
		if(board[row][i] == NULL)
		{
			cout << ' ';
		}
		else
		{
			cout << board[row][i]->getSymbol();
		}

		cout << ' ';
	}
	cout << "|" << '\n';
}
