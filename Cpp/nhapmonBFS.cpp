#include <vector>
#include <queue>
#include <iostream>
#include <tuple>

typedef std::vector<int> vectori;

bool is_valid(int x, int y, int n, int m) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int solve(int n, int m, int x1, int y1, int x2, int y2) {
    vectori dx = {-2, -1, 1, 2, 2, 1, -1, -2};
    vectori dy = {1, 2, 2, 1, -1, -2, -2, -1};
    std::vector<std::vector<bool>> is_visited(n, std::vector<bool>(m));
    std::queue<std::tuple<int, int, int>> q;
    q.push(std::make_tuple(x1, y1, 0));
    is_visited[x1][y1] = true;

    while (!q.empty()) {
        std::tuple<int, int, int> front = q.front();
        q.pop();
        int x = std::get<0>(front);
        int y = std::get<1>(front);
        int steps = std::get<2>(front);
        if (x == x2 && y == y2) {
            return steps;
        }
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (is_valid(nx, ny, n, m) && !is_visited[nx][ny]) {
                q.push(std::make_tuple(nx, ny, steps + 1));
                is_visited[nx][ny] = true;
            }
        }
    }
    return -1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie();
    std::cout.tie();
    int n, m, x1, y1, x2, y2;
    std::cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    std::cout << solve(n, m, x1, y1, x2, y2) << std::endl;
    return 0;
}


// code by duck it1
