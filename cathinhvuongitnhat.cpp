#include <iostream>
#include <vector>
using namespace std;

int solve(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == j) dp[i][j] = 1;
            else {
                dp[i][j] = i * j;
                for (int k = 1; k <= min(i, j); ++k) {
                    dp[i][j] = min(dp[i][j], min(dp[i - k][j] + dp[k][j - k] + 1, dp[i][j - k] + dp[i - k][k] + 1));
                }
            }
        }
    }
    return dp[m][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, n;
    cin >> m >> n;
    cout << solve(m, n);
    return 0;
}
