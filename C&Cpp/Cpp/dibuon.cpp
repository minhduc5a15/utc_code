#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1, 0);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        int benefit = static_cast<int>(a * b * 0.01);
        for (int j = m; j >= a; --j) {
            dp[j] = max(dp[j], dp[j - a] + benefit);
        }
    }
    cout << dp[m];
    return 0;
}

