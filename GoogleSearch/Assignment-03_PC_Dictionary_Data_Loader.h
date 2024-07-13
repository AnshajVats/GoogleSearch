

#ifndef ASSIGNMENT_03_CODE_ASSIGNMENT_03_PC_DICTIONARY_DATA_LOADER_H
#define ASSIGNMENT_03_CODE_ASSIGNMENT_03_PC_DICTIONARY_DATA_LOADER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

struct Definition {
    string partOfSpeech;
    string meaning;
};

struct Dictionary {
    string word;
    vector<Definition> definitions;
};
void openFile(const string& filename, vector<string>& fileContent);
void separateContent(vector<string>& fileContent, vector<Dictionary>& dictionary);
void separateKeyWord(const string& line, string* word, string* definition);
void separateDefinition(const string& definition, Dictionary& dict);



#endif //ASSIGNMENT_03_CODE_ASSIGNMENT_03_PC_DICTIONARY_DATA_LOADER_H
