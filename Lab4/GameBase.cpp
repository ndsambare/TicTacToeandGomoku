#include <iostream>
#include "GameBase Header.h"
#include "Main Header.h"
#include "TicTacToe.h"
#include "Gomoku.h"

//we have to add a play method in GameBase I think 
Game* Game::create_game(int argc, char* argv[]) {
	cout << argv[1] << endl;
	if (strcmp(argv[1], "TicTacToe")==0) {
		return new TicTacToe();
	}
	else if (strcmp(argv[1],"Gomoku")==0) {
		return new Gomoku();
	}
	else {
		return nullptr;
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
	iss >> xcoord >> ycoord;
	if (xcoord > 0 && xcoord < 4 && ycoord>0 && ycoord < 4) {
		if (board[xcoord][ycoord] == " ") {
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
		error result = turn();
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
