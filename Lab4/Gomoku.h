#pragma once
#include "GameBase Header.h"
#include "Main Header.h"

//We have to declare the second constructor and also probably add protected variables

enum GomokuDimensions {
	width = 19, height = 19
};

class Gomoku : public Game {
	friend ostream& operator<<(ostream& out, const TicTacToe& f);

public: 
	Gomoku(); 
	//apparently there's also supposed to be a Gomoku constructor that takes in parameters
	virtual bool draw(); 
	virtual bool done(); 
	virtual int turn();
	virtual void print();
protected: 
	int piecesInARow; 

};