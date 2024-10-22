#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> matrixi;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    matrixi grid(n + 1, vi(n + 1)), dp(n + 1, vi(n + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char c;
            cin >> c;
            grid[i][j] = c == '.';
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (grid[i][j]) {
                if (i > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j > 1) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
            else dp[i][j] = 0;
        }
    }

    cout << dp[n][n];
    return 0;
}
