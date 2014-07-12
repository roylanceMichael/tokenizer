#include <iostream>
#include "tokenizer.h"
using namespace std;

int fullStringReturnedWhenFullStringGiven()
{
	string testStr = "helloWorld";

	string expected = "helloWorld";

	string actual = removePuncuation(testStr);

	if (actual == expected) {
		return 1;
	}

	cout << "failed fullStringReturnedWhenFullStringGiven expected, actual: " << actual << expected << endl;
	
	return 0;
}

int puncuationRemovedFromBeginning()
{
	string testStr = ".helloWorld";

	string expected = "helloWorld";

	string actual = removePuncuation(testStr);

	if (actual == expected) {
		return 1;
	}

	cout << "failed puncuationRemovedFromBeginning expected, actual: " << actual << expected << endl;
	
	return 0;
}

int puncuationRemovedFromEnd()
{
	string testStr = "helloWorld.";

	string expected = "helloWorld";

	string actual = removePuncuation(testStr);

	if (actual == expected) {
		return 1;
	}

	cout << "failed puncuationRemovedFromEnd expected, actual: " << actual << expected << endl;
	
	return 0;
}

int puncuationKeptInMiddle()
{
	string testStr = "hello.World";

	string expected = "hello.World";

	string actual = removePuncuation(testStr);

	if (actual == expected) {
		return 1;
	}

	cout << "failed puncuationKeptInMiddle expected, actual: " << actual << expected << endl;
	
	return 0;
}

int puncuationRemovedFromSidesButKeptInMiddle()
{
	string testStr = "!hello.World@";

	string expected = "hello.World";

	string actual = removePuncuation(testStr);

	if (actual == expected) {
		return 1;
	}

	cout << "failed puncuationRemovedFromSidesButKeptInMiddle expected, actual: " << actual << expected << endl;
	
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

	cout << "passed " << passedTests << " tests" << endl;
}

