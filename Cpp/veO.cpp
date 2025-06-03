#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;

struct item {
    int u, parent;
    bool visited;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<ll> value(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> value[i];
    }

    vector<ll> inc(n + 1, 0), dec(n + 1, 0);
    stack<item> st;
    st.push({1, 0, false});

    while (!st.empty()) {
        auto [u, p, visited] = st.top();
        st.pop();

        if (!visited) {
            st.push({u, p, true});
            for (int v: adj[u]) {
                if (v != p) {
                    st.push({v, u, false});
                }
            }
        }
        else {
            ll max_inc = 0, max_dec = 0;
            for (int v: adj[u]) {
                if (v == p) continue;
                max_inc = max(max_inc, inc[v]);
                max_dec = max(max_dec, dec[v]);
            }
            if (ll cur = value[u] + max_inc - max_dec; cur > 0) {
                max_dec += cur;
            }
            else {
                max_inc -= cur;
            }
            inc[u] = max_inc;
            dec[u] = max_dec;
        }
    }
    cout << inc[1] + dec[1];
    return 0;
}
