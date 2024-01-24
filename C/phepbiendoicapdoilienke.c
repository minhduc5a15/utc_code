#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int s = 0, arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i] & 1) s++;
    }
    if (s & 1)
        printf("NO");
    else {
        int count = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] & 1) {
                count += 2;
                ++arr[i + 1];
            }
        }
        printf("%d", count);
    }

    return 0;
}
