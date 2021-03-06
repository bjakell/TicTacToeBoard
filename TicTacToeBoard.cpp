#include "TicTacToeBoard.h"

/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X)
  {
    turn = O;
  }
  else
  {
    turn = X;
  }
  
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  //Out of bounds
  if((row < 0 || row > 2) || (column < 0 || row > 2))
  {
    return Invalid;
  }
  
  //Piece already in place
  if(board[row][column] != Blank)
  {
    return board[row][column];
  }
  else
  {
    board[row][column] = turn;
    Piece temp = turn;
    toggleTurn();
    return temp;
  }
  
  return Invalid;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(board[row][column] == Blank)
  {
    return Blank;
  }
  else if((row < 0 || row > 2) || (column < 0 || column > 2))
  {
    return Invalid;
  }
  else
  {
    return board[row][column];
  }
  
  return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece array[3][3];
  
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      array[i][j] = getPiece(i, j);
    }
  }
  
  for(int i = 0; i < 3; i++)
  {
    if(turn == array[i][0] && turn == array[i][1] && turn == array[i][2])
    {
      return turn;
    }
    else if(turn == array[0][i] && turn == array[1][i] && turn == array[2][i])
    {
      return turn;
    }
    else if(turn == array[0][0] && turn == array[1][1] && turn == array[2][2])
    {
      return turn;
    }
    else if(turn == array[0][2] && turn == array[1][1] && turn == array[2][0])
    {
      return turn;
    }
  }
  
  return Invalid;
}