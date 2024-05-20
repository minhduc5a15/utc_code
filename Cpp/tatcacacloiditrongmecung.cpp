#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef vector<int> vi;
const vi dx = {1, -1, 0, 0};
const vi dy = {0, 0, 1, -1};
const vector<char> dir = {'N', 'B', 'D', 'T'};

set<string> res;
vector<vi> matrix;
int n, m;

void solve(string path, int i, int j) {
    if (i == n - 1 and j == m - 1) {
        res.insert(path);
        return;
    }
    for (int k = 0; k < 4; ++k) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx >= 0 and nx < n and ny >= 0 and ny < m and matrix[nx][ny] == 0) {
            matrix[nx][ny] = 1;
            solve(path + dir.at(k), nx, ny);
            matrix[nx][ny] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    matrix.assign(n, vi(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    matrix[0][0] = 1;
    solve("", 0, 0);
    if (res.empty()) return cout << "rua khong di duoc", 0;
    for (string s: res) {
        cout << s << '\n';
    }
    return 0;
}
