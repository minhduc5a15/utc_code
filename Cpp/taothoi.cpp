#include <iostream>
#include <queue>
using namespace std;
typedef vector<int> vi;

const vi dx = {-1, 0, 1, 0};
const vi dy = {0, 1, 0, -1};

bool is_valid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int solve(vector<vi> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            }
            if (grid[i][j] == 1) {
                ++count;
            }
        }
    }
    int res = 0;
    while (!q.empty() && count) {
        int sz = q.size();
        while (sz--) {
            pair<int, int> p = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = p.first + dx[i];
                int ny = p.second + dy[i];
                if (is_valid(nx, ny, n, m) && grid[nx][ny] == 1) {
                    --count;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
        res++;
    }
    return count == 0 ? res * 60 : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vi> matrix(n, vi(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    cout << solve(matrix);
    return 0;
}
