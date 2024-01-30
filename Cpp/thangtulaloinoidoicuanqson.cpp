#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

class MergeSortTree {
private:
    vi arr;
    vector<vi> tree;
public:
    int n, q;

    void input() {
        cin >> n >> q;
        arr.resize(n + 1);
        tree.resize(4 * n + 1, vector<int>());
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
    }

    void build(int id, int l, int r) {
        if (l == r) {
            tree[id].push_back(arr[l]);
            return;
        }
        int mid = (l + r) / 2;

        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);

        merge(tree[2 * id].begin(), tree[2 * id].end(), tree[2 * id + 1].begin(), tree[2 * id + 1].end(), back_inserter(tree[id]));
    }

    int query(int id, int l, int r, int x, int y, int u, int v) {
        if (y < l || x > r) return 0;
        if (x <= l && r <= y) {
            vi::iterator lb = lower_bound(tree[id].begin(), tree[id].end(), u);
            vi::iterator ub = upper_bound(tree[id].begin(), tree[id].end(), v);
            return ub - lb;
        }
        int mid = (l + r) / 2;
        return query(2 * id, l, mid, x, y, u, v) + query(2 * id + 1, mid + 1, r, x, y, u, v);
    }

    void solve() {
        while (q--) {
            int x, y, l, r;
            cin >> x >> y >> l >> r;
            cout << query(1, 1, n, x, y, l, r) << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MergeSortTree tree;
    tree.input();
    tree.build(1, 1, tree.n);
    tree.solve();
    return 0;
}
