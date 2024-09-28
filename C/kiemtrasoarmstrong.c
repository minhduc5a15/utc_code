#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf((n == 153 || n == 370 || n == 371 || n == 407) ? "YES" : "NO");
    return 0;
}