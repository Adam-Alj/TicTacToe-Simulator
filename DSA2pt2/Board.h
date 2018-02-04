#ifndef BOARD_
#define BOARD_

// Board.h
// Adam Al-Jumaily
// A00362836

#include <vector>
#include "Cell.h"

class Board {
private:
	// Creates the 3x3 gameboard of cells.
	Cell board[3][3];

	// Number of turns taken.
	int turnNum;

	// Turn control variable.
	bool xTurn;

	// Control variable to see if the game is finished or not
	bool gameOn;

	// Vector to efficiently select empty board cells
	std::vector<int> emptySlots;

	// Outputs a message declaring a winner. 1 for O, 2 for X.
	void declareWinner(int winner);

	// Outputs a message declaring that the board is full.
	void declareFull();

	// Checks the rows in the board to determine state.
	void checkRows();

	// Checks the columns in the board to determine state.
	void checkColumns();

	// Checks the two diagonals in the board to determine state.
	void checkDiagonals();

public:

	// Default constructor, initializes the board and control variables.
	Board();

	// Displays the board to the user.
	void displayBoard() const;

	// Checks to see if the previous move resulted in a winner or full board.
	void checkState();

	// Performs the next move.
	void nextMove();

	// Returns whether the game is running or not.
	bool gameOngoing() const;

	// Ends the game by exiting the program.
	void endGame() const;

};

#endif // !BOARD_
