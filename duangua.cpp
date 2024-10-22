#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
const vector<int> dx = {-2, -1, 1, 2, 2, 1, -1, -2};
const vector<int> dy = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValid(int x, int y, int n) {
    return 1 <= x and x <= n and 1 <= y and y <= n;
}

int bfs(int x1, int y1, int x2, int y2, int n) {
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    queue<tuple<int, int, int>> q;
    visited[x1][y1] = true;
    q.push({x1, y1, 0});
    tuple<int, int, int> top;
    while (!q.empty()) {
        top = q.front();
        q.pop();
        int x = get<0>(top), y = get<1>(top), steps = get<2>(top);
        if (x == x2 and y == y2) return steps;
        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isValid(nx, ny, n) and !visited[nx][ny]) {
                q.push({nx, ny, steps + 1});
                visited[nx][ny] = true;
            }
        }
    }
    return -1;
}

void solve(int x1, int y1, int x2, int y2, int x3, int y3, int n) {
    int steps_1 = bfs(x1, y1, x3, y3, n), steps_2 = bfs(x2, y2, x3, y3, n);
    if (steps_1 == steps_2) cout << 0;
    else if (steps_1 == -1) cout << 2;
    else if (steps_2 == -1) cout << 1;
    else if (steps_1 < steps_2) cout << 1;
    else cout << 2 << '\n';
    cout << '\n' << steps_1 << ' ' << steps_2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x1, y1, x2, y2, x3, y3;
    cin >> n >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    solve(x1, y1, x2, y2, x3, y3, n);
    return 0;
}
