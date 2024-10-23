#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q, maxm = 0;
    cin >> n;
    vector<pair<int, int>> items(n);
    items.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> items[i].first >> items[i].second;
    }
    cin >> q;
    vector<int> queries(n);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
        maxm = max(maxm, queries[i]);
    }
    vector<int> dp(maxm + 1, 0);
    for (const pair<int, int> &item: items) {
        for (int w = maxm; w >= item.first; --w) {
            dp[w] = max(dp[w], item.second + dp[w - item.first]);
        }
    }
    for (int query: queries) {
        cout << dp[query] << '\n';
    }
    return 0;
}
