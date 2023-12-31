#include <iostream>
#define ll long long
const int MOD = 1000000007;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    ll rows = ((n % MOD) * ((n + 1) % MOD)) / 2 % MOD;
    ll cols = ((m % MOD) * ((m + 1) % MOD)) / 2 % MOD;
    ll result = (rows * cols) % MOD;
    cout << result;
    return 0;
}

