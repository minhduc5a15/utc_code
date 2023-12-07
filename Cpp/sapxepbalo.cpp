#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q, maxm = 0;
    cin >> n;
    vector<pair<int, int>> items;
    items.reserve(n);
    for (int i = 0; i < n; ++i) {
        int first, second;
        cin >> first >> second;
        items.emplace_back(first, second);
    }
    cin >> q;
    vector<int> queries;
    queries.reserve(q);
    for (int i = 0; i < q; ++i) {
        int query;
        cin >> query;
        queries.push_back(query);
        maxm = max(maxm, query);
    }
    vector<int> dp(maxm + 1, 0);
    for (const pair<int, int> &item: items) {
        for (int w = maxm; w >= item.first; --w) {
            dp[w] = max(dp[w], item.second + dp[w - item.first]);
        }
    }
    for (const int &query: queries) {
        cout << dp[query] << endl;
    }
    return 0;
}


// code by duck it1
