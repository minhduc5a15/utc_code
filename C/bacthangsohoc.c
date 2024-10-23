#include <stdio.h>
#include <math.h>
typedef long long ll;

int main() {
    ll n;
    scanf("%lld", &n);
    ll k = ceil((-1 + sqrt(1 + (n << 3ll))) / 2);
    printf("%lld", n - (ll) ((k - 1) * k / 2));
    return 0;
}