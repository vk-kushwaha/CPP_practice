#include<bits/stdc++.h> 
using namespace std;

int boardSize;
vector<pair<int, int>> knightMoves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

bool isSafe(vector<vector<bool>> &board, int row, int col) {
    if (row >= 0 && col >= 0 && row < boardSize && col < boardSize && !board[row][col]) {
        for (const auto &move : knightMoves) {
            int newRow = row + move.first;
            int newCol = col + move.second;
            if (newRow >= 0 && newCol >= 0 && newRow < boardSize && newCol < boardSize && board[newRow][newCol]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int countWaysToPlaceKnights(vector<vector<bool>> &board, int row, int col, int knightsPlaced) {
    if (knightsPlaced == boardSize) {
        return 1;
    }

    int ways = 0;

    for (int i = row; i < boardSize; i++) {
        for (int j = (i == row ? col : 0); j < boardSize; j++) {
            if (isSafe(board, i, j)) {
                board[i][j] = true;
                ways += countWaysToPlaceKnights(board, i, j, knightsPlaced + 1);
                board[i][j] = false;
            }
        }
    }

    return ways;
}

void printKnightConfigurations(vector<vector<bool>> &board, int row, int col, int knightsPlaced, string currentConfig) {
    if (knightsPlaced == boardSize) {
        cout << currentConfig << " ";
        return;
    }

    for (int i = row; i < boardSize; i++) {
        for (int j = (i == row ? col : 0); j < boardSize; j++) {
            if (isSafe(board, i, j)) {
                board[i][j] = true;
                printKnightConfigurations(board, i, j, knightsPlaced + 1, currentConfig + "{" + to_string(i) + "-" + to_string(j) + "} ");
                board[i][j] = false;
            }
        }
    }
}



int main() {
    cin >> boardSize;
    vector<vector<bool>> board(boardSize, vector<bool>(boardSize, false));

    int ways = countWaysToPlaceKnights(board, 0, 0, 0);
    printKnightConfigurations(board, 0, 0, 0, "");
    cout<<endl;
    cout << ways << endl;
    return 0;
}