#include <stdio.h>
typedef long long ll;
const ll MAXN = 1000000000000000000;

ll solve(int i, int j) {
    ll dp[2][j + 5];
    for (int x = 1; x <= i; ++x) {
        for (int y = 1; y <= j; ++y) {
            if (x == 1 || y == 1) {
                dp[x & 1][y] = 1;
            }
            else {
                dp[x & 1][y] = dp[(x - 1) & 1][y - 1] + dp[(x - 1) & 1][y];
            }
            if (dp[x & 1][y] > MAXN) {
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
