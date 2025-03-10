#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].emplace_back(v);
    }
    vector dist(n + 1, vector(n + 1, -1));
    for (int i = 1; i <= n; ++i) {
        queue<int> qu;
        dist[i][i] = 0;
        qu.push(i);
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            int d = dist[i][u];
            for (int v: graph[u]) {
                if (dist[i][v] == -1) {
                    dist[i][v] = d + 1;
                    qu.push(v);
                }
            }
        }
    }

    int blocks = (n + 63) / 64;
    vector saved(n + 1, vector(blocks, 0ULL));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] != -1) {
                int block = (j - 1) / 64;
                int bit = (j - 1) % 64;
                saved[i][block] |= (1ULL << bit);
            }
        }
    }

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        int s = INT_MAX;
        int res = 0;
        for (int b = 0; b < blocks; ++b) {
            unsigned long long k = saved[x][b] & saved[y][b] & saved[z][b];
            while (k) {
                int bit = __builtin_ctzll(k);
                int c = b * 64 + bit + 1;
                if (c > n) break;
                if (int sum = dist[x][c] + dist[y][c] + dist[z][c]; sum < s) {
                    s = sum;
                    res = c;
                }
                k &= k - 1;
            }
        }
        cout << res << '\n';
    }
    return 0;
}
