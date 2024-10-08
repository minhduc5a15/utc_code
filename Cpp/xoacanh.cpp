#include <iostream>
#include <vector>
using namespace std;

struct edge {
    int u, v;

    edge(): u(0), v(0) {}

    edge(int u, int v) : u(u), v(v) {}
};

class DSU {
protected:
    vector<int> parent, size;

public:
    explicit DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    void handle(int u, int v) {
        u = find(u);
        if (v = find(v); u != v) {
            if (size[u] < size[v]) swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    }

    int get_size(int u) {
        return size[find(u)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<edge> graph(m), queries(q);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[i] = {u - 1, v - 1};
    }
    for (int i = 0; i < q; ++i) {
        int e, c;
        cin >> e >> c;
        queries[i] = {e - 1, c - 1};
    }
    DSU dsu(n);
    vector<bool> check(m, false);
    for (auto [e, _]: queries) {
        check[e] = true;
    }
    for (int i = 0; i < m; ++i) {
        if (!check[i]) {
            dsu.handle(graph[i].u, graph[i].v);
        }
    }

    vector<int> result(q);

    for (int i = q - 1; i >= 0; --i) {
        auto [e, c] = queries[i];
        result[i] = dsu.get_size(c);
        dsu.handle(graph[e].u, graph[e].v);
    }
    for (int res: result) {
        cout << res << "\n";
    }
    return 0;
}