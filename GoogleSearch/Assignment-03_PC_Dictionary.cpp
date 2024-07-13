#include "Assignment-03_PC_Dictionary_User_Interface.h"


void loadContent(vector<Dictionary> &dictionary);

void getfilename(string *filename);

/**
 * Main function to initialize the dictionary and start the user interface.
 */
int main() {
    string line;
    vector<Dictionary> dictionary;
    loadContent(dictionary);
    userInterface(dictionary);
    return 0;
}

/**
 * Loads content from a data file into the dictionary vector.
 *
 * @param dictionary Reference to the vector where dictionary data will be stored.
 */
void loadContent(vector<Dictionary> &dictionary) {
    vector<string> fileContent;
    string filename;
    getfilename(&filename);
    openFile(filename, fileContent);
    separateContent(fileContent, dictionary);
}

/**
 * Gets the filename for the data file.
 *
 * @param filename Pointer to a string where the filename will be stored.
 */
void getfilename(string *filename) {
    cout << "! Opening data file... C:\\Users\\MickeyMouse\\AbsolutePath\\DB\\Data.CS.SFSU.txt" << endl;
    *filename = "./data.cs.sfsu.txt"; // relative path to the file
}
