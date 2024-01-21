#include <stdio.h>
#define ll long long

ll pow2(ll n) {
    return n * n;
}

ll calc(ll n) {
    return n == 0 ? 0 : (n & 1 ? pow2((n + 1) / 2) + calc(n / 2) : pow2(n / 2) + calc(n / 2));
}

void solve(ll a, ll b) {
    printf("%lld\n", calc(b) - calc(a - 1));
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);
        solve(a, b);
    }
    return 0;
}