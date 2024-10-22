#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef vector<int> vi;

int m, n;
vector<vi> graph;
vector<vector<bool>> conflicts;
vi tasks, load;

bool isValid(int t, int p) {
    for (int i = 0; i < n; ++i) {
        if (tasks[i] == p) {
            if (conflicts[t][i]) {
                return false;
            }
        }
    }
    return true;
}

int solve(int i) {
    if (i == n) {
        return *ranges::max_element(load);
    }
    int res = INT_MAX;
    for (int p = 0; p < m; ++p) {
        if (ranges::find(graph[p], i + 1) != graph[p].end() && isValid(i, p)) {
            tasks[i] = p;
            load[p]++;
            res = min(res, solve(i + 1));
            load[p]--;
            tasks[i] = -1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> m >> n;
    graph.resize(m);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        graph[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> graph[i][j];
        }
    }
    int k;
    cin >> k;
    conflicts.resize(n, vector<bool>(n, false));
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        conflicts[u - 1][v - 1] = true;
        conflicts[v - 1][u - 1] = true;
    }
    tasks.resize(n, -1);
    load.resize(m, 0);
    int result = solve(0);
    if (result == INT_MAX) {
        cout << -1;
        return 0;
    }
    cout << result;
    return 0;
}