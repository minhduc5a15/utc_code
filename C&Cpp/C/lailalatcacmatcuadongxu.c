#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        long long n;
        scanf("%lld", &n);
        long long m = sqrt(n);
        printf("%lld\n", n - m);
    }
    return 0;
}