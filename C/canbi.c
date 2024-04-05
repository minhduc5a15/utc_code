#include <stdio.h>
#include <math.h>
typedef unsigned long long ull;

int main() {
    ull n;
    scanf("%llu", &n);
    ull res = log2(n);
    printf("%llu", res);
    return 0;
}