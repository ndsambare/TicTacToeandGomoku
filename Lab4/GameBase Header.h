#pragma once
#include "Main Header.h"

enum Piece {
	x, o, empty
};

struct game_piece {
	Piece display;
	int xcoord;
	int ycoord;
};

enum error {
	success, failure, quit
};

enum result {
	winner, draw, quitEnd
};

class Game {

public:
	result play();
	static Game* create_game(int, char*[]);
protected:
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual error turn() = 0;
	virtual error prompt(unsigned int&, unsigned int&);
	string board[5][5];
	//we have to fix the game board and once we fix that we have to make sure the rest of our code is compatible with the working game board
	int _width;
	int _height;
	int longestStringLength;
	int turns;
};




