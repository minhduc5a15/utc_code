#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

bool check(int diff, int n, int k, const vector<int> &h) {
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; ++i) {
        ll L = static_cast<ll>(i) * diff - h[i];
        ll R = static_cast<ll>(i) * diff + h[i];
        arr[i] = {L, R};
    }
    sort(arr.begin(), arr.end());

    vector<ll> lis;
    for (int i = 0; i < n; ++i) {
        ll cur = arr[i].second;
        if (auto pos = upper_bound(lis.begin(), lis.end(), cur); pos == lis.end()) {
            lis.push_back(cur);
        }
        else {
            *pos = cur;
        }
    }
    return static_cast<int>(lis.size()) >= (n - k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        if (n <= 1 || n - k <= 1) {
            cout << 0 << '\n';
            continue;
        }

        int low = 0, high = INT_MAX, res = high;
        while (low <= high) {
            if (int mid = low + (high - low) / 2; check(mid, n, k, arr)) {
                res = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        cout << res << '\n';
    }

    return 0;
}
