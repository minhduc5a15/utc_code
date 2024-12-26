#include <iostream>
#include <vector>
#include <deque>
using namespace std;
constexpr int MAXN = 1001;

class ST {
private:
    vector<int> seg;

public:
    void init() {
        seg.resize(MAXN << 2 | 1, 0);
    }

    void update(int id, int l, int r, int pos, int value) {
        if (pos < l || pos > r) return;
        if (l == r) {
            seg[id] = value;
            return;
        }
        int mid = (l + r) >> 1;
        update(id << 1, l, mid, pos, value);
        update(id << 1 | 1, mid + 1, r, pos, value);
        seg[id] = max(seg[id << 1], seg[id << 1 | 1]);
    }

    int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u) return 0;
        if (u <= l && r <= v) return seg[id];
        int mid = (l + r) >> 1;
        return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }

    void solve(int n, int k, const vector<int> &arr) {
        vector<deque<int>> vdq(MAXN);
        for (int i = 0; i < k; ++i) {
            vdq[arr[i]].push_back(i);
            update(1, 0, MAXN - 1, arr[i], vdq[arr[i]].back() - vdq[arr[i]].front());
        }
        cout << get(1, 0, MAXN - 1, 0, MAXN - 1) << ' ';
        for (int i = k; i < n; ++i) {
            int prev = arr[i - k];
            int curr = arr[i];
            if (!vdq[prev].empty()) {
                update(1, 0, MAXN - 1, prev, 0);
                vdq[prev].pop_front();
                if (!vdq[prev].empty()) {
                    update(1, 0, MAXN - 1, prev, vdq[prev].back() - vdq[prev].front());
                }
            }

            if (!vdq[curr].empty()) {
                update(1, 0, MAXN - 1, curr, 0);
            }
            vdq[curr].push_back(i);
            update(1, 0, MAXN - 1, curr, vdq[curr].back() - vdq[curr].front());

            cout << get(1, 0, MAXN - 1, 0, MAXN - 1) << ' ';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ST tree;
    tree.init();
    tree.solve(n, k, arr);
    return 0;
}
