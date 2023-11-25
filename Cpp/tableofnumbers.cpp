#include <iostream>
#include <vector>
typedef long long ll;
typedef std::vector<ll> Vector;
typedef std::vector<Vector> Matrix;
typedef std::pair<ll, ll> Pair;
const ll INF = 2147483647;

Pair solve(int m, int n, Matrix& matrix) {
    Matrix dp_count(m, Vector(n, 0));
    Matrix dp(m, Vector(n, INF));
    if (matrix[0][0] > 0) {
        dp[0][0] = matrix[0][0];
        dp_count[0][0] = 1;
    };
    for (int i = 1; i < m; ++i) {
        if (matrix[i][0] > 0) {
            dp[i][0] = dp[i - 1][0] + matrix[i][0];
            dp_count[i][0] = 1;
        };
    };
    for (int j = 1; j < n; ++j) {
        if (matrix[0][j] > 0) {
            dp[0][j] = dp[0][j - 1] + matrix[0][j];
            dp_count[0][j] = 1;
        };
    };
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][j] > 0) {
                if (dp[i - 1][j] < dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j] + matrix[i][j];
                    dp_count[i][j] = dp_count[i - 1][j];
                }
                else if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i][j - 1] + matrix[i][j];
                    dp_count[i][j] = dp_count[i][j - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j] + matrix[i][j];
                    dp_count[i][j] = dp_count[i - 1][j] + dp_count[i][j - 1];
                };
            };
        };
    };
    return matrix[m - 1][n - 1] > 0 ? std::make_pair(dp[m - 1][n - 1], dp_count[m - 1][n - 1]) : std::make_pair(INF, 0LL);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int m, n;
    std::cin >> m >> n;
    Matrix matrix(m, Vector(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        };
    };
    Pair result = solve(m, n, matrix);
    std::cout << result.first << " " << result.second;
    return 0;
}