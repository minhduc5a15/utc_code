#include <iostream>
#include <vector>
#include <string>

bool solve(const std::vector<std::string>& matrixA, const std::vector<std::string>& matrixB) {
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> matrixA(n), matrixB(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> matrixA[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> matrixB[i];
    }
    std::cout << (solve(matrixA, matrixB) ? "Yes" : "No") << "\n";
    return 0;
}


// code by duck it1
