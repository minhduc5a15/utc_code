#include <iostream>
#include <vector>
#include <algorithm>
#define getAll(x) x.begin(), x.end()
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

inline int count(const vi &x, int y) {
    return upper_bound(getAll(x), y) - lower_bound(getAll(x), y);
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
        build(2 * id, l, mid);
        build(2 * id + 1, mid + 1, r);
        merge(getAll(tree[2 * id]), getAll(tree[2 * id + 1]), back_inserter(tree[id]));
    }

    pii query(int id, int start, int end, int x, int l, int r) {
        if (l > end || r < start) return {0, 0};
        if (l <= start && r >= end) {
            const vi &node = tree[id];
            int min_val = node.front();
            int max_val = node.back();
            if (x >= max_val) {
                return {max_val, count(node, max_val)};
            }
            if (x <= min_val) {
                return {min_val, count(node, min_val)};
            }
            auto it = lower_bound(getAll(node), x);
            if (*it == x) {
                return {x, upper_bound(getAll(node), x) - it};
            }
            auto left = prev(it, 1);
            if (x - *left <= *it - x) {
                int target = *left;
                return {target, count(node, target)};
            }
            return {*it, upper_bound(getAll(node), *it) - it};
        }
        int mid = (start + end) >> 1;
        pii left_q = query(2 * id, start, mid, x, l, r);
        pii right_q = query(2 * id + 1, mid + 1, end, x, l, r);
        if (!left_q.second) return right_q;
        if (!right_q.second) return left_q;
        if (left_q.first == right_q.first) {
            return {left_q.first, left_q.second + right_q.second};
        }
        if (abs(left_q.first - x) == abs(right_q.first - x)) {
            if (left_q.first < right_q.first) {
                return left_q;
            }
            return right_q;
        }
        if (abs(left_q.first - x) < abs(right_q.first - x)) {
            return left_q;
        }
        return right_q;
    }

    void solve() {
        this->build(1, 1, n);
        while (q--) {
            int x, l, r;
            cin >> x >> l >> r;
            pii res = query(1, 1, n, x, l, r);
            cout << res.first << ' ' << res.second << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    MergeSortTree tree;
    tree.init();
    tree.solve();
    return 0;
}