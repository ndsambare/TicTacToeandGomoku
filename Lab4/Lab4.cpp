// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Main Header.h"
#include "GameBase Header.h"

//Main method that calls the TicTacToe game to be played
int main(int argc, char* argv[])
{
	string check = argv[filename];
	if (argc == expCommands || argc == expCommands2) {
		if (check == "TicTacToe") {
			TicTacToe game = TicTacToe();
			if (argc == expCommands) {
				game.computer = false;
			}
			if (argc == expCommands2) {
				string autocheck = argv[expCommands];
				if (autocheck == "auto_player") {
					game.computer = true;
				}
				else {
					return usageMessage(argv[progname]);
				}
			}
			result res = game.play();
			return res;
		}
	}
	return usageMessage(argv[progname]);
}

//Usage Message
//Outputs a helpful message if an incorrect input is typed.
int usageMessage(char* cString) {
	cout << "Usage: " << cString << " " << "<input_file_type>" << endl;
	cout << "The <input_file_type> for this file is 'TicTacToe'" << endl;
	return failure;
}