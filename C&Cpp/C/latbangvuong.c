#include <stdio.h>
#define ll long long

ll solve(ll n, ll k) {
    return n * ((k - 1) % n) + (k - 1) / n + 1;
}

int main() {
    ll n;
    int q;
    scanf("%lld%d", &n, &q);
    while (q--) {
        ll k;
        scanf("%lld", &k);
        printf("%lld ", solve(n, k));
    }
    return 0;
}