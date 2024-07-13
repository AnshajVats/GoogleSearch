#include "Assignment-03_PC_Dictionary_Interaction.h"

/**
 * Checks if a keyword has definitions with a specific part of speech in the dictionary.
 *
 * @param keyword    The keyword to search for.
 * @param partOfSpeech The part of speech to check against.
 * @param dictionary Vector of dictionaries containing words and definitions.
 * @return True if the keyword has definitions with the specified part of speech, false otherwise.
 */
bool checkPartOfSpeech(const string &keyword, const string &partOfSpeech, vector<Dictionary> &dictionary) {
    for (const Dictionary &entry: dictionary) {
        if (entry.word == keyword) {
            for (const Definition &definition: entry.definitions) {
                if (definition.partOfSpeech == partOfSpeech) {
                    return true;
                }
            }
            if(!partOfSpeech.empty()) {
                vector <string> speech = {"noun", "verb", "adjective", "adverb", "pronoun", "preposition", "conjunction", "interjection"};
                int cnt = static_cast<int>(count(speech.begin(), speech.end(), partOfSpeech));
                if (cnt > 0) {
                    return true;
                }

            }
            return false;
        }

    }
    return false;
}


/**
 * Searches for definitions of a keyword in the dictionary, optionally filtering by distinctness and reversing the order.
 *
 * @param dictionary Vector of dictionaries containing words and definitions.
 * @param keyword    The keyword to search for.
 * @param distinct   Flag indicating whether to filter distinct definitions.
 * @param isReverse  Flag indicating whether to reverse the order of definitions.
 * @param partOfSpeech Optional part of speech filter.
 */
void search(vector<Dictionary> &dictionary, const string &keyword, bool distinct, bool isReverse,
            const string &partOfSpeech) {
    vector<Definition> def = searchDefinition(dictionary, keyword, partOfSpeech);
    if (!def.empty()) {
        sortDefinitionsByPartOfSpeech(def);
        if (distinct) {
            getDistinctDefinitions(def);

        }
        if (isReverse) {
            reverse(def.begin(), def.end());
        }
        if (def.empty()) {
            printNotFoundMessage();
            return;
        }
        printEntriesOutput(def, keyword);
    } else {
        printNotFoundMessage();
    }
}


/**
 * Converts a string to lowercase.
 *
 * @param str The string to convert to lowercase.
 */
void toLowerCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

/**
 * Sorts definitions by part of speech and meaning in a case-insensitive manner.
 *
 * @param definitions Vector of definitions to sort.
 */
void sortDefinitionsByPartOfSpeech(vector<Definition> &definitions) {
    bool swapped;
    for (size_t i = 0; i < definitions.size() - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < definitions.size() - i - 1; j++) {
            // Create temporary strings for case-insensitive comparison
            string partOfSpeechA = definitions[j].partOfSpeech;
            string partOfSpeechB = definitions[j + 1].partOfSpeech;
            string meaningA = definitions[j].meaning;
            string meaningB = definitions[j + 1].meaning;

            toLowerCase(partOfSpeechA);
            toLowerCase(partOfSpeechB);
            toLowerCase(meaningA);
            toLowerCase(meaningB);

            // Compare and swap if needed
            if ((partOfSpeechA > partOfSpeechB) ||
                (partOfSpeechA == partOfSpeechB && meaningA > meaningB)) {
                swap(definitions[j], definitions[j + 1]);
                swapped = true;
            }
        }
        // If no elements were swapped, the list is sorted
        if (!swapped) break;
    }
}


/**
 * Removes duplicate definitions from a vector of definitions.
 *
 * @param def Vector of definitions to remove duplicates from.
 */
void getDistinctDefinitions(vector<Definition> &def) {
    for (int i = 0; i < def.size(); i++) {
        for (int j = i + 1; j < def.size(); j++) {
            toLowerCase(def[i].meaning);
            toLowerCase(def[j].meaning);
            if (def[i].meaning == def[j].meaning && def[i].partOfSpeech == def[j].partOfSpeech) {
                def.erase(def.begin() + j);
                j--;
            }
        }
    }
}

/**
 * Searches for definitions of a keyword in the dictionary.
 *
 * @param dictionary Vector of dictionaries containing words and definitions.
 * @param keyword    The keyword to search for.
 * @param partOfSpeech Optional part of speech filter.
 * @return Vector of definitions of the keyword.
 */
vector<Definition> searchDefinition(vector<Dictionary> &dictionary, const string &keyword, const string &partOfSpeech) {
    vector<Definition> definitions;
    for (const Dictionary &entry: dictionary) {
        if (entry.word == keyword) {
            for (const Definition &definition: entry.definitions) {
                if (partOfSpeech.empty() || definition.partOfSpeech == partOfSpeech) {
                    definitions.push_back(definition);
                }
            }
            return definitions;
        }
    }
    return definitions;
}
