#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

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
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    ll sum = prefixSum.back();
    int q;
    cin >> q;
    while (q--) {
        int i;
        cin >> i;
        int target = prev_arr[q];
        int pos = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        cout << (ll) target * (2 * pos - n) - 2 * prefixSum[pos - 1] + sum << '\n';
    }
    return 0;
}

