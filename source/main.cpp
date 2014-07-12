#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <typeinfo>
#include "tokenizer.h"
using namespace std;

int main(int argc, char* argv[])
{
	// do we have two files?
	if (argc < 3) {
		cout << "expecting two files, one for input and one for output. received " << argc - 1 << endl;
		return -1;
	}

	cout << "processing input " << argv[1] << endl;
	processFileInList(argv[1]);

	return 0;
}

