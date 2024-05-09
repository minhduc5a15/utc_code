#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const int MOD = 1000000007;

unordered_map<ll, vll> graph;
vll visited, memo;

ll dfs(ll start, ll end) {
    if (start == end) return 1;
    if (memo[start] != -1) return memo[start];
    visited[start] = true;
    ll paths = 0;
    if (graph.find(start) != graph.end()) {
        for (ll node: graph.at(start)) {
            if (!visited[node]) {
                paths += dfs(node, end) % MOD;
            }
        }
    }
    visited[start] = false;
    return memo[start] = paths % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
    }
    visited.resize(n + 1, false);
    memo.resize(n + 1, -1);
    cout << dfs(1, n);
    return 0;
}
