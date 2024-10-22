#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = n; j >= i; --j) {
            dp[j] += dp[j - i];
            dp[j] %= MOD;
        }
    }
    cout << dp.back();
    return 0;
}
