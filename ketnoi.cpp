#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, ranks;

int find(int u) {
    if (u != parent[u]) parent[u] = find(parent[u]);
    return parent[u];
}

void union_set(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (ranks.at(u) > ranks.at(v)) {
            parent.at(v) = u;
            return;
        }
        parent.at(u) = v;
        if (ranks.at(u) == ranks.at(v)) ++ranks[v];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);
    ranks.resize(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    int type, u, v;
    while (m--) {
        cin >> type >> u >> v;
        if (type == 1) union_set(u, v);
        else cout << (find(u) == find(v) ? "yes\n" : "no\n");
    }
    return 0;
}
