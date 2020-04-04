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
	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	error prompt(unsigned int&, unsigned int&);
	virtual error turn() = 0;
	result play();
	error auto_player(); //part of extra credit
	bool computer; //part of extra credit
	int turns;
protected:
	int _width;
	int _height;
	Piece board[20][20];
	int longestStringLength;
};

class TicTacToe: public Game {

public:
	virtual bool done();
	virtual bool draw();
	virtual error turn();
	virtual void print() {
		cout << *this << endl;
	}
private:
	
	Piece winner;
};




ostream& operator<<(ostream& out, const Game& f);
