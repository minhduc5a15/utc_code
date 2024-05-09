#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

vector<vi> graph;
vi up_map, down_map;

int dfs(int u, int v) {
    for (int i: graph[u]) {
        if (i != v) {
            down_map[i] += down_map[u];
            up_map[u] += dfs(i, u);
        }
    }
    return up_map[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    graph.assign(n + 5, vi()), up_map.assign(n + 5, 0), down_map.assign(n + 5, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int q;
    cin >> q;
    while (q--) {
        string cmd;
        int i;
        cin >> cmd >> i;
        if (cmd == "UPCAST") ++up_map[i];
        else ++down_map[i];
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        cout << ((up_map[i] + down_map[i]) & 1);
    }
    return 0;
}
