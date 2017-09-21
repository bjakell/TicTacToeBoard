/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}
*/

TEST(TicTacToeBoardTest, sanityCheck)
{
	TicTacToeBoard board;
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, getWinnerNoPiece)
{
	TicTacToeBoard board;
	Piece result = board.getWinner();
	
	ASSERT_EQ(Invalid, result);
}

TEST(TicTacToeBoardTest, toggleTurnWorking)
{
	TicTacToeBoard board;
	
	Piece result;
	result = board.toggleTurn();
	
	ASSERT_NE(X, result);
}

TEST(TicTacToeBoardTest, placePieceInBounds)
{
	TicTacToeBoard board;
	Piece result = board.placePiece(0,0);
	
	ASSERT_EQ(X, result);
}

TEST(TicTacToeBoardTest, placePieceOutOfBounds)
{
	TicTacToeBoard board;
	Piece result = board.placePiece(4,4);
	
	ASSERT_EQ(Invalid, result);
}