#include <stdio.h>
#include <math.h>
typedef unsigned long long ull;

int main() {
    ull n;
    scanf("%llu", &n);
    ull p = log2(n);
    printf("%llu", (n - (1ull << p)) << 1 | 1);
    return 0;
}