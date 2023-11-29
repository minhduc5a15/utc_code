#include <stdio.h>
#define ll long long

ll solve(ll n) {
    ll i = 2;
    while (i * i <= n) {
        ll d = i * i;
        if (n % d == 0) {
            while (n % d == 0) {
                n /= i;
            }
        }
        i += 1 + (i & 1);
    }
    return n;
}

int main() {
    ll n;
    scanf("%lld", &n);
    printf("%lld\n", solve(n));
    return 0;
}