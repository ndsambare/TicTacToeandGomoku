// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Main Header.h"
#include "GameBase Header.h"
#include "TicTacToe.h"
#include <memory>

//Main method that calls the TicTacToe game to be played
int main(int argc, char* argv[])
{
	Game* game = Game::create_game(argc, argv);
	if (game == 0) {
		return usageMessage(argv[progname]);
	}
	
	game.play();
	delete game;
	
	return usageMessage(argv[progname]);
}

//Usage Message
//Outputs a helpful message if an incorrect input is typed.
int usageMessage(char* cString) {
	cout << "Usage: " << cString << " " << "<input_file_type>" << endl;
	cout << "The <input_file_type> for this file is 'TicTacToe'" << endl;
	return failure;
}