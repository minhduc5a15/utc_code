#include <iostream>
using namespace std;
typedef long long ll;
constexpr ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int maxn = min(n, m);
    ll count = 0;
    for (int i = 0; i <= maxn / 2; ++i) {
        int a = n - 2 * i, b = m - 2 * i;
        ll count_1 = (a / 3 + a % 4) / 4 + (a % 4 == 0);
        ll count_2 = (b / 3 + b % 4) / 4 + (b % 4 == 0);
        count += (count_1 % MOD * count_2 % MOD);
        count %= MOD;
    }
    cout << count;
    return 0;
}
