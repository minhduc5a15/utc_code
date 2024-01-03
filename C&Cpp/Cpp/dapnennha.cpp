#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef vector<vector<int>> matrixi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n, d;
    cin >> m >> n >> d;
    matrixi matrix(m, vector<int>(n));

    int min_val = INT_MAX;
    int max_val = INT_MIN;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
            min_val = min(min_val, matrix[i][j]);
            max_val = max(max_val, matrix[i][j]);
        }
    }

    int res = INT_MAX;
    for (int target = min_val; target <= max_val; target += d) {
        int steps = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int diff = abs(matrix[i][j] - target);
                if (diff % d == 0) {
                    steps += diff / d;
                }
                else {
                    steps = INT_MAX;
                    break;
                }
            }
            if (steps == INT_MAX) {
                break;
            }
        }
        res = min(res, steps);
    }
    cout << (res == INT_MAX ? -1 : res) << endl;
    return 0;
}
