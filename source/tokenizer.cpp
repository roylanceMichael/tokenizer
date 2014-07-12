#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <locale>
#include "tokenizer.h"
using namespace std;

// static variables
locale loc;

string removePuncuation(string currentBuffer) 
{
	int beginningIter = 0;
	int startNoPuncuation = 0;

	while (beginningIter < currentBuffer.length())
	{
		if (isalnum(currentBuffer[beginningIter]))
		{
			startNoPuncuation = beginningIter;
			break;
		}
		beginningIter++;
	}

	int endIter = currentBuffer.length() - 1;
	int endNoPuncuation = currentBuffer.length() - 1;

	while (endIter > 0) 
	{
		if (isalnum(currentBuffer[endIter]))
		{
			endNoPuncuation = endIter;
			break;
		}
		endIter--;
	}
	
	int numberOfPlacesToKeep = endIter - beginningIter + 1;
	string newBuffer = currentBuffer.substr(beginningIter, numberOfPlacesToKeep);
	return newBuffer;
}

bool processInputFileLine(char* fileName) 
{
	unordered_map <string, int> wordCount;

	ifstream file(fileName, ifstream::in);

	char currentChar;
	bool previousCharWasSpace = false;
	string currentBuffer;
	
	cout << std::tolower(currentBuffer[0], loc) << endl;
	while (file >> noskipws >> currentChar) {
		if (currentChar == ' ' && currentBuffer.length() > 0) { 
			removePuncuation(currentBuffer);
			currentBuffer = "";
		}
		else if (currentChar != ' ') {
			currentBuffer += currentChar;
		}
	}

	// close file
	file.close();
	
	return true;
}

bool processFileInList(char fileName[]) 
{
	ifstream file;
	file.open(fileName, ios::in);

	char inputFileName[300];
	file >> inputFileName;
	processInputFileLine(inputFileName);

	while (file) {
		file >> inputFileName;
		processInputFileLine(inputFileName);
	}

	// close file
	file.close();

	return true;
}