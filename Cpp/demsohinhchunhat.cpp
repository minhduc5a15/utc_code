#include <iostream>
#define MOD 1000000007
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    long long rows = ((n % MOD) * ((n + 1) % MOD)) / 2 % MOD;
    long long cols = ((m % MOD) * ((m + 1) % MOD)) / 2 % MOD;
    long long result = (rows * cols) % MOD;
    cout << result << endl;
    return 0;
}
