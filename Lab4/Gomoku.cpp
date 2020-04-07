
#include "Gomoku.h"
#include "GameBase Header.h"
#include "Main Header.h"

using namespace std;

//constructor
Gomoku::Gomoku()
{
	Game::_width = 20;
	Game::_height = _width;
	piecesInARow = 5;
	longestStringLength = 3;
	isGomoku = true;
	winner = "";
	for (int i = 0; i < _height; ++i) {
		for (int j = 0; j < _width; ++j) {
			board.push_back(" ");
		}
	}
}

//indicates whose turn it is and adds the valid input coordinate to the board
error Gomoku::turn() {
	string piece;
	if (turns % 2 == 0) { //Blacks's turn
		piece = "B";
	}
	else { //White's turn
		piece = "W";
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
		board.at((__int64)_width * yref + xref) = piece; //inserts piece
	}
	if (result == error::quit) {
		return error::quit;
	}
	print();
	cout << endl;
	cout << "Player ";
	if (piece == "W") {
		cout << "W: ";
	}
	else {
		cout << "B: ";
	}
	for (int i = 0; i < _height; ++i) {
		for (int j = 0; j < _width; ++j) {
			if (board.at((__int64)_width * i + j) == piece) {
				cout << i << ", " << j << "; ";
			}
		}
	}
	cout << endl;
	++turns; // increments number of turns that have happened
	return error::success;
}


//prints out the gameboard with the dimensions along the sides
ostream& operator<<(ostream& out, const Gomoku& f) {
	for (int i = f._height - 1; i >= 0; i--) {
		out << setw(f.longestStringLength) << i;
		for (int j = 0; j < f._width; j++) {
			out  << f.board.at((__int64)f._width*i+j) << setw(f.longestStringLength);
		}
		out << endl;
	}
	out << "  X";
	for (int i = 0; i < f._width; i++) {
		out << i << setw(f.longestStringLength);
	}
	return out;
}

//function that calls the ostream to print
void Gomoku::print() {
	cout << *this << endl; 
}

//checks 3 criteria: i) if board is full, ii) if someone has won iii) if it is possible for either player to win
bool Gomoku::draw() {
	//to check if either player can win, we make a two copies of the game board
	//for both copies, we will fill the empty spots on the board with all black or white pieces
	//if done(copy) returns true, then it is possible for that player to win
	vector<string> blackBoardCopy;
	vector<string> whiteBoardCopy;
	for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
			blackBoardCopy.push_back(board.at((__int64)_width * i + j));
				whiteBoardCopy.push_back(board.at((__int64)_width * i + j));

		}
	}
	string blackPiece = "B";
	string whitePiece = "W";
	for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
			if (blackBoardCopy.at((__int64)_width * i + j) == " ") {
				blackBoardCopy.push_back(blackPiece); 
			}
			if (whiteBoardCopy.at((__int64)_width * i + j) == " ") {
				whiteBoardCopy.push_back(whitePiece);
			}
		}
	}

	if (done(blackBoardCopy) == false) {
		return false; 
	}
	if (done(whiteBoardCopy) == false) {
		return false; 
	}
	if (done()) {
		return false; 
	}
	else {
		for (int i = 0; i < _height; i++) {
			for (int j = 0; j < _width; j++) {
				if (board.at((__int64)_width*i+j) == " ") {
					return false;
				}
			}
		}
		return true; 
	}

}

//version of the done() method that takes in a copy of the game board rather than the actual game board
bool Gomoku::done(vector<string> &copy) {
	int count = 0;
	string pieceCheck;
	//check diagonals going bottom left to top right
	for (int i = 0; i < _height; ++i) {
		int xval = 0;
		int yval = i;
		while (xval < _width && yval < _height) {
			xval++;
			yval++;
			if (xval > 0 && yval > i && xval < _width && yval < _height) {
				pieceCheck = copy.at((__int64)_width * yval + xval);
				if (pieceCheck == copy.at((__int64)_width * ((__int64)yval - 1) + ((__int64)xval - 1)) && pieceCheck != " ") {
					++count;
				}
				else {
					count = 0;
				}
			}
			if (count == piecesInARow - 1) {
				return true;
			}
		}
	}
	count = 0;
	for (int i = 1; i < _width; ++i) {
		int xval = i;
		int yval = 0;
		while (xval < _width && yval < _height) {
			xval++;
			yval++;
			if (xval > i && yval > 0 && xval < _width && yval < _height) {
				pieceCheck = copy.at((__int64)_width * yval + xval);
				if (pieceCheck == copy.at((__int64)_width * ((__int64)yval - 1) + ((__int64)xval - 1)) && pieceCheck != " ") {
					++count;
				}
				else {
					count = 0;
				}
			}
			if (count == piecesInARow - 1) {
				return true;
			}
		}
	}
	//check diagonals going bottom right to top left
	count = 0;
	for (int i = 0; i < _height; ++i) {
		int xval = _width;
		int yval = i;
		while (xval > 0 && yval < _height) {
			xval--;
			yval++;
			if (xval < _width && yval > i && xval > 0 && yval < _height) {
				pieceCheck = copy.at((__int64)_width * yval + xval);
				if (pieceCheck == copy.at((__int64)_width * ((__int64)yval - 1) + ((__int64)xval + 1)) && pieceCheck != " ") {
					++count;
				}
				else {
					count = 0;
				}
			}
			if (count == piecesInARow - 1) {
				return true;
			}
		}
	}
	count = 0;
	for (int i = 0; i < _width; ++i) {
		int xval = i;
		int yval = 0;
		while (xval > 0 && yval < _height) {
			xval--;
			yval++;
			if (xval < i && yval > 0 && xval > 0 && yval < _height) {
				pieceCheck = copy.at((__int64)_width * yval + xval);
				if (pieceCheck == copy.at((__int64)_width * ((__int64)yval - 1) + ((__int64)xval + 1)) && pieceCheck != " ") {
					++count;
				}
				else {
					count = 0;
				}
			}
			if (count == piecesInARow - 1) {
				return true;
			}
		}
	}
	//check vertical pieces in a row
	count = 0;
	for (int i = 0; i < _width; ++i) {
		for (int j = 0; j < _height; ++j) {
			pieceCheck = copy.at((__int64)_width * j + i);
			if (j > 0) {
				if (pieceCheck == copy.at((__int64)_width * ((__int64)j - 1) + i) && pieceCheck != " ") {
					++count;
				}
				else {
					count = 0;
				}
			}
			if (count == piecesInARow - 1) {
				return true;
			}
		}
		count = 0;
	}
	//check horizontal pieces in a row
	count = 0;
	for (int i = 0; i < _height; ++i) {
		for (int j = 0; j < _width; ++j) {
			pieceCheck = copy.at((__int64)_width * i + j);
			if (j > 0) {
				if (pieceCheck == copy.at((__int64)_width * i + j - 1) && pieceCheck != " ") {
					++count;
				}
				else {
					count = 0;
				}
			}
			if (count == piecesInARow - 1) {
				return true;
			}
		}
		count = 0;
	}
	return false;
}

