#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int solve(int n, int k, int m, int s, int f) {
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;
    q.push({s, 0});
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        if (current.first == f) return current.second;
        vector<int> next_floors = {current.first - m, current.first + k};
        for (int next_floor: next_floors) {
            if (1 <= next_floor && next_floor <= n && !visited[next_floor]) {
                visited[next_floor] = true;
                q.push({next_floor, current.second + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, m, s, f;
    cin >> n >> k >> m >> s >> f;
    cout << solve(n, k, m, s, f);
    return 0;
}

// code by duck it1
