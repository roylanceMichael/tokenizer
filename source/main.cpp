#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <typeinfo>
#include "tokenizer.h"
#include "transformMap.h"
using namespace std;

int main(int argc, char* argv[])
{
	// do we have two files?
	if (argc < 3) {
		cout << "expecting two files, one for input and one for output. received " << argc - 1 << endl;
		return -1;
	}

	cout << "processing input " << argv[1] << endl;
	string mainFileName(argv[1]);
	string outputFile(argv[2]);
	map <string, int> wordCount;

	bool processResult = processFileInList(mainFileName, wordCount);

	if (processResult) {
		transformMapToFile(wordCount, outputFile);
		return 0;
	}

	return 1;
}

