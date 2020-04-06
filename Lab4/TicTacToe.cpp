#include "TicTacToe.h"

//constructor
TicTacToe::TicTacToe()
	:winner("")
{
	Game::_width,Game::_height = 5;
	turns = 0;
	longestStringLength = 3;

	for (int i = 0; i < _width; ++i) {
		for (int j = 0; j < _height; ++j) {
			cout << "nice";
			board[i][j] = " ";
		}
	}
}

//prints out the gameboard with the dimensions along the sides
ostream& operator<<(ostream& out, const TicTacToe& f) {
	for (int i = f._height - 1; i >= 0; i--) {
		out << setw(3) << i;
		for (int j = 0; j < f._width; j++) {
			out << setw(3) << f.board[i][j];
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
		if (board[1][i] == board[2][i] && board[1][i] == board[3][i] && board[1][i] != " ") {
			winner = board[1][i];
			return true;
		}
	}

	//check columns
	for (int i = 1; i < _width - 1; i++) {
		if (board[i][1] == board[i][2] && board[i][1] == board[i][3] && board[i][1] != " ") {
			winner = board[i][1];
			return true;
		}
	}

	//check diags
	if (board[1][1] == board[2][2] && board[1][1] == board[3][3] && board[1][1] != " ") {
		winner = board[1][1];
		return true;
	}
	if (board[1][3] == board[2][2] && board[1][3] == board[3][1] && board[1][3] != " ") {
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
			if (board[i][j] == " ") {
				return false;
			}
		}
	}
	return true;
}

//indicates whose turn it is and adds the valid input coordinate to the board
error TicTacToe::turn() {
	string piece;
	if (turns % 2 == 0) { //X's turn
		piece = "X";
	}
	else { //O's turn
		piece = "O";
	}
	unsigned int x, y;
	unsigned int& xref = x;
	unsigned int& yref = y;
	error result = prompt(xref, yref);
	cout << result << endl;
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
	if (piece == "O") {
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

