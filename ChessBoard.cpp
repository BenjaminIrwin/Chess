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
	initChessBoard();
	//		configureShadowboard();
}

void ChessBoard::initChessBoard()
{
	cout << "New game beginning..." << endl << endl;

	for (int i = 0; i < NUM_ROWS; i++)
		for (int j = 0; j < NUM_COLS; j++)
			board[i][j] = NULL;

	//	int** shadowboard_ = shadowboard[0][0]

	//Set white pieces
	for (int j = 0; j < NUM_COLS; j++)
		board[1][j] = new Pawn(White, this);

	board[0][0] = new Rook(White, this);

	board[0][1] = new Knight(White, this);
	board[0][2] = new Bishop(White, this);
	board[0][3] = new Queen(White, this);
	board[0][4] = new King(White, this);
	board[0][5] = new Bishop(White, this);
	board[0][6] = new Knight(White, this);

	board[0][7] = new Rook(White, this);

	//Set Black pieces
	for (int j = 0; j < NUM_COLS; j++)
		board[6][j] = new Pawn(Black, this);

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
/*
   void ChessBoard::configureShadowboard()
   {
   for (int i = 0; i < NUM_ROWS; i++)
   for (int j = 0; j < NUM_COLS; j++)
   shadowboard[i][j] = 0;

   for (int i = 0; i < NUM_ROWS; i++)
   for (int j = 0; j < NUM_COLS; j++)
   if(board[i][j] != NULL)
   shadowboard[i][j] = 1;

   }
 */
void ChessBoard::submitMove(string origin, string destination)
{
	//SAMPLE CALL: 	cb.submitMove("D7", "D6");
	if(!input_check(origin, destination))
	{
		cout << "PARAMETERS INVALID" << endl;
		return;
	}

	int originColumn = static_cast<int>(origin[0]) - 65;
	int originRow = static_cast<int>(origin[1]) - 49;
	int destinationColumn = static_cast<int>(destination[0]) - 65;
	int destinationRow = static_cast<int>(destination[1]) - 49;

	if(!(checkMove(originRow, originColumn, destinationRow, destinationColumn)))
		return;

	cout << board[originRow][originColumn]->getSide() << " " << board[originRow][originColumn]->getName()
		<< " moves from " << origin << " to " << destination << endl;

	if(board[destinationRow][destinationColumn] != NULL)
	{
		cout << board[originRow][originColumn]->getSide() << " takes " <<
			board[destinationRow][destinationColumn]->getSide()
			<< " " << board[destinationRow][destinationColumn]->getName() << endl;
	}

	move(originRow, originColumn, destinationRow, destinationColumn);
	board[destinationRow][destinationColumn]->movedOn();
//	cout << "h1" << endl;
	this->white_turn = !(this->white_turn);
//	cout << "h2" << endl;

	cout << "Checking for check..." << endl;
	if(check())
	{
		cout << "CHECK FOUND." << endl;
		if(white_turn)
			cout <<  "White in check";		
		else
			cout << "Black in check";

		if(mateDetect())
		{
			cout << "mate! Game over." << endl;
			return;
		}

		cout << "." << endl; 		
	} else
	{
		cout << "CHECK NOT FOUND. CHECKING FOR STALEMATE..." << endl;
		if(mateDetect())
		{
			cout << "STALEMATE!" << endl;
		}
	}


	printBoard();

	cout << endl;

}

bool ChessBoard::checkMove(int originRow, int originColumn, int destinationRow, int destinationColumn)
{

	if(!(rangeCheck(originRow) && rangeCheck(originColumn) && rangeCheck(destinationRow) &&
				rangeCheck(destinationColumn)))
		return false;

	if(board[originRow][originColumn] == NULL)
	{
	//	cout << "Origin space empty." << endl;
		return false;
	}

//	cout << "1. " << endl;

	if((this->white_turn != board[originRow][originColumn]->side))
	{
	//	cout << "Attempt to move the opposing player's piece." << endl;
		return false;

	}

//	cout << "2. " << endl;

	if(board[destinationRow][destinationColumn] != NULL)
	{
		if(board[destinationRow][destinationColumn]->side == board[originRow][originColumn]->side)
		{
		//	cout << "Can't take own piece." << endl;
			return false;
		}
	}

//	cout << "3. " << endl;

	if(!(board[originRow][originColumn]->isMoveValid(originColumn, originRow,
					destinationColumn,
					destinationRow)))
	{
		return false;
	}

//	cout << "4. " << endl;

	if((!checkDetect(originRow, originColumn, destinationRow, destinationColumn)))
		return false;

//	cout << "5. " << endl;
//	cout << "6. " << endl;

	return true;

}

bool ChessBoard::mateDetect()//Precondition:player is in check
{
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLS; j++)
		{
			if (board[i][j] != NULL && (((board[i][j]->getSide() == "Black") && (white_turn == false))
						|| ((board[i][j]->getSide() == "White") && (white_turn == true))))
					{
						for(int k = 0; k < NUM_ROWS; k++)
						{
							for(int l = 0; l < NUM_COLS; l++)
							{
								if(checkMove(i, j, k, l))
									return false;
							}
						}
					}
		}
	}

	return true;

}
/*
bool ChessBoard::stalemateDetect()
{

}
*/

bool ChessBoard::checkDetect(int originRow, int originColumn, int destinationRow, int destinationColumn)
{
	Piece* temp = board[destinationRow][destinationColumn];

	move(originRow, originColumn, destinationRow, destinationColumn);

	if(check())
	{
//		cout << "Move puts player into check" << endl;
		move(destinationRow, destinationColumn, originRow, originColumn);
		board[destinationRow][destinationColumn] = temp;
		return false;
	}

	move(destinationRow, destinationColumn, originRow, originColumn);
	board[destinationRow][destinationColumn] = temp;

	return true;
}

void ChessBoard::move(int originRow, int originColumn, int destinationRow, int destinationColumn)
{
	board[destinationRow][destinationColumn] = board[originRow][originColumn];
	board[originRow][originColumn] = NULL;
}

void ChessBoard::locateKing(int& column, int& row)
{
	for(int i = 0; i < NUM_ROWS; i++)
		for(int j = 0; j < NUM_COLS; j++)
			if(board[i][j] != NULL && board[i][j]->side == white_turn && board[i][j]->getName() == "king")
			{
				row = i;
				column = j;
			}
}


bool ChessBoard::canKingMove()
{
	int column;
	int row;

	locateKing(column, row);

	for(int i = column - 1; i <= column + 1; i++)
		for (int j = row - 1; j <= row + 1; j++)
		{
			if(i == column && j == row)
				continue;
			else
				if(checkMove(row, column, j, i))
					return true;
		}
	return false;
}

bool ChessBoard::check()
{

	int column;
	int row;

	locateKing(column, row);

	for(int i = 0; i < NUM_ROWS; i++)
		for(int j = 0; j < NUM_COLS; j++)
			if(board[i][j] != NULL && board[i][j]->side != white_turn)
				if(board[i][j]->isMoveValid(j, i, column, row))
				{
					return true;
				}


	return false;
}

/*
   std::string ChessBoard::getSide(int row, int column)
   {
   string side = board[row][column]->getSide();

   return side;
   }
 */

bool ChessBoard::isPositionEmpty(int row, int column)
{
	if(board[row][column] == NULL)
		return true;
	else
		return false;
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
