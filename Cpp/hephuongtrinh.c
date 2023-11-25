#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int x = (b & ~a) | d;
        printf((((x | a) == b) && ((x & c) == d)) ? "YES\n" : "NO\n");
    }
    return 0;
}   
