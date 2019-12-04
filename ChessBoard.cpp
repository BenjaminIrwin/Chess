#include"ChessBoard.h"

using namespace std;

ChessBoard::ChessBoard()
{
		initChessBoard();
};


void ChessBoard::initChessBoard()
{
	cout << "New game beginning..." << endl << endl;

	for (int i = 0; i < NUM_ROWS; i++)
     for (int j = 0; j < NUM_COLS; j++)
       board[i][j] = NULL;

			 //Set black pieces
			 for (int j = 0; j < NUM_COLS; j++)
			 				board[1][j] = new Pawn(Black, this);

				board[0][0] = new Rook(Black);
/*
				board[0][1] = new Knight(Black);
				board[0][2] = new Bishop(Black);
				board[0][3] = new Queen(Black);
				board[0][4] = new King(Black);
				board[0][5] = new Bishop(Black);
				board[0][6] = new Knight(Black);
*/
				board[0][7] = new Rook(Black);

				//Set white pieces
				for (int j = 0; j < NUM_COLS; j++)
 			 				board[6][j] = new Pawn(White, this);

 				board[7][0] = new Rook(White);
/*
 				board[7][1] = new Knight(White);
 				board[7][2] = new Bishop(White);
 				board[7][3] = new Queen(White);
 				board[7][4] = new King(White);
 				board[7][5] = new Bishop(White);
 				board[7][6] = new Knight(White);
*/
 				board[7][7] = new Rook(White);

				printBoard();
}

void ChessBoard::submitMove(string origin, string destination)
{
		//SAMPLE CALL: 	cb.submitMove("D7", "D6");

		int originColumn = static_cast<int>(origin[0]) - 65;
		int originRow = static_cast<int>(origin[1]) - 49;

		int destinationColumn = static_cast<int>(destination[0]) - 65;
		int destinationRow = static_cast<int>(destination[1]) - 49;


		cout << "ORIGIN: " << originColumn << "  " << originRow << endl;
		cout << "DESTINATION: " << destinationColumn << "  " << destinationRow << endl;


		if(board[originRow][originColumn]->isMoveValid(originColumn, originRow,
																										destinationColumn,
																										destinationRow))
		{
			board[destinationRow][destinationColumn] = board[originRow][originColumn];
			board[originRow][originColumn] = NULL;
			printBoard();
		} else
		{
			cout << "MOVE INVALID." << endl;
		}

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
