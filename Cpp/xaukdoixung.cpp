#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

void solve(string s, int k) {
    int n = s.size();
    vector<vi> dp(n + 1, vi(n + 1, 0));
    int res = 0;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            dp[i][j] = dp[i + 1][j - 1] + (s[i] != s[j]);
            if (dp[i][j] <= k) res = max(res, j - i + 1);
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        string s;
        int k;
        cin >> s >> k;
        solve(s, k);
    }
    return 0;
}