#include <stdio.h>
#include <math.h>

int solve(long long n) {
    return (n & (n - 1)) ? 0 : pow(2, (int)(log(n) / log(2)));
}

int main() {
    long long n;
    scanf("%lld", &n);
    printf("%d", solve(n));
    return 0;
}


// code by duck it1
