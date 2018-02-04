// Board.cpp
// Adam Al-Jumaily
// A00362836

#include <iostream>
#include <time.h>
#include "Board.h"

/**********************
	Private Functions
**********************/

void Board::declareWinner(int w) {
	gameOn = false;
	if (w == 1) {
		std::cout << "\n\nO wins!\n\n";
	}
	else if (w == 2) {
		std::cout << "\n\nX wins!\n\n";
	}
}

void Board::declareFull() {
	gameOn = false;
	std::cout << "\n\nNo winner...\n\n";
}

void Board::checkRows() {
	for (int i = 0; i < 3; i++) {
		if ( (!board[i][0].isEmpty()) &&
			(board[i][0].getContent() ==
			board[i][1].getContent()) &&
			(board[i][1].getContent() ==
			board[i][2].getContent()) ) {

			//Program exit point...
			declareWinner(board[i][0].getContent());
		}
	}
}

void Board::checkColumns() {
	for (int i = 0; i < 3; i++) {
		if ( (!board[0][i].isEmpty()) &&
			(board[0][i].getContent() ==
			board[1][i].getContent()) &&
			(board[1][i].getContent() ==
			board[2][i].getContent()) ) {

			//Program exit point...
			declareWinner(board[0][i].getContent());
		}
	}
}

void Board::checkDiagonals() {
		if ( (!board[0][0].isEmpty()) &&
			(board[0][0].getContent() ==
			board[1][1].getContent()) &&
			(board[1][1].getContent() ==
			board[2][2].getContent()) ) {

			//Program exit point...
			declareWinner(board[0][0].getContent());
		}
		else if ((!board[2][0].isEmpty()) &&
				(board[2][0].getContent() ==
				board[1][1].getContent()) &&
				(board[1][1].getContent() ==
				board[0][2].getContent()))
		{

			//Program exit point...
			declareWinner(board[2][0].getContent());
		}
}


/**********************
	Public Functions
**********************/

Board::Board() {

	// Fills a vector of size 9 with the values 0-8.
	emptySlots = std::vector<int>(9);
	for (int i = 0; i < 9; i++) {
		emptySlots[i] = i;
	}
	xTurn = true;
	gameOn = true;
	turnNum = 0;
}

void Board::displayBoard() const {
	if (gameOn) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << "|";
				if (board[i][j].getContent() == 1) {
					std::cout << "O";
				}
				else if (board[i][j].getContent() == 2) {
					std::cout << "X";
				}
				else if (board[i][j].getContent() == 0) {
					std::cout << "_";
				}
			}
			std::cout << "|" << std::endl;
		}
	}
}

void Board::checkState() {
	// No possible winner or full board before turn 5. Short-circuit.
	if (turnNum < 5) {
		return;
	}
	// Checks rows, columns, and diagonals for state info.
	else {
		// Possible exit points...
		checkRows();
		checkColumns();
		checkDiagonals();
	}
}

void Board::nextMove() {
	if (turnNum == 9) {
		// Program exit point...
		declareFull();
	}
	else {
		/* Generates a random number based on the vector size.
		   Uses that number to index the vector and based on the
		   returned value, sets the content of a cell to the boolean
		   value xTurn plus 1. A false xturn value would yield 0+1=1,
		   which corresponds to the 'O' content in the Cell object.

		   Uses local time as a seed for random values.
		*/
		int cellSelect;
		std::srand(time(NULL));
		cellSelect = std::rand() % emptySlots.size();
		switch (emptySlots[cellSelect]) {
		case 0:
			board[0][0].setContent(xTurn + 1);
			break;
		case 1:
			board[0][1].setContent(xTurn + 1);
			break;
		case 2:
			board[0][2].setContent(xTurn + 1);
			break;
		case 3:
			board[1][0].setContent(xTurn + 1);
			break;
		case 4:
			board[1][1].setContent(xTurn + 1);
			break;
		case 5:
			board[1][2].setContent(xTurn + 1);
			break;
		case 6:
			board[2][0].setContent(xTurn + 1);
			break;
		case 7:
			board[2][1].setContent(xTurn + 1);
			break;
		case 8:
			board[2][2].setContent(xTurn + 1);
			break;
		}
		/* Removes the indexed value from the vector, thereby decreasing its
		   size and maintaining that it only contains empty cells.

		   Increments turnNum and flips the value of xTurn.
		*/
		emptySlots.erase(emptySlots.begin() + cellSelect);
		turnNum++;
		xTurn = !xTurn;
	}
}

bool Board::gameOngoing() const {
	return gameOn;
}

void Board::endGame() const{
	exit(0);
}