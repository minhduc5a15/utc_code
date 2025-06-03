#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x, s = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            s ^= x;
        }
        if (n & 1) printf("%d\n", s);
        else printf("%d\n", s == 0 ? 0 : -1);
    }
    return 0;
}
