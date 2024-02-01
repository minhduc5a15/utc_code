#include <stdio.h>
#include <stdlib.h>
#define ll long long
const int MOD = 1000000007;

int main() {
    int n;
    scanf("%d", &n);
    ll dp[n][n];
    ll arr[n + 1];
    for (int i = 0; i < n; ++i) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        dp[i][i] = llabs(x - y);
        arr[i + 1] = arr[i] + dp[i][i];
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= n - i; ++j) {
            int k = j + i - 1;
            ll s = arr[k + 1] - arr[j];
            dp[j][k] = s - dp[j + 1][k] > s - dp[j][k - 1] ? s - dp[j + 1][k] : s - dp[j][k - 1];
        }
    }

    ll ken = dp[0][n - 1];
    ll kun = arr[n] - ken;
    ken %= MOD;
    kun %= MOD;
    printf("%lld\n%lld\n", ken, kun);
    if (ken > kun) printf("Ken");
    else if (kun > ken) printf("Kun");
    else printf("-1");

    return 0;
}
