#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int s = 0, a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] & 1) s++;
    }
    if (s & 1)
        printf("NO");
    else {
        int count = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] & 1) {
                count += 2;
                ++a[i + 1];
            }
        }
        printf("%d", count);
    }

    return 0;
}

// code by duck it1
