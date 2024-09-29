#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

ll solve(const vector<int> &arr, int n, int m) {
    vector<ll> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = m; j > arr[i] - 1; --j) {
            dp[j] += dp[j - arr[i]];
        }
    }
    return (dp[m] - (m == 0)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << solve(arr, n, m);
    return 0;
}
