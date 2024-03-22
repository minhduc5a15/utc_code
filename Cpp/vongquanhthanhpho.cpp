#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

vector<vi> graph;
vi root_node, steps_taken, prev_nodes, steps_from_root;
int m, n;

void reset() {
    graph.clear();
    root_node.clear();
    steps_taken.clear();
    prev_nodes.clear();
    steps_from_root.clear();
}

void solve() {
    root_node.resize(m);
    steps_taken.resize(m);
    prev_nodes.resize(m);
    steps_from_root.resize(m);
    queue<int> q;
    int res = m * 2;
    for (int vertex: graph[0]) {
        root_node[vertex] = prev_nodes[vertex] = vertex;
        steps_from_root[vertex] = steps_taken[vertex] = 1;
        q.push(vertex);
    }
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int node: graph[curr]) {
            if (node == 0 or prev_nodes[curr] == node) continue;
            if (root_node[node] == 0) {
                q.push(node);
                prev_nodes[node] = curr;
                root_node[node] = root_node[curr];
                steps_taken[node] = steps_taken[curr] + 1;
                steps_from_root[root_node[node]] = max(steps_from_root[root_node[node]], steps_taken[node]);
            }
            else if (root_node[curr] != root_node[node]) {
                res = min(res, steps_taken[curr] + steps_taken[node] + 1);
            }
        }
    }
    if (res == m * 2) {
        int size = steps_from_root.size();
        sort(steps_from_root.begin(), steps_from_root.end());
        cout << steps_from_root[size - 1] + steps_from_root[size - 2] + 1 << '\n';
        return;
    }
    cout << res << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        graph.resize(m);
        while (n--) {
            int u, v;
            cin >> u >> v;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        solve();
        reset();
    }
    return 0;
}
