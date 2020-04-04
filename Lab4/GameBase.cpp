#include <iostream>
#include "GameBase Header.h"
#include "Main Header.h"
#include "TicTacToe.h"

Game* create_game(int argc, char* argv[]) {
	shared_ptr<Game> pointer = nullptr;
	if (argv[1] == "TicTacToe") {
		return (class Game*) new TicTacToe();
	}
	else {
		return 0;
	}
}

//takes in the input and parses to indicate where the user moved
error Game::prompt(unsigned int& xcoord, unsigned int& ycoord) {
	cout << "Type in a valid coordinate to place a game piece or type quit to end game" << endl;
	string save;
	getline(cin, save);
	for (char& character : save) {
		if (character == ',') {
			character = ' ';
			break;
		}
	}
	if (save == "quit") {
		cout << "quit" << endl;
		return error::quit;
	}
	istringstream iss(save);
	if (save.length() > 3) {
		return error::failure;
	}
	string x, y;
	iss >> xcoord >> ycoord;
	if (xcoord > 0 && xcoord < 4 && ycoord>0 && ycoord < 4) {
		if (board[xcoord][ycoord] == Piece::empty) {
			cout << "Placed: " << xcoord << "," << ycoord << endl;
			return error::success;
		}
	}
	return error::failure;
}


//calls the turn function repeatedly until i) someone has won 2) there is a draw or 3) someone has quit
result Game::play() {
	bool end = true;
	result res;
	while (end == true) {
		cout << "Turn: " << turns << endl;
		error result;
		result = turn();
		if (result == error::quit) {
			cout << "User has quit. There have been " << turns << " rounds." << endl;
			res = result::quitEnd;
			break;
		}
		if (done() == true) {
			if (winner == Piece::o) {
				cout << "Player O has won!" << endl;
			}
			if (winner == Piece::x) {
				cout << "Player X has won!" << endl;
			}
			res = result::winner;
			end = false;
			break;
		}
		if (draw() == true) {
			cout << "It's a draw!" << endl;
			res = result::draw;
			end = false;
			break;
		}
		cout << "-------------------------------" << endl;
	}
	return res;
}

