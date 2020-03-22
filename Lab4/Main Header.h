#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

enum arg {
	progname, filename, expCommands, expCommands2
};

int usageMessage(char*);
