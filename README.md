tokenizer
=========
this application does the following:
---------
*	opens a file as the first parameter on the command-line
	* this file contains multiple file names
		* if this parameter doesn't exist, the program will exit out with a note to the user to include the parameter in
		* if this file doesn't exist, the program will exit out with a note to the user about how it does not exist
	* processes each file in the file list
*	if the file in the file list does not exist, the file will be skipped with a note to the user
*	the file is separated by whitespace (c++ isspace) with trailing and leading punctuation stripped. finally, the characters are forced to be lower cased.
	* punctuation is defined as by Penn Treebank
		* http://www.eecis.udel.edu/~vijay/cis889/ie/pos-set.pdf
		* http://www.computing.dcu.ie/~acahill/tagset.html
		* function defined to easily change definition of punctuation, if needed
*	the tokenized words are then grouped together, sorted by frequency, and print out into a file specified by the second parameter

tests can be examined at source/tests.cpp. they can be executed by running ./runTests.sh.

usage: 
=========
./run.sh <inputFileWithMultipleFileNames> <outputFileName>

this will read in each file in the file list and process a wordcount globally and create an output file with the results.

./run.sh docs/fileNameList outputFile.txt 

will create a file that looks like:

the	4572

of	2310

to	2036

a	2016

in	1864

and	1608

for	896

that	816

said	622

is	594

it	526

on	508

mr	446
...

This was tested with g++ 4.8.2 (Ubuntu) and 5.1 (Apple)