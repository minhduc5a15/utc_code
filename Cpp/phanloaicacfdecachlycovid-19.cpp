#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

void solve(int n, const vector<int> adj_list[]) {
    queue<int> q;
    unordered_map<int, int> map;
    vector<int> dist(n + 1, -1);
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
        for (const int& v : adj_list[u]) {
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
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> adj_list[n + 1];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    solve(n, adj_list);
    return 0;
}
// code by duck it1