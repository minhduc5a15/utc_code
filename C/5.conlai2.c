#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 10000; ++i) {
        if (i % n == 2) {
            printf("%d\n", i);
        }
    }
    return 0;
}