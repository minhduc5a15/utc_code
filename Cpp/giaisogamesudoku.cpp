// source: https://stackoverflow.com/questions/1697334/algorithm-for-solving-sudoku
#include <iostream>
#include <vector>
#define duck int main
using namespace std;
pair<int, int> next_cell(vector<vector<int>>& grid, int i, int j) {
    for (int x = i; x < 9; ++x) {
        for (int y = j; y < 9; ++y) {
            if (grid[x][y] == 0) {
                return make_pair(x, y);
            }
        }
    }
    for (int x = 0; x < 9; ++x) {
        for (int y = 0; y < 9; ++y) {
            if (grid[x][y] == 0) {
                return make_pair(x, y);
            }
        }
    }
    return make_pair(-1, -1);
}

bool isValid(vector<vector<int>>& grid, int i, int j, int e) {
    for (int x = 0; x < 9; ++x) {
        if (grid[i][x] == e) {
            return false;
        }
    }
    for (int x = 0; x < 9; ++x) {
        if (grid[x][j] == e) {
            return false;
        }
    }
    int secTopX = 3 * (i / 3);
    int secTopY = 3 * (j / 3);
    for (int x = secTopX; x < secTopX + 3; ++x) {
        for (int y = secTopY; y < secTopY + 3; ++y) {
            if (grid[x][y] == e) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& grid, int i = 0, int j = 0) {
    pair<int, int> cell = next_cell(grid, i, j);
    i = cell.first;
    j = cell.second;
    if (i == -1) {
        return true;
    }
    for (int e = 1; e <= 9; ++e) {
        if (isValid(grid, i, j, e)) {
            grid[i][j] = e;
            if (solveSudoku(grid, i, j)) {
                return true;
            }
            grid[i][j] = 0;
        }
    }
    return false;
}

duck() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>> grid(9, vector<int>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> grid[i][j];
        }
    }
    solveSudoku(grid);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
