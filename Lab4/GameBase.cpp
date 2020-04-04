#include <iostream>
#include "GameBase Header.h"
#include "Main Header.h"
#include <sstream>
#include <iostream>
#include <iomanip>

//constructor
Game::Game()
	:_width(20), _height(20), board(),longestStringLength(2)
{
	for (int i = 0; i < _width; ++i) {
		for (int j = 0; j < _height; ++j) {
			board[i][j] = Piece::empty;
		}
	}
}

//prints out the gameboard with the dimensions along the sides
ostream& operator<<(ostream& out, const Game& f) {
	for (int i = f._height - 1; i >= 0; i--) {
		out << setw(3) << i;
		for (int j = 0; j < f._width; j++) {
			if (f.board[j][i] == Piece::o) {
				out << setw(3) << "O";
			}
			if (f.board[j][i] == Piece::x) {
				out << setw(3) << "X";
			}

			if (f.board[j][i] == Piece::empty) {
				out << setw(3) << " ";
			}
		}
		out << endl;
	}
	out << "   ";
	for (int i = 0; i < f._width; i++) {
		out << setw(3) << i;
	}
	return out;
}

//checks to see if someone has won yet
bool TicTacToe::done() {
	//check rows
	for (int i = 1; i < _height - 1; i++) {
		if (board[1][i] == board[2][i] && board[1][i] == board[3][i] && board[1][i] != Piece::empty) {
			winner = board[1][i];
			return true;
		}
	}

	//check columns
	for (int i = 1; i < _width - 1; i++) {
		if (board[i][1] == board[i][2] && board[i][1] == board[i][3] && board[i][1] != Piece::empty) {
			winner = board[i][1];
			return true;
		}
	}

	//check diags
	if (board[1][1] == board[2][2] && board[1][1] == board[3][3] && board[1][1] != Piece::empty) {
		winner = board[1][1];
		return true;
	}
	if (board[1][3] == board[2][2] && board[1][3] == board[3][1] && board[1][3] != Piece::empty) {
		winner = board[1][3];
		return true;
	}

	return false;
}

//checks to see if more moves can be made
bool TicTacToe::draw() {
	if (done() == true) {
		return false;
	}
	for (int i = 1; i < _width - 1; ++i) {
		for (int j = 1; j < _height - 1; ++j) {
			if (board[i][j] == Piece::empty) {
				return false;
			}
		}
	}
	return true;
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

//indicates whose turn it is and adds the valid input coordinate to the board
error TicTacToe::turn() {
	Piece piece;
	if (turns % 2 == 0) { //X's turn
		piece = Piece::x;
	}
	else { //O's turn
		piece = Piece::o;
	}
	unsigned int x, y;
	unsigned int& xref = x;
	unsigned int& yref = y;
	error result = prompt(xref, yref);
	while (result == error::failure) {
		result = prompt(xref, yref);
	}
	if (result == error::success) {
		board[xref][yref] = piece; //inserts piece
	}
	if (result == error::quit) {
		return error::quit;
	}
	print();
	cout << endl;
	cout << "Player ";
	if (piece == Piece::o) {
		cout << "O: ";
	}
	else {
		cout << "X: ";
	}
	for (int i = 0; i < _width; ++i) {
		for (int j = 0; j < _height; ++j) {
			if (board[i][j] == piece) {
				cout << i << ", " << j << "; ";
			}
		}
	}
	cout << endl;
	++turns; // increments number of turns that have happened
	return error::success;
}

//calls the turn function repeatedly until i) someone has won 2) there is a draw or 3) someone has quit
result Game::play() {
	bool end = true;
	result res;
	while (end == true) {
		cout << "Turn: " << turns << endl;
		error result;
		if (computer == true && turns % 2 == 0) {
			result = auto_player();
		}
		else {
			result = turn();
		}
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

//makes best decision based on the game board and then places an X. Best decision is based on 1) winning 2) blocking 3) if none, then random
error Game::auto_player() {
	vector<game_piece> openSpaces;
	bool placed = false;
	//find empty spaces
	for (int i = 1; i < _width - 1; ++i) {
		for (int j = 1; j < _height - 1; ++j) {
			if (board[i][j] == Piece::empty) {
				game_piece open;
				open.display = Piece::empty;
				open.xcoord = i;
				open.ycoord = j;
				openSpaces.push_back(open);
			}
		}
	}
	//check if computer can win this turn
	for (game_piece& piece : openSpaces) {
		board[piece.xcoord][piece.ycoord] = Piece::x;
		//if piece makes the computer win, then place piece there
		if (done() == true) {
			placed = true;
			break;
		}
		else {
			board[piece.xcoord][piece.ycoord] = Piece::empty;
		}
		//if yes, then set gameboard equal to that
	}
	//if not, check if computer must block
	if (placed == false) {
		for (game_piece& piece : openSpaces) {
			board[piece.xcoord][piece.ycoord] = Piece::o;
			//if piece makes the player win, then place piece there to block
			if (done() == true) {
				placed = true;
				board[piece.xcoord][piece.ycoord] = Piece::x;
				break;
			}
			else {
				board[piece.xcoord][piece.ycoord] = Piece::empty;
			}
		}
	}
	//if not, place randomly
	if (placed == false) {
		int veclength = openSpaces.size();
		int index = rand() % veclength;
		game_piece randPiece = openSpaces[index];
		board[randPiece.xcoord][randPiece.ycoord] = Piece::x;
	}
	//print gameboard
	cout << *this << endl;
	//print where the computer went
	cout << "Computer: ";
	for (int i = 0; i < _width; ++i) {
		for (int j = 0; j < _height; ++j) {
			if (board[i][j] == Piece::x) {
				cout << i << ", " << j << "; ";
			}
		}
	}
	cout << endl;
	++turns;
	return error::success;
}