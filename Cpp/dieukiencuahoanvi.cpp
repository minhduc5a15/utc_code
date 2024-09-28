#include <iostream>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    ll dp[n + 5];
    dp[0] = dp[1] = 1;
    dp[2] = dp[3] = 0;
    for (ll i = 4; i <= n; ++i) {
        dp[i] = ((i + 1) * dp[i - 1] + (i - 3) * dp[i - 4] - (i - 2) * dp[i - 2] - (i - 5) * dp[i - 3] + MOD) % MOD;
    }
    cout << (dp[n] + MOD) % MOD;
    return 0;
}