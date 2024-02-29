#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void printBoard(const vector<vector<char>>& board);
bool checkWin(const vector<vector<char>>& board, char player);
bool checkDraw(const vector<vector<char>>& board);
void playerTurn(vector<vector<char>>& board, char player);

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // 3x3 tic-tac-toe board initialized with spaces
    char currentPlayer = 'X';
    bool gameEnded = false;

    while (!gameEnded) {
        printBoard(board);
        playerTurn(board, currentPlayer);
        gameEnded = checkWin(board, currentPlayer);

        if (gameEnded) {
            cout << "Player " << currentPlayer << " wins!" << endl;
        } else if (checkDraw(board)) {
            cout << "The game is a draw!" << endl;
            gameEnded = true;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printBoard(board); // Print the final state of the board
    return 0;
}

void printBoard(const vector<vector<char>>& board) {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << ' ';
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -----\n";
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false; // If there's at least one cell not filled, it's not a draw
            }
        }
    }
    return true; // If all cells are filled and there's no winner, it's a draw
}

void playerTurn(vector<vector<char>>& board, char player) {
    int x, y;
    do {
        cout << "Player " << player << ", enter your move (row and column): ";
        cin >> x >> y;
    } while (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != ' ');

    board[x][y] = player;
}
