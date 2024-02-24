#include <stdio.h>

long long solve(int i, int j) {
    long long dp[2][j + 5];
    for (int x = 1; x <= i; ++x) {
        for (int y = 1; y <= j; ++y) {
            if (x == 1 || y == 1) {
                dp[x & 1][y] = 1;
            }
            else {
                dp[x & 1][y] = dp[(x - 1) % 2][y - 1] + dp[(x - 1) % 2][y];
            }
            if (dp[x & 1][y] > 1e18) {
                return -1;
            }
        }
    }
    return dp[i & 1][j];
}

int main() {
    int i, j;
    scanf("%d %d", &i, &j);
    printf("%lld", solve(i, j));
    return 0;
}
