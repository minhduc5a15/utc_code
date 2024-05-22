#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
const vi dx = {1, -1, 0, 0};
const vi dy = {0, 0, 1, -1};

int res = 0;
bool flag = false;
int n, m;
vector<vi> matrix, visited;

void dfs(int x, int y) {
    visited[x][y] = true;
    if (x == 0 or x == n - 1 or y == 0 or y == m - 1) flag = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 or nx >= n or ny < 0 or ny >= m or visited[nx][ny] or matrix[nx][ny] == 1) continue;
        dfs(nx, ny);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    matrix.assign(n, vi(m));
    visited = matrix;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (not visited[i][j] && matrix[i][j] == 0) {
                dfs(i, j);
                res += not flag;
                flag = false;
            }
        }
    }
    cout << res;
    return 0;
}
