#pragma once

#include "GameBase Header.h"

class TicTacToe : public Game {
	friend ostream& operator<<(ostream& out, const TicTacToe& f);

public:
	TicTacToe();
	virtual bool done();
	virtual bool draw();
	virtual error turn();
	virtual void print() {
		cout << *this << endl;
	}
	virtual result play();
	Piece winner;
};

ostream& operator<<(ostream& out, const TicTacToe& f);
