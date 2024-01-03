#include <iostream>
#include <vector>
#define ll long long
const int MOD = 1000000007;
const int MAX = 100001;
using namespace std;

vector<ll> factorial(MAX), inverse(MAX);

ll power(ll base, ll exponent, int modulus = MOD) {
    base %= modulus;
    ll result = 1;
    while (exponent) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
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
    for (int i = 1; i < MAX; ++i) {
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

