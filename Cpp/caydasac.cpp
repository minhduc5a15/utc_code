#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 100005;
typedef vector<int> vi;

vector<vi> tree(MAXN, vi()), dp(MAXN, vi(10, 0));
vi node_color(MAXN);
int V, Q, u, v, c;

void dfs(int node, int parent) {
    dp[node][node_color[node]]++;
    for (int child: tree[node]) {
        if (child != parent) {
            dfs(child, node);
            for (int i = 1; i <= 9; ++i) {
                dp[node][i] += dp[child][i];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> V >> Q;
    for (int i = 1; i < V; ++i) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 1; i <= V; ++i) {
        cin >> node_color[i];
    }
    dfs(1, 0);
    while (Q--) {
        cin >> u >> c;
        cout << dp[u][c] << '\n';
    }
    return 0;
}