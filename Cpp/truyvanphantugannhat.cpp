#include <iostream>
#include <vector>
#include <algorithm>
#define getAll(x) x.begin(), x.end()
#define lb(x, y) lower_bound(getAll(x), y)
#define ub(x, y) upper_bound(getAll(x), y)
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

inline int count(const vi &x, int y) {
    return ub(x, y) - lb(x, y);
}

class MergeSortTree {
private:
    vi arr;
    vector<vi> tree;
public:
    int n, q;

    void init() {
        cin >> n >> q;
        arr.resize(n + 1);
        tree.resize(4 * n + 5, vi());
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
    }

    void build(int id, int l, int r) {
        if (l == r) {
            tree[id].push_back(arr[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        merge(getAll(tree[id << 1]), getAll(tree[id << 1 | 1]), back_inserter(tree[id]));
    }

    pii query(int id, int start, int end, int x, int l, int r) {
        if (l > end or r < start) return {0, 0};
        if (l <= start or end <= r) {
            const vi &node = tree[id];
            int min_val = node.front(), max_val = node.back();
            if (x >= max_val) return {max_val, count(node, max_val)};
            if (x <= min_val) return {min_val, count(node, min_val)};
            vi::const_iterator it = lb(node, x);
            if (*it == x) return {x, ub(node, x) - it};
            vi::const_iterator left = prev(it, 1);
            if (x - *left <= *it - x) return {*left, count(node, *left)};
            return {*it, ub(node, *it) - it};
        }
        int mid = (start + end) >> 1;
        pii left_q = query(id << 1, start, mid, x, l, r);
        pii right_q = query(id << 1 | 1, mid + 1, end, x, l, r);
        if (!left_q.second) return right_q;
        if (!right_q.second) return left_q;
        if (left_q.first == right_q.first) return {left_q.first, left_q.second + right_q.second};
        if (abs(left_q.first - x) == abs(right_q.first - x)) {
            if (left_q.first < right_q.first) return left_q;
            return right_q;
        }
        if (abs(left_q.first - x) < abs(right_q.first - x)) return left_q;
        return right_q;
    }

    void solve() {
        build(1, 1, n);
        pii res;
        int x, l, r;
        while (q--) {
            cin >> x >> l >> r;
            res = query(1, 1, n, x, l, r);
            cout << res.first << ' ' << res.second << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    MergeSortTree tree;
    tree.init();
    tree.solve();
    return 0;
}