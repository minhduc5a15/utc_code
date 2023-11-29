#include <iostream>
#include <queue>
#include <vector>

int solve(int n, int k, int m, int s, int f) {
    std::vector<bool> visited(n + 1, false);
    std::queue<std::pair<int, int>> q;
    q.push({ s, 0 });
    while (!q.empty()) {
        std::pair<int, int> current = q.front();
        q.pop();
        if (current.first == f) return current.second;
        std::vector<int> next_floors = { current.first - m, current.first + k };
        for (int next_floor : next_floors) {
            if (1 <= next_floor && next_floor <= n && !visited[next_floor]) {
                visited[next_floor] = true;
                q.push({ next_floor, current.second + 1 });
            }
        }
    }
    return -1;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, k, m, s, f;
    std::cin >> n >> k >> m >> s >> f;
    std::cout << solve(n, k, m, s, f);
    return 0;
}