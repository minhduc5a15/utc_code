// bài này hay z
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
typedef vector<vector<bool>> matrix;
const vector<pii> directions = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    matrix grid(n, vector<bool>(m, false)), result(n, vector<bool>(m, false));
    result[1][1] = true;
    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c;
            grid[i][j] = (c == '.');
        }
    }
    queue<pii> q;
    q.push({ 1, 1 });
    while (!q.empty()) {
        pii curr_pos = q.front();
        q.pop();
        for (pii direction : directions) {
            int nx = direction.first, ny = direction.second;
            int i = 1;
            bool check = false;
            while (grid[curr_pos.first + i * nx][curr_pos.second + i * ny]) {
                if (!result[curr_pos.first + i * nx][curr_pos.second + i * ny]) {
                    check = result[curr_pos.first + i * nx][curr_pos.second + i * ny] = true;
                }
                ++i;
            }
            --i;
            if (check) q.push({ curr_pos.first + i * nx, curr_pos.second + i * ny });
        }
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            count += result[i][j];
        }
    }
    cout << count;
    return 0;
}
