#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

vector<vi> adj;
vi visited;
int max_dist, max_node;

void dfs(int u, int d) {
    visited[u] = 1;
    if (d > max_dist) max_dist = d, max_node = u;
    for (int v: adj[u]) {
        if (visited[v] == 0) {
            dfs(v, d + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, a, b;
    cin >> n;
    adj.assign(n + 1, vi()), visited.assign(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    max_dist = -1;
    dfs(1, 0);
    visited.assign(n + 1, 0);
    max_dist = -1;
    dfs(max_node, 0);
    cout << max_dist;
    return 0;
}
