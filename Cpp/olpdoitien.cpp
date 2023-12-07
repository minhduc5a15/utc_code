#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool solve(int n, vector<vector<float>> &matrix) {
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
        if (log_exchange_rates[i][i] > 0) {
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
        cout << (solve(n, matrix) ? "YES" : "NO") << '\n';
    }
    return 0;
}


// code by duck it1
