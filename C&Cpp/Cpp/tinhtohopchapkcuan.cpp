#include <iostream>
#include <vector>
#define ll long long
#define MAXN 100001
const int MOD = 1000000007;

using namespace std;

vector<ll> factorial(MAXN), inverse(MAXN);

int power(int a, int b) {
    if (b == 0) return 1;
    ll temp = power(a, b / 2);
    temp = (temp * temp) % MOD;
    if (b % 2 == 0) return temp;
    else return ((a * temp) % MOD);
}

ll inverse_num(int n) {
    return power(n, MOD - 2);
}

ll C(int n, int r) {
    if (r > n) return 0;
    return (factorial[n] * ((inverse[r] * inverse[n - r]) % MOD)) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    factorial[0] = 1;
    inverse[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
        inverse[i] = inverse_num(factorial[i]);
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << C(a, b) << "\n";
    }
    return 0;
}

