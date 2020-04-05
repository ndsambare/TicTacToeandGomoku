
#include "TicTacToe.h"
#include "GameBase Header.h"
#include "Main Header.h"

using namespace std;
//what to work on: the turn method I didn't know how to implement because I can't figure out what the game board is doing
// We also have to apparently add a Gomoku constructor that takes in parameters, and we need a done method that takes in some parameters also 
//Other than that, we have to fix the constructor that already exists so that it is compatible with the GameBase class we have

Gomoku::Gomoku() {
	_width, _height = width;

	for (int i = 0; i < _width; ++i) {
		for (int j = 0; j < _height; ++j) {
			board[i][j] = " ";
		}
	}
}

int Gomoku::turn() {

}




//prints out the gameboard with the dimensions along the sides
ostream& operator<<(ostream& out, const Gomoku& gomoku) {
	for (int i = gomoku._height - 1; i >= 0; i--) {
		out << setw(gomoku.longestStringLength) << i;
		for (int j = 0; j < gomoku._width; j++) {
			int gomokuIndex = j * gomoku.width_ + i; 
			out << setw(gomoku.longestStringLength) << gomoku.board[index];

			}
		}
		out << endl;
	}
out << setw(gomoku.longestStringLength) << " ";
	for (int i = 0; i < gomoku._width; i++) {
		out << setw(gomoku.longestStringLength) << i;
	}
	out << endl; 
	return out;
}

void Gomoku::print() {
	cout << *this; 
}

bool Gomoku::draw() {

	if (done()) {
		return false; 
	}
	else {
		for (int i = 0; i < gomoku.height_; i++) {
			for (int j = 0; j < gomoku.width_; j++) {
				int gameIndex = gomoku.width_ * i + j;
				if (board[gameIndex] == " ") {
					return false;
				}
			}
		}
		return true; 
	}

}

bool Gomoku::done() {
	for (int i = 0; i < gomoku.height_; i++) {
		for (int j = 0; j < gomoku.width_; j++) {
			int doneIndex = gomoku.width_ * i + j; 
			string pieceOnBoard = "";
			pieceOnBoard = board[i][j]; 

			//checking both diagonals 
			int piecesInARow = 1; 
			int i_value = i; 
			int j_value = j; 

			while (j_value > 0 && i_value < gomoku.height_) {
				//we are checking the diagonal going from right to left, so the i value increases, but the j value decreases
				i_value = i_value + 1; 
				j_value = j_value - 1; 
				
				//check if the piece matches the other and that it is not empty
				if (pieceOnBoard == board[i_value][j_value] && pieceOnBoard != " ") {
					piecesInARow++; 

					//check to see if the pieces in a row is equal to 5
					if (piecesInARow == 5) {
						return true; 
					}
				}
				else {
					//reset the pieces in a row back to 1
					piecesInARow = 1; 
				}
			}
			//reset the counter variables here so that we can check again on the the diagonal here where i decreases and j increases
			piecesInARow = 1; 
			i_value = i; 
			j_value = j;
			while (i_value > 0 && j_value < gomoku.height_) {
				i_value--; 
				j_value++; 

				if (pieceOnBoard == board[i_value][j_value] && pieceOnBoard != " ") {
					piecesInARow++;

					//check to see if the pieces in a row is equal to 5
					if (piecesInARow == 5) {
						
						return true;
					}
				}
				else {
					//reset the pieces in a row back to 1
					piecesInARow = 1;
				}


			}

			piecesInARow = 1;
			i_value = i;
			j_value = j;

			while (i_value > 0 && j_value > 0) {
				i_value--; 
				j_value--; 

				if (pieceOnBoard == board[i_value][j_value] && pieceOnBoard != " ") {
					piecesInARow++;

					//check to see if the pieces in a row is equal to 5
					if (piecesInARow == 5) {

						return true;
					}
				}
				else {
					//reset the pieces in a row back to 1
					piecesInARow = 1;
				}

			}
			piecesInARow = 1;
			i_value = i;
			j_value = j;
			while (i_value < gomoku.height_ && j_value < gomoku.height_) {
				i_value++; 
				j_value++; 
			
				if (pieceOnBoard == board[i_value][j_value] && pieceOnBoard != " ") {
					piecesInARow++;

					//check to see if the pieces in a row is equal to 5
					if (piecesInARow == 5) {

						return true;
					}
				}
				else {
					//reset the pieces in a row back to 1
					piecesInARow = 1;
				}

			}

			//going to the up vertically -- check for 5
			i_value = i; 
			piecesInARow = 1; 
			while (i_value < gomoku.height_) {
				i_value++; 
				if (pieceOnBoard == board[i_value][j] && pieceOnBoard != " ") {
					piecesInARow++;

					//check to see if the pieces in a row is equal to 5
					if (piecesInARow == 5) {

						return true;
					}
				}
				else {
					//reset the pieces in a row back to 1
					piecesInARow = 1;
				}


			}

			//going down vertically -- check for 5
			i_value = i; 
			piecesInARow = 1; 
			while (i_value > 0) {
				i_value--; 
				if (pieceOnBoard == board[i_value][j] && pieceOnBoard != " ") {
					piecesInARow++;

					//check to see if the pieces in a row is equal to 5
					if (piecesInARow == 5) {

						return true;
					}
				}
				else {
					//reset the pieces in a row back to 1
					piecesInARow = 1;
				}

			}

			//going to the right -- check for 5
			j_value = j; 
			piecesInARow = 1; 
			while (j_value < gomoku.width_) {
				j_value++; 
				if (pieceOnBoard == board[i][j_value] && pieceOnBoard != " ") {
					piecesInARow++;

					//check to see if the pieces in a row is equal to 5
					if (piecesInARow == 5) {

						return true;
					}
				}
				else {
					//reset the pieces in a row back to 1
					piecesInARow = 1;
				}

			}

			//going to the left--check for 5

			j_value = j; 
			piecesInArow = 1; 
			while (j_value > 0) {
				j_value--; 
				if (pieceOnBoard == board[i][j_value] && pieceOnBoard != " ") {
					piecesInARow++;

					//check to see if the pieces in a row is equal to 5
					if (piecesInARow == 5) {

						return true;
					}
				}
				else {
					//reset the pieces in a row back to 1
					piecesInARow = 1;
				}
				
			}
 


		}
	}

}


