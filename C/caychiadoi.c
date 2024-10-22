#include <stdio.h>
#include <math.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d %lld\n", n == 1 ? 1 : (int)log2(n) + 2, 2LL * n - 1);
    }
    return 0;
}
