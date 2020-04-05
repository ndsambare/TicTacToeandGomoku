#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

enum arg {
	progname, filename, expCommands, expCommands2
};

int usageMessage(char*);

enum values {
	inARow = 5
};