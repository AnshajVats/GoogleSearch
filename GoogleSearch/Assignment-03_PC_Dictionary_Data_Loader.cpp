#include "Assignment-03_PC_Dictionary_Data_Loader.h"

/**
 * Opens a file and reads its content into a vector of strings.
 *
 * @param filename    The name of the file to open.
 * @param fileContent Vector where each line of the file will be stored as a string.
 */
void openFile(const string &filename, vector<string> &fileContent) {
    ifstream file;
    string line;
    string currentFilename = filename; // Store the initial filename for error message

    while (true) {
        file.open(currentFilename, std::ios::in);
        if (file.is_open()) {
            cout << "! Opening data file... " << currentFilename << endl;
            while (getline(file, line)) {
                fileContent.push_back(line);
            }
            file.close();
            cout << "! Loading completed..." << endl;
            cout << "! Closing data file... " << currentFilename << endl;
            break; // Exit the loop once file is successfully loaded
        } else {
            cout << "<!>ERROR<!> ===> File could not be opened." << endl;
            cout << "<!>ERROR<!> ===> Provided file path: " << currentFilename << endl;
            cout << "<!>Enter the CORRECT data file path: ";

            getline(cin, currentFilename); // Get the corrected file path from user
        }
    }
}


/**
 * Separates content from the file into individual dictionary entries.
 *
 * @param fileContent Vector containing each line of the file as a string.
 * @param dictionary  Vector where each dictionary entry will be stored.
 */
void separateContent(vector<string> &fileContent, vector<Dictionary> &dictionary) {
    int definitionCount = 0;
    for (const auto &line: fileContent) {
        string word, definition;
        Dictionary dict;
        separateKeyWord(line, &word, &definition);
        dict.word = word;
        separateDefinition(definition, dict);
        dictionary.push_back(dict);
        definitionCount += static_cast<int>(dict.definitions.size());
    }
    cout << "====== DICTIONARY 340 C++ =====" << endl;
    cout << "------ Keywords:" << dictionary.size() << endl;
    cout << "------ Definitions: " << definitionCount << endl;
}


/**
 * Separates the keyword and its definitions from a line of input.
 *
 * @param line       The input string containing keyword and definitions.
 * @param word       Pointer to store the extracted keyword.
 * @param definition Pointer to store the extracted definitions.
 */
void separateKeyWord(const string &line, string *word, string *definition) {
    int index = 0;
    while (line[index] != '|') {
        *word += line[index];
        index++;
    }
    index++;
    while (index < line.length()) {
        *definition += line[index];
        index++;
    }
}

/**
 * Separates the part of speech and meaning from a definition string.
 *
 * @param definition The definition string to separate.
 * @param dict       The dictionary to store the separated definitions.
 */
void separateDefinition(const string &definition, Dictionary &dict) {
    Definition def;
    string partOfSpeech, meaning;
    int index = 0;
    while (index < definition.length()) {
        while (definition[index] != ' ') {
            partOfSpeech += definition[index];
            index++;
        }
        index += 5;
        while (definition[index] != '|' && index < definition.length()) {
            meaning += definition[index];
            index++;
        }
        index++;
        while (!meaning.empty() && meaning.back() != '.') {
            meaning.pop_back();
        }

        meaning.erase(meaning.begin(), find_if(meaning.begin(), meaning.end(), [](char ch) {
            return !isspace(ch);
        }));

        def.partOfSpeech = partOfSpeech;
        partOfSpeech.clear();
        def.meaning = meaning;
        meaning.clear();
        dict.definitions.push_back(def);
    }
}