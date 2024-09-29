#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool solve(const vector<string>& matrixA, const vector<string>& matrixB) {
    int rowsA = matrixA.size(), colsA = matrixA[0].size();
    int rowsB = matrixB.size(), colsB = matrixB[0].size();
    for (int i = 0; i <= rowsA - rowsB; ++i) {
        for (int j = 0; j <= colsA - colsB; ++j) {
            bool match = true;
            for (int p = 0; p < rowsB; ++p) {
                for (int q = 0; q < colsB; ++q) {
                    if (matrixA[i + p][j + q] != matrixB[p][q]) {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }
            if (match) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> matrixA(n), matrixB(m);
    for (int i = 0; i < n; ++i) {
        cin >> matrixA[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> matrixB[i];
    }
    cout << (solve(matrixA, matrixB) ? "Yes" : "No") << "\n";
    return 0;
}

