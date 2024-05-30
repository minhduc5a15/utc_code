#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree {
private:
    vector<int> arr;
    vector<int> seg;
public:
    int n, q;

    void init() {
        cin >> n >> q;
        arr.resize(n + 1);
        seg.resize(n << 2 | 1);
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
    }

    void build(int id, int l, int r) {
        if (l == r) {
            seg[id] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
    }

    int getMax(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return INT_MIN;
        if (u <= l && r <= v) return seg[id];
        int mid = (l + r) >> 1;
        return max(getMax(id << 1, l, mid, u, v), getMax(id << 1 | 1, mid + 1, r, u, v));
    }

    void solve() {
        build(1, 1, n);
        int l, r;
        while (q--) {
            cin >> l >> r;
            cout << getMax(1, 1, n, l, r) << '\n';
        }
    }
} tree;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    tree.init();
    tree.solve();
    return 0;
}
