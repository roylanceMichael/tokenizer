#include <iostream>
#include <map>
#include "transformMap.h"
#include "tokenizer.h"
using namespace std;

int fullStringReturnedWhenFullStringGiven()
{
	string testStr = "helloworld";

	string expected = "helloworld";

	string actual = handlePuncuationAndCasing(testStr);

	if (actual == expected) {
		return 1;
	}

	cout << "failed fullStringReturnedWhenFullStringGiven expected, actual: " << actual << expected << endl;
	
	return 0;
}

int puncuationRemovedFromBeginning()
{
	string testStr = ".helloworld";

	string expected = "helloworld";

	string actual = handlePuncuationAndCasing(testStr);

	if (actual == expected) {
		return 1;
	}

	cout << "failed puncuationRemovedFromBeginning expected, actual: " << actual << expected << endl;
	
	return 0;
}

int puncuationRemovedFromEnd()
{
	string testStr = "helloWorld.";

	string expected = "helloworld";

	string actual = handlePuncuationAndCasing(testStr);

	if (actual == expected) {
		return 1;
	}

	cout << "failed puncuationRemovedFromEnd expected, actual: " << actual << expected << endl;
	
	return 0;
}

int puncuationKeptInMiddle()
{
	string testStr = "hello.world";

	string expected = "hello.world";

	string actual = handlePuncuationAndCasing(testStr);

	if (actual == expected) {
		return 1;
	}

	cout << "failed puncuationKeptInMiddle expected, actual: " << actual << expected << endl;
	
	return 0;
}

int puncuationRemovedFromSidesButKeptInMiddle()
{
	string testStr = "!hello.world@";

	string expected = "hello.world";

	string actual = handlePuncuationAndCasing(testStr);

	if (actual == expected) {
		return 1;
	}

	cout << "failed puncuationRemovedFromSidesButKeptInMiddle expected, actual: " << actual << expected << endl;
	
	return 0;
}

int charactersAreForcedIntoLower()
{
	string testStr = "HELLOWORLD";

	string expected = "helloworld";

	string actual = handlePuncuationAndCasing(testStr);

	if (actual == expected) {
		return 1;
	}

	cout << "failed charactersAreForcedIntoLower expected, actual: " << actual << expected << endl;
	
	return 0;
}

int returnsFalseIfMainFileDoesNotExist()
{
	int expected = 0;
	map <string, int> result;
	processFileInList("erroneousFileName.txt", result);

	if (result.size() == expected) {
		return 1;
	}

	cout << "failed returnsFalseIfMainFileDoesNotExist" << endl;
	
	return 0;
}

int returnsMasterListWhenInputFileEntered()
{
	int expected = 13;
	map <string, int> result; 
	processFileInList("docs/testInput.txt", result);

	if (result.size() == expected) {
		return 1;
	}

	cout << "failed returnsMasterListWhenInputFileEntered " << result.size() << endl;

	for (map<string, int>::iterator it=result.begin(); it!=result.end(); ++it)
	{
    	cout << it->first << " => " << it->second << '\n';
    }
	
	return 0;
}

int returnsCorrectDictionaryFromSimpleTestDocument()
{
	int expected = 8;
	map <string, int> result;
	processInputFileLine("docs/simpleTest.txt", result);

	if (result.size() == expected) {
		return 1;
	}

	for (map<string, int>::iterator it=result.begin(); it!=result.end(); ++it)
	{
    	cout << it->first << " => " << it->second << '\n';
    }

	cout << "failed returnsCorrectDictionaryFromSimpleTestDocument: " << result.size() << endl;
	
	return 0;
}

int transformsDictionaryCorrectly()
{
	int expected = 8;
	map <string, int> result;
	processInputFileLine("docs/simpleTest.txt", result);
	transformMapToFile(result, "testFile.txt");

	if (result.size() == expected) {
		return 1;
	}
	
	return 0;
}

int main()
{
	int passedTests;

	passedTests += fullStringReturnedWhenFullStringGiven();
	passedTests += puncuationRemovedFromBeginning();
	passedTests += puncuationRemovedFromEnd();
	passedTests += puncuationKeptInMiddle();
	passedTests += puncuationRemovedFromSidesButKeptInMiddle();
	passedTests += charactersAreForcedIntoLower();
	passedTests += returnsFalseIfMainFileDoesNotExist();
	passedTests += returnsCorrectDictionaryFromSimpleTestDocument();
	passedTests += returnsMasterListWhenInputFileEntered();
	passedTests += transformsDictionaryCorrectly();

	cout << "passed " << passedTests << " tests" << endl;
}