#include <iostream>
#include <vector>
#define ll long long
#define MOD 1000000007LL

using namespace std;

ll solve(ll n) {
    --n;
    vector<ll> dp(n + 1, 0LL);
    dp[0] = 2;
    dp[1] = 4;
    dp[2] = 7;
    for (ll i = 3; i <= n; ++i) {
        dp[i] = (2LL * dp[i - 1] - dp[i - 2] + dp[i - 3]) % MOD;
    }
    return (dp[n] + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin >> n;
    cout << solve(n);
    return 0;
}

// code by duck it1
