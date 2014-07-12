#include <map>
// removes puncuation from the beginning and end of a string and force lower
std::string handlePuncuationAndCasing(std::string currentBuffer);

// processes the initial input file
void processInputFileLine(std::string fileName, std::map<std::string, int> &wordCount);

// processes all the filenames in a file
void processFileInList(std::string fileName, std::map<std::string, int> &wordCount);