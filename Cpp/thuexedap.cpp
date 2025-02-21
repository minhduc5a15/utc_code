#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef long long ll;

class ST {
private:
    vector<ll> seg;

    ll get_min(int id, int l, int r, int u, int v) {
        if (v < l or r < u) return LLONG_MAX;
        if (u <= l and r <= v) return seg[id];
        int mid = (l + r) >> 1;
        return min(get_min(id << 1, l, mid, u, v), get_min(id << 1 | 1, mid + 1, r, u, v));
    }

    void update(int id, int l, int r, int pos, ll val) {
        if (l == r) {
            seg[id] = val;
            return;
        }
        if (int mid = (l + r) >> 1; pos <= mid) update(id << 1, l, mid, pos, val);
        else update(id << 1 | 1, mid + 1, r, pos, val);
        seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
    }

public:
    int n;

    void init(int size) {
        n = size;
        seg.assign(n << 2 | 1, LLONG_MAX);
    }

    void build(int id, int l, int r, const vector<ll> &dp) {
        if (l == r) {
            seg[id] = dp[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid, dp);
        build(id << 1 | 1, mid + 1, r, dp);
        seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
    }

    ll get_min(int l, int r) {
        return get_min(1, 1, n + 1, l, r);
    }

    void update(int pos, ll val) {
        update(1, 1, n + 1, pos, val);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> t(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> t[i] >> p[i];
    }
    vector<ll> dp(n + 2, LLONG_MAX);
    dp[n + 1] = 0;
    ST seg;
    seg.init(n + 1);
    seg.update(n + 1, dp[n + 1]);
    for (int i = n; i >= 1; --i) {
        int l = i + 1, r = t[i] + 1;
        ll s = seg.get_min(l, r);
        dp[i] = p[i] + s;
        seg.update(i, dp[i]);
    }
    cout << dp[1];
    return 0;
}