//checks to see if the game board has 5 in a row anywhere (diagonal, vertical, horizontal)
bool Gomoku::done() {
	int count = 0;
	string pieceCheck;
	//check diagonals going bottom left to top right
	for (int i = 0; i < _height; ++i) {
		int xval = 0;
		int yval = i;
		while (xval < _width && yval < _height) {
			xval++;
			yval++;
			if (xval > 0 && yval > i && xval <_width && yval < _height) {
				pieceCheck = board.at((__int64)_width * yval + xval);
				if (pieceCheck == board.at((__int64)_width * ((__int64)yval-1) + ((__int64)xval-1)) && pieceCheck != " ") {
					++count;
				}
				else {
					count = 0;
				}
			}
			if (count == piecesInARow - 1) {
				winner = pieceCheck;
				return true;
			}
		}
	}
	count = 0;
	for (int i = 1; i < _width; ++i) {
		int xval = i;
		int yval = 0;
		while (xval < _width && yval < _height) {
			xval++;
			yval++;
			if (xval > i && yval > 0 && xval < _width && yval < _height) {
				pieceCheck = board.at((__int64)_width * yval + xval);
				if (pieceCheck == board.at((__int64)_width * ((__int64)yval - 1) + ((__int64)xval - 1)) && pieceCheck != " ") {
					++count;
				}
				else {
					count = 0;
				}
			}
			if (count == piecesInARow - 1) {
				winner = pieceCheck;
				return true;
			}
		}
	}
	//check diagonals going bottom right to top left
	count = 0;
	for (int i = 0; i < _height; ++i) {
		int xval = _width;
		int yval = i;
		while (xval > 0 && yval < _height) {
			xval--;
			yval++;
			if (xval < _width && yval > i && xval > 0 && yval < _height) {
				pieceCheck = board.at((__int64)_width * yval + xval);
				if (pieceCheck == board.at((__int64)_width * ((__int64)yval - 1) + ((__int64)xval + 1)) && pieceCheck != " ") {
					++count;
				}
				else {
					count = 0;
				}
			}
			if (count == piecesInARow - 1) {
				winner = pieceCheck;
				return true;
			}
		}
	}
	count = 0;
	for (int i = 0; i < _width; ++i) {
		int xval = i;
		int yval = 0;
		while (xval > 0 && yval < _height) {
			xval--;
			yval++;
			if (xval < i && yval > 0 && xval > 0 && yval < _height) {
				pieceCheck = board.at((__int64)_width * yval + xval);
				if (pieceCheck == board.at((__int64)_width * ((__int64)yval - 1) + ((__int64)xval + 1)) && pieceCheck != " ") {
					++count;
				}
				else {
					count = 0;
				}
			}
			if (count == piecesInARow - 1) {
				winner = pieceCheck;
				return true;
			}
		}
	}
	//check vertical pieces in a row
	count = 0;
	for (int i = 0; i < _width; ++i) {
		for (int j = 0; j < _height; ++j) {
			pieceCheck = board.at((__int64)_width * j + i);
			if (j > 0) {
				if (pieceCheck == board.at((__int64)_width * ((__int64)j-1) + i) && pieceCheck != " ") {
					++count;
				}
				else {
					count = 0;
				}
			}
			if (count == piecesInARow-1) {
				winner = pieceCheck;
				return true;
			}
		}
		count = 0;
	}
	//check horizontal pieces in a row
	count = 0;
	for (int i = 0; i < _height; ++i) {
		for (int j = 0; j < _width; ++j) {
			pieceCheck = board.at((__int64)_width * i + j);
			if (j > 0) {
				if (pieceCheck == board.at((__int64)_width * i + j - 1) && pieceCheck != " ") {
					++count;
				}
				else {
					count = 0;
				}
			}
			if (count == piecesInARow-1) {
				winner = pieceCheck;
				return true;
			}
		}
		count = 0;
	}
	return false;
}


