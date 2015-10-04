#pragma once
#include <iostream>
#include <cstring>

/** 13.1 Write a method to print the last K lines of an input file using C++. **/

using namespace std;

class File
{
public:
	File() {}
	bool good() {}
};

void getLine(File &file, string &lines)
{
}

void printLastKLines(int k)
{
	File file;
	string lines[k];
	int linesCount = 0;
	while (file.good()) {
		getLine(file, lines[linesCount % k]); // read file line by line
		++linesCount;
	}

	// if less than K lines were read, print them all
	int start = 0;
	int count = 0;
	if (linesCount < k) {
		start = 0;
		count = linesCount;
	} else {
		start = linesCount % k;
		count = k;
	}
	for (int i = 0; i < count; ++i) {
		cout << lines[(start + i) % k] << endl;
	}
}
