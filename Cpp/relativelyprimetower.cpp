#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

ull gcd(ull a, ull b) {
    return !b ? a : gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<ull> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<ull> dp(n, 0);
    ull res = 0;
    for (int i = 0; i < n; ++i) {
        dp[i] = arr[i];
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i] && gcd(arr[j], arr[i]) == 1) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res;
    return 0;
}
