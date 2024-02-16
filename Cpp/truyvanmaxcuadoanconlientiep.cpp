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
        seg.resize(4 * n + 5);
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
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        seg[id] = max(seg[2 * id], seg[2 * id + 1]);
    }

    int getMax(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return INT_MIN;
        if (u <= l && r <= v) return seg[id];
        int mid = (l + r) >> 1;
        return max(getMax(2 * id, l, mid, u, v), getMax(2 * id + 1, mid + 1, r, u, v));
    }

    void solve() {
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << getMax(1, 1, n, l, r) << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    SegmentTree tree;
    tree.init();
    tree.build(1, 1, tree.n);
    tree.solve();
    return 0;
}
