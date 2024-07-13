#include "Assignment-03_PC_Dictionary_Print_Output.h"

/**
 * Prints a message to the user when the input is incorrect.
 */
void wrongInput() {
    cout << " |" << endl;
    cout << "  PARAMETER HOW-TO, please enter:" << endl;
    cout << "  1. A search key -then 2. An optional part of speech -then\n"
         << "  3. An optional 'distinct' -then 4. An optional 'reverse'" << endl;
    cout << " |" << endl;
}

/**
 * Checks if a keyword has definitions with a specific part of speech in the dictionary.
 *
 * @param keyword    The keyword to search for.
 * @param partOfSpeech The part of speech to check against.
 * @param dictionary Vector of dictionaries containing words and definitions.
 * @return True if the keyword has definitions with the specified part of speech, false otherwise.
 */
bool containsNumbers(const string &keyword) {
    return any_of(keyword.begin(), keyword.end(), ::isdigit) &&
           any_of(keyword.begin(), keyword.end(), ::isalpha);
}

/**
 * Capitalizes the first letter of a keyword.
 *
 * @param keyword The keyword to capitalize.
 */
void capitalizeKeyword(string &keyword) {
    if (keyword.empty()) return;

    if (containsNumbers(keyword)) {
        transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
    } else {
        keyword[0] = static_cast<char>(toupper(keyword[0]));
    }
}

/**
 * Prints the definitions of a keyword to the console.
 *
 * @param resultEntries The definitions to print.
 * @param keyword       The keyword to print.
 */
void printEntriesOutput(const vector<Definition> &resultEntries, const string &keyword) {
    string capitalizedKeyword = keyword;
    capitalizeKeyword(capitalizedKeyword);

    for (const Definition &entry: resultEntries) {
        string capitalizedMeaning = entry.meaning;
        if (!capitalizedMeaning.empty()) {
            capitalizedMeaning[0] = static_cast<char>(toupper(static_cast<unsigned char>(capitalizedMeaning[0])));
        }

        cout << "    " << capitalizedKeyword << " [" << entry.partOfSpeech << "] : " << capitalizedMeaning << endl;
    }
}

/**
 * Prints a message to the user when the keyword is not found in the dictionary.
 */
void printNotFoundMessage() {
    cout << "   <NOT FOUND> To be considered for the next release. Thank you." << endl;
    cout << "  |" << endl;
    cout << "  |" << endl;
    cout << "   PARAMETER HOW-TO, please enter:" << endl;
    cout << "   1. A search key -then 2. An optional part of speech -then\n"
         << "   3. An optional 'distinct' -then 4. An optional 'reverse'" << endl;
}

/**
 * Prints a message to the user when the input is invalid.
 *
 * @param input The invalid input.
 * @param index The index of the invalid input.
 */
void printInvalidInput(const string &input, int index) {
    vector<string> validInputs = {"key", "part of speech", "distinct", "reverse"};
    cout << "  |" << endl;
    for (int i = index; i < validInputs.size(); i++) {
        cout << "   <The entered " << index + 1 << (index == 2 ? "rd" : "th")
             << " parameter '" << input << "' is NOT '" << validInputs[i] << "'.>" << endl;
    }
    cout << "   <The entered " << index + 1 << (index == 2 ? "rd" : "th")
         << " parameter '" << input << "' was disregarded.>" << endl;

    switch (index) {
        case 1:
            cout << "   <The " << index + 1 << "nd parameter should be a part of speech or 'distinct' or 'reverse'.>"
                 << endl;
            break;
        case 2:
            cout << "   <The " << index + 1 << "rd parameter should be a 'distinct' or 'reverse'.>" << endl;
            break;
        case 3:
            cout << "   <The " << index + 1 << "th parameter should be a 'reverse'.>" << endl;
            break;
    }
    cout << "  |" << endl;
}
