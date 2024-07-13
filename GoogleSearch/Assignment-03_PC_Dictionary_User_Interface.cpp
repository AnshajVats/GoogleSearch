#include "Assignment-03_PC_Dictionary_User_Interface.h"

/**
 * Implements the user interface for interacting with the dictionary, handling user input, and displaying search results.
 *
 * @param dictionary Vector of dictionaries containing words and definitions.
 */
void userInterface(vector<Dictionary>& dictionary){
    string inputFromUser;
    vector<string> parts;
    bool distinct = false;
    bool reverse = false;
    string partOfSpeech;
    int i = 1;
    while (true) {
        cout << "Search [" << i << "]: ";
        getline(cin, inputFromUser);

        if (inputFromUser.empty() || all_of(inputFromUser.begin(), inputFromUser.end(), [](char c){ return isspace(c); })) {
            wrongInput();
            continue;
        }
        // Convert inputFromUser to lowercase for comparison
        transform(inputFromUser.begin(), inputFromUser.end(), inputFromUser.begin(), ::tolower);

        // Splitting input into parts
        parts = split(inputFromUser, " ");
        if (parts.size() > 4) {
            wrongInput();
            continue;
        }


        if (inputFromUser == "!q") {
            cout << "\n-----THANK YOU-----" << endl;
            return; // Exit the program
        } else if (inputFromUser == "!help" || inputFromUser.empty()) {
            wrongInput();
        } else {
            takeUserInput(parts, dictionary, &distinct, &reverse, &partOfSpeech);
            cout << "  |" << endl;
            search(dictionary, parts[0], distinct, reverse, partOfSpeech);
            distinct = false;
            reverse = false;
            partOfSpeech.clear();
            cout << "  |" << endl;
        }
        i++;
    }
}

/**
 * This function is used to split the input from the user
 * @param input
 * @param delimiter
 * @return
 */
vector<string> split(const string &input,const string &delimiter) {
    vector<string> tokens;
    int start, end = static_cast<int>(-1*delimiter.size());
    do {
        start = static_cast<int>(end + delimiter.size());
        end = static_cast<int>(input.find(delimiter, start));
        string token = input.substr(start, end - start);
        if (!token.empty()) {
            tokens.push_back(token);
        }
    } while (end != -1);
    return tokens;
}

/**
 * This function is used to check if the part of speech entered by the user is valid
 * @param keyword
 * @param partOfSpeech
 * @param dictionary
 * @return
 */
void takeUserInput(vector<string>& parts, vector<Dictionary>& dictionary, bool* distinct, bool* reverse, string* partOfSpeech){
    for (int i = 1; i < parts.size(); ++i) {
        if (parts[i] == "distinct" && i != 3) {
            *distinct = true;
        }   else if (parts[i] == "reverse") {
            *reverse = true;
        }   else if (checkPartOfSpeech(parts[0], parts[i], dictionary)) {
            *partOfSpeech = parts[i];
        }  else {
            printInvalidInput(parts[i], i);
        }
    }
}