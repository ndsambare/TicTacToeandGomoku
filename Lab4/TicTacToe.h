#pragma once

#include "GameBase Header.h"

//derived class of the base class Game, defines functions that allow the game TicTacToe to be played
class TicTacToe : public Game {
public:
	friend ostream& operator<<(ostream& out, const TicTacToe& f);
	TicTacToe();
	virtual bool done();
	virtual bool draw();
	virtual error turn();
	virtual void print() {
		cout << *this << endl;
	}
};

ostream& operator<<(ostream&, const TicTacToe&);
