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
        exponent >>= 1ll;
    }
    return result;
}

int main() {
    ll n;
    scanf("%lld", &n);
    if (n >= 4) printf("%lld", power(2, n - 2, MOD));
    else {
        if (n == 1) printf("1");
        else printf("2");
    }
    return 0;
}
