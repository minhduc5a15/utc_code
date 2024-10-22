#include <stdio.h>
typedef long long ll;
const int MOD = 1000000007;

ll power(ll base, ll exponent, int modulus) {
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

ll solve(ll n) {
    return power(n, 2, MOD) % MOD * power(n + 1, 2, MOD) % MOD * power(4, MOD - 2, MOD) % MOD;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n;
        scanf("%lld", &n);
        printf("%lld ", solve(n));
    }
    return 0;
}
