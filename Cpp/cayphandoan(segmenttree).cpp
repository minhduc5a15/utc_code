#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
private:
    vector<int> arr, seg, cnt, gcd;
    int n, q;
public:

    void init() {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        int max_size = 4 * n + 1;
        seg.resize(max_size);
        cnt.resize(max_size);
        gcd.resize(max_size);
    }

    static int GCD(int a, int b) {
        return b == 0 ? a : GCD(b, a % b);
    }

    void build(int id, int l, int r) {
        if (l == r) {
            seg[id] = arr[l];
            gcd[id] = arr[l];
            cnt[id] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build((id << 1) + 1, mid + 1, r);
        seg[id] = min(seg[id << 1], seg[(id << 1) + 1]);
        gcd[id] = GCD(gcd[id << 1], gcd[(id << 1) + 1]);
        cnt[id] = (gcd[id] == gcd[id << 1] ? cnt[id << 1] : 0) + (gcd[id] == gcd[(id << 1) + 1] ? cnt[(id << 1) + 1] : 0);
    }

    void update(int id, int l, int r, int i, int v) {
        if (i < l || r < i) return;
        if (l == r) {
            seg[id] = v;
            gcd[id] = v;
            cnt[id] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, i, v);
        update((id << 1) + 1, mid + 1, r, i, v);
        seg[id] = min(seg[id << 1], seg[(id << 1) + 1]);
        gcd[id] = GCD(gcd[id << 1], gcd[(id << 1) + 1]);
        cnt[id] = (gcd[id] == gcd[id << 1] ? cnt[id << 1] : 0) + (gcd[id] == gcd[(id << 1) + 1] ? cnt[(id << 1) + 1] : 0);
    }

    int getMin(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return INT_MAX;
        if (u <= l && r <= v) return seg[id];
        int mid = (l + r) >> 1;
        return min(getMin(id << 1, l, mid, u, v), getMin((id << 1) + 1, mid + 1, r, u, v));
    }

    int getGCD(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return gcd[id];
        int mid = (l + r) >> 1;
        return GCD(getGCD(id << 1, l, mid, u, v), getGCD((id << 1) + 1, mid + 1, r, u, v));
    }

    int getCount(int id, int l, int r, int u, int v, int g) {
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return (gcd[id] == g ? cnt[id] : 0);
        int mid = (l + r) >> 1;
        return getCount(id << 1, l, mid, u, v, g) + getCount((id << 1) + 1, mid + 1, r, u, v, g);
    }

    void solve() {
        this->build(1, 1, n);
        cin >> q;
        while (q--) {
            char type;
            cin >> type;
            if (type == 'C') {
                int x, v;
                cin >> x >> v;
                update(1, 1, n, x, v);
            }
            else {
                int l, r;
                cin >> l >> r;
                if (type == 'M') cout << getMin(1, 1, n, l, r) << '\n';
                else if (type == 'G') cout << getGCD(1, 1, n, l, r) << '\n';
                else cout << getCount(1, 1, n, l, r, getGCD(1, 1, n, l, r)) << '\n';
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    SegmentTree tree;
    tree.init();
    tree.solve();
    return 0;
}
