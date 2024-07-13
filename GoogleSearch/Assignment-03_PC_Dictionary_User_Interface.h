//
// Created by Anshaj Vats on 7/5/24.
//

#ifndef ASSIGNMENT_03_CODE_ASSIGNMENT_03_PC_DICTIONARY_USER_INTERFACE_H
#define ASSIGNMENT_03_CODE_ASSIGNMENT_03_PC_DICTIONARY_USER_INTERFACE_H
#include "Assignment-03_PC_Dictionary_Print_Output.h"
#include  "Assignment-03_PC_Dictionary_Interaction.h"

void userInterface(vector<Dictionary>& dictionary);
void takeUserInput(vector<string>& parts, vector<Dictionary>& dictionary, bool* distinct, bool* reverse, string* partOfSpeech);
vector<string> split(const string &input,const string &delimiter);

#endif //ASSIGNMENT_03_CODE_ASSIGNMENT_03_PC_DICTIONARY_USER_INTERFACE_H
