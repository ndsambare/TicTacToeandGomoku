#pragma once
#include "GameBase Header.h"
#include "Main Header.h"

//We have to declare the second constructor and also probably add protected variables


class Gomoku : public Game {
	friend ostream& operator<<(ostream& out, const Gomoku& f);

public: 
	Gomoku(); 
	//apparently there's also supposed to be a Gomoku constructor that takes in parameters
	virtual bool draw(); 
	virtual bool done();
	virtual bool done(vector<string>& copy);
	virtual error turn();
	virtual void print();
protected: 
	int piecesInARow; 
};

ostream& operator<<(ostream&, const Gomoku&);
