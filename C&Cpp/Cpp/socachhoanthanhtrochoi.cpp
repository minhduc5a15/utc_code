#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#define ll long long
using namespace std;
const int MOD = 1000000007;

ll dfs(const unordered_map<ll, vector<ll>> &graph, ll start, ll end, unordered_set<ll> &visited, vector<ll> &memo) {
    if (start == end) {
        return 1;
    }
    if (memo[start] != -1) {
        return memo[start];
    }
    visited.insert(start);
    ll paths = 0;
    if (graph.count(start)) {
        for (ll node: graph.at(start)) {
            if (visited.find(node) == visited.end()) {
                paths += dfs(graph, node, end, visited, memo) % MOD;
            }
        }
    }
    visited.erase(start);
    memo[start] = paths;
    return paths % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    unordered_map<ll, vector<ll>> graph;
    for (int i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    unordered_set<ll> visited;
    vector<ll> memo(n + 1, -1);
    cout << dfs(graph, 1, n, visited, memo) << endl;
    return 0;
}
