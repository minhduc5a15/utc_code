#include <stdio.h>
#include <math.h>
#define ll long long
int main() {
    ll n;
    scanf("%lld", &n);
    printf("%lld", (n - (ll)pow(2, (int)log2(n))) * 2 + 1);
    return 0;
}
