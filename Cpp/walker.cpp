#include <iostream>
#include <vector>
using namespace std;
typedef vector<bool> vb;
const int MAXN = 25;

string path;
vector<vb> visited(MAXN << 1, vb(MAXN << 1, false));
int ex, ey;

bool is_valid(int x, int y, int steps, int n) {
    if (x > ex and x - n + steps > ex or y > ey and y - n + steps > ey) return false;
    if (x < ex and x + n - steps < ex or y < ey and y + n - steps < ey) return false;
    if ((n + ex + ey - x - y - steps + 2 * MAXN) & 1) return false;
    return true;
}

int solve(int i, int j, int steps, int n) {
    if (visited[i + MAXN][j + MAXN] or not is_valid(i, j, steps, n)) return 0;
    if (i == ex and j == ey) return steps == n;
    int res = 0;
    visited[i + MAXN][j + MAXN] = true;
    if (path[steps] == 'R') res = solve(i + 1, j, steps + 1, n);
    if (path[steps] == 'L') res = solve(i - 1, j, steps + 1, n);
    if (path[steps] == 'U') res = solve(i, j + 1, steps + 1, n);
    if (path[steps] == 'D') res = solve(i, j - 1, steps + 1, n);
    if (path[steps] == '_') {
        res += solve(i + 1, j, steps + 1, n);
        res += solve(i - 1, j, steps + 1, n);
        res += solve(i, j + 1, steps + 1, n);
        res += solve(i, j - 1, steps + 1, n);
    }
    visited[i + MAXN][j + MAXN] = false;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> ex >> ey;
        cin >> path;
        cout << solve(0, 0, 0, path.size()) << '\n';
    }
    return 0;
}