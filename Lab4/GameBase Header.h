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
	friend ostream& operator<<(ostream& out, const Game& f);
public:
	Game();
	bool done();
	bool draw();
	error prompt(unsigned int&, unsigned int&);
	error turn();
	result play();
	error auto_player(); //part of extra credit
	bool computer; //part of extra credit

private:
	Piece board[5][5];
	int _width;
	int _height;
	int turns;
	Piece winner;
};




ostream& operator<<(ostream& out, const Game& f);
