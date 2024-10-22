#include <iostream>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    ll rows = ((n % MOD) * ((n + 1) % MOD)) / 2 % MOD;
    ll cols = ((m % MOD) * ((m + 1) % MOD)) / 2 % MOD;
    ll result = (rows * cols) % MOD;
    cout << result;
    return 0;
}

