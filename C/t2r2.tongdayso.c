#include <stdio.h>
typedef long long ll;
const int MOD = 1000000007;

int main() {
    ll n, s = 0;
    while (scanf("%lld", &n) == 1) {
        s += n;
        s = (s + MOD) % MOD;
    }
    printf("%lld", s % MOD);
    return 0;
}