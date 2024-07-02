#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> matrixi;

int max_side(const matrixi &matrix, int n, int m, int num) {
    matrixi F(n, vi(m, 0));
    for (int i = 0; i < n; ++i) {
        F[i][0] = (matrix[i][0] == num) ? 1 : 0;
    }
    for (int j = 0; j < m; ++j) {
        F[0][j] = (matrix[0][j] == num) ? 1 : 0;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (matrix[i][j] == num and i >= F[i - 1][j] and j >= F[i][j - 1] and i >= F[i - 1][j - 1]) {
                F[i][j] = min(F[i - 1][j], min(F[i][j - 1], F[i - 1][j - 1])) + 1;
            }
        }
    }
    int max_side = 0;
    for (const vi &row: F) {
        max_side = max(max_side, *max_element(row.begin(), row.end()));
    }
    return max_side;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    matrixi matrix(n, vi(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << max(max_side(matrix, n, m, 0), max_side(matrix, n, m, 1));
    return 0;
}
