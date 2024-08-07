#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef double db;
typedef vector<vector<db>> matrixdb;

db determinant(const matrixdb &matrix) {
    db total = 0;
    int size = matrix.size();
    if (matrix.size() == 2 and matrix[0].size() == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }
    for (int fc = 0; fc < size; ++fc) {
        matrixdb As(size - 1, vector<db>(size - 1));
        for (int i = 1; i < size; ++i) {
            int j1 = 0;
            for (int j = 0; j < size; ++j) {
                if (j == fc)
                    continue;
                As[i - 1][j1] = matrix[i][j];
                j1++;
            }
        }
        db sign = (fc % 2 == 0) ? 1 : -1;
        total += sign * matrix[0][fc] * determinant(As);
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    matrixdb matrix(n, vector<db>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << fixed << setprecision(2) << determinant(matrix) << endl;
    return 0;
}

