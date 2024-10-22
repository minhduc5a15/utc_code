#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef vector<int> vi;

int n, m;
vector<vi> graph;
vi dist;
stack<int> st;
vector<bool> visited;

void topo_sort(int v) {
    visited[v] = true;
    for (int u: graph[v]) {
        if (!visited[u]) topo_sort(u);
    }
    st.push(v);
}

void solve() {
    if (graph.at(1).empty()) return;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) topo_sort(i);
    }
    dist[1] = 0;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (dist[u] != -1) {
            for (int v: graph.at(u)) {
                dist[v] = max(dist[v], dist[u] + 1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    int u, v;
    graph.assign(n + 1, vi()), visited.assign(n + 1, false), dist.assign(n + 1, -1);
    while (m--) {
        cin >> u >> v;
        graph[u].push_back(v);
    }
    solve();
    ++dist[n];
    if (dist[n] <= 1) return cout << "Hello World!", 0;
    cout << dist[n];
    return 0;
}
