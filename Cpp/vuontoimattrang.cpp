#include <stdio.h>
#include <stdlib.h>
#define MOD 1000000007

int solve(int n, int a, int b) {
    if (n == 0) return 0;
    int* dp = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i <= n; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (i - a >= 0) {
            dp[i] = (dp[i] + dp[i - a]) % MOD;
        }
        if (i - b >= 0) {
            dp[i] = (dp[i] + dp[i - b]) % MOD;
        }
    }
    int result = dp[n];
    free(dp);
    return result;
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    printf("%d", solve(n, a, b));
    return 0;
}
