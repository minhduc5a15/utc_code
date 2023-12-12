#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf((((((b & ~a) | d) | a) == b) && ((((b & ~a) | d) & c) == d)) ? "YES\n" : "NO\n");
    }
    return 0;
}