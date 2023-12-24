#include <iostream>
#include <vector>
#define MAXN 100001
using namespace std;

vector<int> parent(MAXN, 0);
vector<int> comp_size(MAXN, 0);

int solve(int a, int b) {
    a = (parent[a] != a) ? solve(parent[a], b) : parent[a];
    b = (parent[b] != b) ? solve(parent[b], a) : parent[b];
    if (a != b) {
        if (a > b) parent[a] = b;
        else parent[b] = a;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, max_size;
    int dist_gr = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        solve(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        parent[i] = solve(i, i);
        ++comp_size[parent[i]];
        max_size = max(max_size, comp_size[parent[i]]);
        dist_gr += parent[i] == i;
    }
    cout << dist_gr << endl << max_size;
    return 0;
}
