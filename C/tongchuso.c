#include <stdio.h>
typedef long long ll;

ll sum(ll num, ll cur, ll prev) {
    if (!num) return 0;
    ll last = num % 10;
    ll rest = num / 10;
    ll total = rest * cur * 45 + (last * (last - 1) >> 1) * cur + last * (prev + 1);
    return total + sum(rest, cur * 10, prev + last * cur);
}

ll solve(ll a, ll b) {
    return sum(b, 1, 0) - sum(a - 1, 1, 0);
}

int main() {
    int t;
    ll a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", solve(a, b));
    }
    return 0;
}
