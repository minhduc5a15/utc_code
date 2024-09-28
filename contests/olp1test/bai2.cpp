#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, float> pif;

int solve(vector<pif> &bricks) {
    int n = bricks.size();
    sort(bricks.begin(), bricks.end(), [](const pif &a, const pif &b) {
        return a.second <= b.second;
    });
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (bricks[i].first >= bricks[j].first and dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    return n - *max_element(dp.begin(), dp.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pif> bricks(n);
    for (int i = 0; i < n; ++i) {
        cin >> bricks[i].first >> bricks[i].second;
    }
    cout << solve(bricks);
    return 0;
}
