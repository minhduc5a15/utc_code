#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n), prev_arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        prev_arr[i] = arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<ll> prefixSum(n);
    prefixSum.front() = arr.front();
    for (int i = 1; i < n; ++i) prefixSum[i] = prefixSum[i - 1] + arr[i];
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;
        int target = prev_arr[q];
        int pos = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
        while (pos < n - 1 && arr[pos] == arr[pos + 1]) {
            ++pos;
        }
        ll sum = prefixSum.back();
        if (pos) {
            cout << (ll)target * (2 * pos - n) - 2 * prefixSum[pos - 1] + sum << '\n';
        }
        else {
            cout << sum - (ll)(n * target) << '\n';
        }
    }
    return 0;
}

