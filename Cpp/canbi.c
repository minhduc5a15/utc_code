#include <stdio.h>
#include <math.h>
#define ull unsigned long long

int main() {
    ull n;
    scanf("%llu", &n);
    ull res = log2(n);
    printf("%llu", res);
    return 0;
}