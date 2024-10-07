#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {
    int u, v, w;
};

struct Dsu {
    vector<int> parent;

    void init(int n) {
        parent.resize(n + 5, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        parent[v] = u;
        return true;
    }
} dsu;

vector<edge> edges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, res = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    dsu.init(n);
    sort(edges.begin(), edges.end(), [](const edge &a, const edge &b) {
        return a.w < b.w;
    });
    for (const edge &edge: edges) {
        if (!dsu.join(edge.u, edge.v)) continue;
        res += edge.w;
    }
    cout << res << '\n';
    return 0;
}