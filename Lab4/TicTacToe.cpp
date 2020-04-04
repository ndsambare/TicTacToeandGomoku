#include "TicTacToe.h"

//constructor
TicTacToe::TicTacToe()
{
	_width,_height = 5;
	
	for (int i = 0; i < _width; ++i) {
		for (int j = 0; j < _height; ++j) {
			board[i][j] = Piece::empty;
		}
	}
}

//prints out the gameboard with the dimensions along the sides
ostream& operator<<(ostream& out, const TicTacToe& f) {
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
result TicTacToe::play() {
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
