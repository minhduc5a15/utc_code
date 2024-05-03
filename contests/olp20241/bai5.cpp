#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> matrixi;
const vi dx = {1, 1, -1, -1, 0, 0, 1, -1};
const vi dy = {-1, 1, 1, -1, 1, -1, 0, 0};

int n, m;
matrixi matrix;

void solve() {
    matrixi mark(n, vi(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == -1) {
                mark[i][j] = -1;
                for (int k = 0; k < 8; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 <= nx and nx < n and 0 <= ny and ny < m and matrix[nx][ny] != -1) {
                        ++mark[nx][ny];
                    }
                }
            }
        }
    }
    for (vi row: mark) {
        for (int num: row) {
            cout << num << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    matrix.resize(n, vi(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    solve();
    return 0;
}