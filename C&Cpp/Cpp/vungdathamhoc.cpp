#include <iostream>
#include <vector>
#define MAXN 1000000
#define ll long long
using namespace std;

vector<bool> visited(MAXN);
vector<ll> graph[MAXN];

ll dfs(ll v) {
    ll size = 1;
    visited[v] = true;
    for (ll x: graph[v]) {
        if (!visited[x]) {
            size += dfs(x);
        }
    }
    return size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        ll c_lib, c_road;
        cin >> n >> m >> c_lib >> c_road;
        for (int i = 0; i <= n; ++i) {
            graph[i].clear();
            visited[i] = false;
        }
        while (m--) {
            ll u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        ll res = 0;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                res += c_lib + (dfs(i) - 1) * min(c_lib, c_road);
            }
        }
        cout << res << '\n';
    }
    return 0;
}