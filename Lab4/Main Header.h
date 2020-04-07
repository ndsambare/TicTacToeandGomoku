#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

//different input types
enum arg {
	progname, filename, expCommands
};

int usageMessage(char*);