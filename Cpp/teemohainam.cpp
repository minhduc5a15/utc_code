#include <iostream>
#include <queue>
#include <numeric>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> matrixi;

int n;
matrixi matrix, dist;
int i_start, j_start, i_end, j_end;
int start, des;

void generate() {
    matrix = matrixi(n, vi(n, 0));
    dist = matrixi(n, vi(n, 0));
    int d = 0;
    for (int x = 0, y = 0, i = 1; i <= n * n; ++i) {
        matrix[x][y] = i;
        if (matrix[x][y] == start) i_start = x, j_start = y;
        if (matrix[x][y] == des) i_end = x, j_end = y;
        if (d == 0) {
            x++;
            if (x + 1 == n || matrix[x + 1][y] != 0) {
                d = 1;
            }
        }
        else if (d == 1) {
            y++;
            if (y + 1 == n || matrix[x][y + 1] != 0) {
                d = 2;
            }
        }
        else if (d == 2) {
            x--;
            if (x - 1 == -1 || matrix[x - 1][y] != 0) {
                d = 3;
            }
        }
        else {
            y--;
            if (matrix[x][y - 1] != 0) {
                d = 0;
            }
        }
    }
}

queue<pair<int, int>> q;

void is_valid(int i, int j, int value, int step) {
    if (i < min(i_start, i_end) - 10) return;
    if (j < min(j_start, j_end) - 10) return;
    if (i > max(i_start, i_end) + 10) return;
    if (j > max(j_start, j_end) + 10) return;
    if (i < 0 || j < 0 || i >= n || j >= n) return;
    if (dist[i][j] != 0) return;
    if (gcd(value, matrix[i][j]) != 1) return;
    dist[i][j] = step + 1;
    q.push({i, j});
}

void solve() {
    generate();
    while (!q.empty()) q.pop();
    q.push({i_start, j_start});
    while (dist[i_end][j_end] == 0) {
        int i = q.front().first;
        int j = q.front().second;
        is_valid(i + 1, j, matrix[i][j], dist[i][j]);
        is_valid(i - 1, j, matrix[i][j], dist[i][j]);
        is_valid(i, j + 1, matrix[i][j], dist[i][j]);
        is_valid(i, j - 1, matrix[i][j], dist[i][j]);
        q.pop();
    }
    cout << dist[i_end][j_end] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> start >> des;
        if (start == des) {
            cout << 0 << '\n';
            continue;
        }
        solve();
    }
    return 0;
}
