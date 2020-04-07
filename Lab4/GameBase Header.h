#pragma once
#include "Main Header.h"

//sets the max index for TicTicToe
enum indices {
	maxTicTacToe = 3
};

//possible error messages
enum error {
	success, failure, quit, badInput
};

//different results possible at the end of every turn
enum result {
	winner, draw, quitEnd
};

//values in a row for Gomoku
enum values {
	inARow = 5
};

//base class, contains functions and member variables applicable to multiple games
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
	vector<string> board;
	int _width;
	int _height;
	int longestStringLength;
	int turns; 
	bool isGomoku;
	string winner;
};




