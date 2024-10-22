#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
constexpr ll MOD = 1000000007;

int n, k;
vector<int> a(102, 0);
ll dp[102][4][4];
bool visited[102][4][4];

ll solve(int i, int last1, int last2) {
    if (i == n + 1) return 1;
    if (visited[i][last1][last2]) return dp[i][last1][last2] % MOD;
    ll count = 0;
    if (a[i] != 0) {
        if (a[i] != last1 || a[i] != last2) {
            count = solve(i + 1, a[i], last1) % MOD;
        }
    } else {
        for (int j = 1; j <= 3; ++j) {
            if (j != last1 || j != last2) {
                count += solve(i + 1, j, last1) % MOD;
            }
        }
    }
    visited[i][last1][last2] = true;
    return dp[i][last1][last2] = count % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        a[x] = y;
    }
    cout << solve(1, 0, 0);
    return 0;
}