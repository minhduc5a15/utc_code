#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
constexpr int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, r;
    cin >> n >> m >> r;
    vi arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i] %= m;
    }
    vi dp(m, 0);
    for (int x: arr) {
        vi tmp(dp);
        for (int j = 0; j < m; ++j) {
            if (dp[j] > 0) {
                int p = (j * x) % m;
                tmp[p] = (tmp[p] + dp[j]) % MOD;
            }
        }
        tmp[x % m] = (tmp[x % m] + 1) % MOD;
        dp = tmp;
    }
    cout << dp[r];
    return 0;
}
