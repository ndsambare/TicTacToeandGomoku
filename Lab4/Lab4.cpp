// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Main Header.h"
#include "TicTacToe.h"
#include <memory>

class Game;
class TicTacToe;
class Gomoku;

//Main method that calls the TicTacToe game to be played
int main(int argc, char* argv[])
{
	if (argc != expCommands) {
		return usageMessage(argv[progname]);
	}
	Game* game = Game::create_game(argc, argv);
	if (game == nullptr) {
		return usageMessage(argv[progname]);
	}
	shared_ptr<Game> spointer(game);
	result res = game->play();
	return res;
}

//Usage Message
//Outputs a helpful message if an incorrect input is typed.
int usageMessage(char* cString) {
	cout << "Usage: " << cString << " " << "<input_file_type>" << endl;
	cout << "The <input_file_type> for this file is 'TicTacToe' or 'Gomoku'" << endl;
	return badInput;
}