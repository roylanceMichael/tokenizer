#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <map>
#include <vector>
#include <utility>
#include "tokenizer.h"
using namespace std;

bool comparison (pair<string,int> i, pair<string,int> j) 
{ 
	return (i.second > j.second); 
}

void transformMapToFile(
	map<string, int> &wordCount,
	string fileName) 
{
	vector<pair<string,int> > items;

	for (map<string, int>::iterator it=wordCount.begin(); it!=wordCount.end(); ++it)
	{
    	items.push_back(make_pair(it->first, it->second));
    }

    sort(items.begin(), items.end(), comparison);

    ofstream outputFile;
	outputFile.open(fileName);

    for (vector<pair<string,int> >::iterator it=items.begin(); it!=items.end(); ++it)
	{
    	outputFile << it->first << '\t' << it->second << endl;
    }
}