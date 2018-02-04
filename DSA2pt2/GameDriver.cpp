// GameDriver.cpp
// Adam Al-Jumaily
// A00362836

#include "Board.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {

	cout << "Simulated Tic-Tac-Toe Game\n"
		<< "Adam Al-Jumaily\n\n"
		<< "Use the enter key to go to the next turn.\n\n";
	
	Board *game = new Board();
	string input;
	while (true) {
		game->nextMove();
		game->displayBoard();
		game->checkState();
		if (game->gameOngoing()) {
			cin.ignore();
		}
		else {
			cout << "Press Enter to start a new game.\nEnter Q to quit.\n";
			getline(cin, input);
			if (input == "q" || input == "Q") {
				game->endGame();
			}
			else {
				// clears up memory and starts a new game.
				delete game;
				game = new Board();
			}
		}
	}
	
}