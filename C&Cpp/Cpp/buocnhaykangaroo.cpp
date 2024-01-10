#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y;
    cin >> n >> x >> y;
    int res = INT_MIN;
    vector<int> dp(n, INT_MIN);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (i >= x) {
            mp[dp[i - x]]++;
        }
        if (!mp.empty()) {
            dp[i] = max(a, mp.rbegin()->first + a);
        }
        else {
            dp[i] = a;
        }
        if (i >= y && i - y >= 0) {
            mp[dp[i - y]]--;
            if (mp[dp[i - y]] == 0) {
                mp.erase(dp[i - y]);
            }
        }
        res = max(dp[i], res);
    }
    cout << res;
    return 0;
}
