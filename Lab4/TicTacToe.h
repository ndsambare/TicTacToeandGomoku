#pragma once

#include "GameBase Header.h"

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
	string winner;
};

ostream& operator<<(ostream&, const TicTacToe&);
