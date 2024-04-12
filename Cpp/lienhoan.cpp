#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
const int MAXN = 1001;

vi visited(MAXN, 0);
vector<vi> graph(MAXN);
vector<vi> mark(MAXN, vi(MAXN, 0));

void dfs(int u) {
    if (visited[u]) return;
    mark[u][u] = visited[u] = 1;
    for (int v: graph[u]) {
        dfs(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k, n, m;
    cin >> k >> n >> m;
    vi arr(k);
    for (int i = 0; i < k; ++i) {
        cin >> arr[i];
    }
    graph.reserve(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
    }
    for (int x: arr) {
        fill(visited.begin(), visited.end(), 0);
        dfs(x);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int count = 0;
        for (int x: arr) count += mark[x][i];
        if (count == k) ++res;
    }
    cout << res;
    return 0;
}
