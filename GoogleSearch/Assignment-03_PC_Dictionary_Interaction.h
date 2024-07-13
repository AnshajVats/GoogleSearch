//
// Created by Anshaj Vats on 7/5/24.
//

#ifndef ASSIGNMENT_03_CODE_ASSIGNMENT_03_PC_DICTIONARY_INTERACTION_H
#define ASSIGNMENT_03_CODE_ASSIGNMENT_03_PC_DICTIONARY_INTERACTION_H
#include <set>
#include "Assignment-03_PC_Dictionary_Data_Loader.h"
#include "Assignment-03_PC_Dictionary_Print_Output.h"


bool checkPartOfSpeech(const string& keyword, const string& partOfSpeech, vector<Dictionary>& dictionary);
void search(vector<Dictionary>& dictionary, const string& keyword, bool distinct, bool isReverse, const string& partOfSpeech);
vector <Definition> searchDefinition(vector<Dictionary>& dictionary,const string& keyword, const string& partOfSpeech);
void sortDefinitionsByPartOfSpeech(vector<Definition>& definitions);
void getDistinctDefinitions(vector<Definition>& definitions);
void toLowerCase(string& str);

#endif //ASSIGNMENT_03_CODE_ASSIGNMENT_03_PC_DICTIONARY_INTERACTION_H
