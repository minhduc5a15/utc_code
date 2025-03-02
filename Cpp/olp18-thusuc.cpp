#include <iostream>
#include <vector>
using namespace std;

constexpr int NMAX = 500500;

class DSU {
private:
    vector<int> parent, s;

public:
    explicit DSU(int n) {
        parent.resize(n + 2);
        s.resize(n + 2);
        for (int i = 1; i <= n + 1; ++i) {
            parent[i] = i;
        }
    }

    void set(int i, int val) {
        s[i] = val;
        if (val == 1) {
            parent[i] = i + 1;
            return;
        }
        parent[i] = i;
    }

    int find(int u) {
        return (parent[u] == u ? u : parent[u] = find(parent[u]));
    }

    void update(int i, int new_val) {
        s[i] = new_val;
        if (new_val == 1) {
            parent[i] = find(i + 1);
            return;
        }
        parent[i] = i;
    }

    int get(int i) const {
        return s[i];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        dsu.set(i, x);
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            int i = dsu.find(l);
            while (i <= r) {
                int new_val = dsu.get(i) - 1;
                dsu.update(i, new_val);
                i = dsu.find(i + 1);
            }
        }
        else {
            int l, r, x;
            cin >> l >> r >> x;
            unsigned long long prod = 1;
            int res = -1;
            int i = dsu.find(l);
            while (i <= r) {
                if (prod > static_cast<unsigned long long>(x) / dsu.get(i)) {
                    res = i;
                    break;
                }
                prod *= dsu.get(i);
                i = dsu.find(i + 1);
            }
            cout << res << '\n';
        }
    }
    return 0;
}
