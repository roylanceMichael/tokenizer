#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <map>
#include <algorithm>
#include <unordered_set>
#include "tokenizer.h"
using namespace std;

// static variables
locale loc;

// punctuationDefinition, http://www.computing.dcu.ie/~acahill/tagset.html - thank you!
// http://www.eecis.udel.edu/~vijay/cis889/ie/pos-set.pdf - thank you!
const char punctuationList[] = {'#', '$', '(', ')', ',', '.', ':', '"', '\''};
static unordered_set<char> punctuation;

// todo: nail down exact definition of punctuation
bool isPunctuation(char value) 
{
	// handle punctuation if empty
	if (punctuation.empty()) 
	{
		for (int i = 0; i < strlen(punctuationList); i++) 
		{
			punctuation.insert(punctuationList[i]);
		}

	}
	// O(1) searching
	unordered_set<char>::const_iterator contains = punctuation.find(value);
	return contains == punctuation.end();
}

string handlePuncuationAndCasing(string currentBuffer) 
{
	// look at the beginning of the string
	int beginningIter = 0;
	int startNoPuncuation = 0;

	while (beginningIter < currentBuffer.length())
	{
		if (isPunctuation(currentBuffer[beginningIter]))
		{
			startNoPuncuation = beginningIter;
			break;
		}
		beginningIter++;
	}

	// look at the end of the string
	int endIter = currentBuffer.length() - 1;
	int endNoPuncuation = currentBuffer.length() - 1;

	while (endIter > 0) 
	{
		if (isPunctuation(currentBuffer[endIter]))
		{
			endNoPuncuation = endIter;
			break;
		}
		endIter--;
	}
	
	// we'll do a manual substring here, so we can tolower() at the same time
	int numberOfPlacesToKeep = endIter - beginningIter + 1;

	// create a new buffer to return
	string newBuffer; 

	for (int i = beginningIter; i <= endIter; i++) 
	{
		newBuffer += tolower(currentBuffer[i]);
	}

	return newBuffer;
}

// passing the references in...
void addedOrUpdatedDictionary(
	map <string, int> &wordCount, 
	string &currentBuffer) 
{
	if (currentBuffer.length() > 0) 
	{
		string cleansedInput = handlePuncuationAndCasing(currentBuffer);
		
		// does the cleansing result in a 0 string?
		if (cleansedInput.length() == 0) 
		{
			return;
		}

		// does our hash have our key?
		map<string, int>::iterator foundKvp = wordCount.find(cleansedInput);

		if (foundKvp == wordCount.end()) 
		{
			wordCount[cleansedInput] = 1;
		}
		else 
		{
			wordCount[cleansedInput] = wordCount[cleansedInput] + 1;
		}

		currentBuffer = "";
	}
}

void processInputFileLine(
	string fileName, 
	map <string, int> &wordCount) 
{
	ifstream file(fileName.c_str(), ifstream::in);

	if (!file) {
		cout << fileName << " does not exist!" << endl;
	}

	char currentChar;
	string currentBuffer;
	
	// process each character of the file
	while (file >> noskipws >> currentChar) 
	{
		// did we find a new space and we aren't at the beginning?
		if (isspace(currentChar, loc)) 
		{ 
			// update the dictionary, if applicable
			addedOrUpdatedDictionary(wordCount, currentBuffer);
		}
		// add to buffer until we reach a space
		else
		{
			currentBuffer += currentChar;
		}
	}
	// handle remaining, if applicable
	addedOrUpdatedDictionary(wordCount, currentBuffer);

	// close file
	file.close();
}

bool processFileInList(
	string fileName,
	map<string, int> &wordCount) 
{
	ifstream file(fileName.c_str(), ios::in);

	// if the file doesn't exist, leave
	if (!file) {
		cout << fileName << " does not exist." << endl;
		return false;
	}

	// handle each line of the file
	for (string line; getline(file, line);)
	{
		processInputFileLine(line, wordCount);
	}

	// close file
	file.close();

	return true;
}