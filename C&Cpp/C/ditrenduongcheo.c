#include <stdio.h>
#include <math.h>
#define ll long long
typedef struct {
    ll first;
    ll second;
} obj;

obj solve(ll n) {
    ll i = ceil((sqrt(8 * n + 1) - 1) / 2);
    ll k = i * (i + 1) / 2;
    if (k == n) {
        return (obj) {k, i + 1};
    }
    ll l = i * (i - 1) / 2;
    return (obj) {l, i};
}

int main() {
    ll n;
    scanf("%lld", &n);
    obj result = solve(n);
    if (result.second % 2 == 0) {
        printf("%lld %lld\n", n - result.first + 1, result.second + result.first - n);
    }
    else {
        printf("%lld %lld\n", result.second + result.first - n, n - result.first + 1);
    }
    return 0;
}
