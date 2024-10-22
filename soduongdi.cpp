#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> matrixi;

bool isValid(int r, int c, int n, int m, matrixi &grid, vector<vector<bool>> &visited) {
    if (0 <= r and r < n and 0 <= c and c < m) {
        if (!visited[r][c] and (grid[r][c] == 0 or grid[r][c] == 2)) {
            return true;
        }
    }
    return false;
}

int countPaths(vector<int> &v, int r, int c, int n, int m, matrixi &grid, vector<vector<bool>> &visited, int zeros) {
    if (r == v[0] and c == v[1]) {
        return (zeros == 0) ? 1 : 0;
    }
    visited[r][c] = true;
    int count = 0;
    if (isValid(r - 1, c, n, m, grid, visited)) {
        count += countPaths(v, r - 1, c, n, m, grid, visited, (zeros - 1) * (grid[r - 1][c] == 0) + zeros * (grid[r - 1][c] != 0));
    }
    if (isValid(r + 1, c, n, m, grid, visited)) {
        count += countPaths(v, r + 1, c, n, m, grid, visited, (zeros - 1) * (grid[r + 1][c] == 0) + zeros * (grid[r + 1][c] != 0));
    }
    if (isValid(r, c - 1, n, m, grid, visited)) {
        count += countPaths(v, r, c - 1, n, m, grid, visited, (zeros - 1) * (grid[r][c - 1] == 0) + zeros * (grid[r][c - 1] != 0));
    }
    if (isValid(r, c + 1, n, m, grid, visited)) {
        count += countPaths(v, r, c + 1, n, m, grid, visited, (zeros - 1) * (grid[r][c + 1] == 0) + zeros * (grid[r][c + 1] != 0));
    }
    visited[r][c] = false;
    return count;
}

int solve(matrixi &grid, int n, int m) {
    vi u = {0, 0};
    vi v = {0, 0};
    int zeros = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 0) {
                ++zeros;
            }
            else if (grid[i][j] == 1) {
                u = {i, j};
            }
            else if (grid[i][j] == 2) {
                v = {i, j};
            }
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    return countPaths(v, u[0], u[1], n, m, grid, visited, zeros);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        matrixi grid(n, vi(m));
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) {
                cin >> grid[j][k];
            }
        }
        cout << solve(grid, n, m) << '\n';
    }
    return 0;
}
