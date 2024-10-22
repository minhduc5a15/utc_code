#include <stdio.h>
#include <math.h>
typedef unsigned long long ull;

ull solve(ull k, ull x) {
    return x > k * k ? (k << 1) - 1 : x <= k * (k + 1) >> 1 ? ceil((-1 + sqrt(1 + (x << 3ll))) / 2) : (k << 1) - solve(k, k * k - x + 1);
}

int main() {
    int t;
    scanf("%d", &t);
    ull k, x;
    while (t--) {
        scanf("%llu %llu", &k, &x);
        printf("%llu\n", solve(k, x));
    }
    return 0;
}
