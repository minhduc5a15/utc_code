#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> matrixi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m, n, q;
    cin >> m >> n >> q;
    matrixi matrix(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> matrix[i][j];
        }
    }
    matrixi prefix_sum(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefix_sum[i][j] = matrix[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }
    int r1, r2, c1, c2;
    while (q--) {
        cin >> r1 >> r2 >> c1 >> c2;
        int s = prefix_sum[r2][c2] - prefix_sum[r1 - 1][c2] - prefix_sum[r2][c1 - 1] + prefix_sum[r1 - 1][c1 - 1];
        cout << s << '\n';
    }
    return 0;
}
