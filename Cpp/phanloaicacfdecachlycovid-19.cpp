#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
typedef vector<int> vi;

void solve(int n, const vi adj_list[]) {
    queue<int> q;
    unordered_map<int, int> map;
    vi dist(n + 1, -1);
    int t;
    cin >> t;
    map[0] = t;
    while (t--) {
        int node;
        cin >> node;
        q.push(node);
        dist[node] = 0;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: adj_list[u]) {
            if (dist[v] == -1) {
                q.push(v);
                dist[v] = dist[u] + 1;
                ++map[dist[v]];
            }
        }
    }
    for (int i = 0; i < n && map[i]; ++i) {
        cout << "F" << i << ": " << map[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vi adj_list[n + 1];
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj_list[u].emplace_back(v);
        adj_list[v].emplace_back(u);
    }
    solve(n, adj_list);
    return 0;
}
