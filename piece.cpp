#include <iostream>

#include "piece.h"

using namespace std;

void Piece::movedOn()
{
    if(hasMoved == false)
      hasMoved = true;

    return;
}

std::string Piece::getSide()
{
  if(side == Black)
    return "Black";
  else
    return "White";
}

bool Piece::diagonalCheck(int originRow, int originColumn, int destinationRow, int destinationColumn)
{
  //4 directions
  int row = originRow, column = originColumn;

  while(true)//(row != destinationRow && column != destinationColumn)
  {
    if(row < destinationRow)
      row++;
    else
      row--;

    if(column < destinationColumn)
      column++;
    else
      column--;

    if(row == destinationRow && column == destinationColumn)
      return true;

    if(!(board_->isPositionEmpty(row, column)))
      return false;

  }

}

bool Piece::straightCheck(int originRow, int originColumn, int destinationRow, int destinationColumn)
{
  if(originRow == destinationRow)//If on same row
  {
    if(destinationColumn > originColumn)
    {
      for(int i = originColumn + 1; i < destinationColumn; i++)
      {
        if(!(board_->isPositionEmpty(originRow, i)))
          return false;
      }
    }

    if(destinationColumn < originColumn)
    {
      for(int i = originColumn - 1; i > destinationColumn; i--)
      {
        if(!(board_->isPositionEmpty(originRow, i)))
          return false;
      }
    }
  }

/////////////////////////////////////////////////////////////////////////////

  if(originColumn == destinationColumn)//If on same column
  {
    if(destinationRow > originRow)
    {
      for(int i = originRow + 1; i < destinationRow; i++)
      {
        if(!(board_->isPositionEmpty(i, originColumn)))
          return false;
      }
    }

    if(destinationRow < originRow)
    {
      for(int i = originRow - 1; i > destinationRow; i--)
      {
        if(!(board_->isPositionEmpty(i, originColumn)))
          return false;
      }
    }
  }
  return true;
}
