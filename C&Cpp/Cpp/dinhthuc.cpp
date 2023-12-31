#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef vector<vector<double>> matrixdb;

double determinant(const matrixdb &matrix) {
    double total = 0;
    int size = matrix.size();
    if (matrix.size() == 2 && matrix[0].size() == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
    }
    for (int fc = 0; fc < size; fc++) {
        matrixdb As(size - 1, vector<double>(size - 1));
        for (int i = 1; i < size; ++i) {
            int j1 = 0;
            for (int j = 0; j < size; ++j) {
                if (j == fc)
                    continue;
                As[i - 1][j1] = matrix[i][j];
                j1++;
            }
        }
        double sign = (fc % 2 == 0) ? 1 : -1;
        total += sign * matrix[0][fc] * determinant(As);
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    matrixdb matrix(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << fixed << setprecision(2) << determinant(matrix) << endl;
    return 0;
}

