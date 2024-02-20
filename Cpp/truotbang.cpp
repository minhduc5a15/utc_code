#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<bool> vb;
typedef vector<vb> matrixb;
typedef pair<int, int> pii;
const vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    matrixb visited(n, vb(m, false));
    matrixb result(n, vb(m, false));
    result[1][1] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            visited[i][j] = (c == '.');
        }
    }
    queue<pii> q;
    q.push({1, 1});
    while (!q.empty()) {
        pii pos = q.front();
        q.pop();
        for (const pii &direction: directions) {
            int nx = direction.first, ny = direction.second;
            int i = 1;
            bool check = false;
            for (; visited[pos.first + i * nx][pos.second + i * ny]; ++i) {
                if (!result[pos.first + i * nx][pos.second + i * ny]) {
                    result[pos.first + i * nx][pos.second + i * ny] = true;
                    check = true;
                }
            }
            if (check) {
                q.push({pos.first + (i - 1) * nx, pos.second + (i - 1) * ny});
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (result[i][j]) ++count;
        }
    }
    cout << count;
    return 0;
}

