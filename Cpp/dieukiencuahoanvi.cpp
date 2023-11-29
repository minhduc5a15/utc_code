#include <iostream>
#define ll long long
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 1000005;
int dp[MAX_N];

int main() {
    dp[0] = dp[1] = 1;
    dp[2] = dp[3] = 0;
    for (int i = 4; i < MAX_N; ++i) {
        dp[i] = ((ll)(i + 1) * dp[i - 1] - (ll)(i - 2) * dp[i - 2] - (ll)(i - 5) * dp[i - 3] + (ll)(i - 3) * dp[i - 4]) % MOD;
        if (dp[i] < 0) dp[i] += MOD;
    }
    int n;
    cin >> n;
    cout << dp[n];
    return 0;
}
