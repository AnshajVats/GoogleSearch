//
// Created by Anshaj Vats on 7/5/24.
//

#ifndef ASSIGNMENT_03_CODE_ASSIGNMENT_03_PC_DICTIONARY_PRINT_OUTPUT_H
#define ASSIGNMENT_03_CODE_ASSIGNMENT_03_PC_DICTIONARY_PRINT_OUTPUT_H
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Assignment-03_PC_Dictionary_Data_Loader.h"
void wrongInput();
void printEntriesOutput(const vector<Definition>& resultEntries, const string& keyword);
void printNotFoundMessage();
void printInvalidInput(const string& input, int index);
void capitalizeKeyword(string& keyword);
bool containsNumbers(const string& keyword);
#endif //ASSIGNMENT_03_CODE_ASSIGNMENT_03_PC_DICTIONARY_PRINT_OUTPUT_H
