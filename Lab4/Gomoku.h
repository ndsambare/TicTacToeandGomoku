#pragma once
#include "GameBase Header.h"
#include "Main Header.h"


//derived class of the base class Game, defines functions that allow the game Gomoku to be played
class Gomoku : public Game {
public: 
	friend ostream& operator<<(ostream& out, const Gomoku& f);
	Gomoku(); 
	virtual bool draw(); 
	virtual bool done();
	virtual bool done(vector<string>& copy);
	virtual error turn();
	virtual void print();
protected: 
	int piecesInARow; 
};

ostream& operator<<(ostream&, const Gomoku&);
