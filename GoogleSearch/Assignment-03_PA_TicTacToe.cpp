#include <iostream>
using namespace std;

bool isWon(char, char[][3]);
bool isDraw(char[][3]);
void displayBoard(char[][3]);
void makeAMove(char[][3], char);
void takeInput(int*, int*, char, char[][3]);
bool checkInput(int, int, char[][3]);
bool checkBoard(char, char[][3]);


int main() {
    //
    //	PLEASE DO NOT CHANGE function main
    //
    char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
    displayBoard(board);
    while (true) {

        // The first player makes a move
        makeAMove(board, 'X');
        displayBoard(board);

        if (isWon('X', board)) {
            cout << "X player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }

        // The second player makes a move
        makeAMove(board, 'O');
        displayBoard(board);

        if (isWon('O', board)) {
            cout << "O player won" << endl;
            exit(0);
        }
        else if (isDraw(board)) {
            cout << "No winner" << endl;
            exit(0);
        }
    }

    return 0;
}

bool checkBoard(char player, char board[][3]) {
    int row = sizeof(board) /sizeof(board[0]);
    int column = sizeof(board) /sizeof(board[0]);

    for (int i = 0; i <= row; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    for (int i = 0; i <= column; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool isWon(char player, char board[][3]) {
    return checkBoard(player, board);
}

bool isDraw(char board[][3]) {
    int row = sizeof(board) /sizeof(board[0]);
    int column = sizeof(board) /sizeof(board[0]);

    for (int i = 0; i <= row; i++) {
        for (int j = 0; j <= column; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}
void displayBoard(char board[][3]) {
    int row = sizeof(board) /sizeof(board[0]);
    int column = sizeof(board) /sizeof(board[0]);

    for (int i = 0; i <= row; i++) {
        cout << "------------- \n";
        for (int j = 0; j <= column; j++) {
            cout << "| " << board[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "-------------\n";
}
void makeAMove(char board[][3], char player){
    int row = -1, column = -1;
    takeInput(&row, &column, player, board);
    board[row][column] = player;

}

void takeInput(int* row, int* column, char player, char board[][3]) {

    do {
        cout << "Enter a row (0, 1, 2) for player " << player <<  ":";
        cin >> *row;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a digit\n";
            continue;
        }
        cout << "Enter a column (0, 1, 2) for player " << player << ":";
        cin >> *column;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a digit\n";
            continue;
        }
    } while (!checkInput(*row, *column, board));

}

bool checkInput(int row, int column, char board[][3]) {
    if (row < 0 || row > 2) {
        cout << "\nInvalid input. Row and column must be between 0 and 2.\n";
        return false;
    } else if (column < 0 || column > 2) {
        cout << "\nInvalid input. Row and column must be between 0 and 2.\n";
        return false;
    } else if (board[row][column] != ' ') {
        cout << "This cell is already occupied. Try a different cell\n";
        return false;
    }
    else return true;

}