#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> matrixi;
const vi dx = {1, -1, 0, 0};
const vi dy = {0, 0, 1, -1};

matrixi matrix;

bool isValid(int x, int y, int n, int m) {
    return 1 <= x and x <= n && 1 <= y and y <= m and matrix[x][y] != 1;
}

int bfs(int x1, int y1, int x2, int y2, int n, int m) {
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    visited[x1][y1] = true;
    queue<tuple<int, int, int>> q;
    q.push({x1, y1, 0});
    while (!q.empty()) {
        tuple<int, int, int> top = q.front();
        q.pop();
        int x = get<0>(top), y = get<1>(top), steps = get<2>(top);
        if (x == x2 && y == y2) return steps;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny, n, m) and !visited[nx][ny]) {
                q.push({nx, ny, steps + 1});
                visited[nx][ny] = true;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    matrix.resize(n + 1, vi(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> matrix[i][j];
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << bfs(x1, y1, x2, y2, n, m);
    return 0;
}
