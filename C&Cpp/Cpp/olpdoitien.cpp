#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool solve(const vector<vector<float>> &matrix, int n) {
    vector<vector<float>> log_exchange_rates(n, vector<float>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            log_exchange_rates[i][j] = log(matrix[i][j]);
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                log_exchange_rates[i][j] = max(log_exchange_rates[i][j], log_exchange_rates[i][k] + log_exchange_rates[k][j]);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (log_exchange_rates[i][i]) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<float>> matrix(n, vector<float>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
        cout << (solve(matrix, n) ? "YES" : "NO") << '\n';
    }
    return 0;
}


// code by duck it1
