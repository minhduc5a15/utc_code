#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 10001;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> dp(MAXN, MAXN);
    dp[0] = 0;
    for (int i = 1; i <= MAXN; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[j] <= i) {
                dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            }
            else break;
        }
    }
    while (q--) {
        int m;
        cin >> m;
        cout << (dp[m] == MAXN ? -1 : dp[m]) << '\n';
    }
    return 0;
}
