#include <stdio.h>
#define ll long long

ll pow2(ll n) {
    return n * n;
}

ll calc(ll n) {
    return n == 0 ? 0 : pow2(((n & 1) + n) >> 1) + calc(n >> 1);
}

void solve(ll a, ll b) {
    printf("%lld\n", calc(b) - calc(a - 1));
}

int main() {
    int t;
    scanf("%d", &t);
    ll a, b;
    while (t--) {
        scanf("%lld %lld", &a, &b);
        solve(a, b);
    }
    return 0;
}