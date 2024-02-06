#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#define ll long long
using namespace std;
const int ITER = 5;

vector<ll> prefix_sum;

int solve(int l, int r, int end) {
    if (r - l <= 1) return l;
    ll min_diff = LONG_LONG_MAX;
    int pos = r;
    int low = l, high = end;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        ll s1 = prefix_sum[mid] - prefix_sum[l - 1];
        ll s2 = prefix_sum[r] - prefix_sum[mid];
        ll diff = abs(s1 - s2);
        if (diff < min_diff) {
            min_diff = diff;
            pos = mid;
        }
        if (s1 < s2) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return pos;
}

int re(int l, int r, int end, int iter) {
    if (iter == 0) return solve(l, r, end);
    else return re(l, r, re(l, r, end, iter - 1), iter - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q, x;
    cin >> n >> q;
    prefix_sum.resize(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        prefix_sum[i + 1] = prefix_sum[i] + x;
    }
    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << re(l, r, r, ITER) << '\n';
    }
    return 0;
}