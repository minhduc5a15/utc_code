#include <iostream>
#include <vector>
using namespace std;

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
    vector<int> dp(m + 1, m + 1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = arr[i]; j <= m; ++j) {
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }
    if (dp[m] == m + 1) cout << "ATM khong the tra tien";
    else cout << dp[m];
    return 0;
}