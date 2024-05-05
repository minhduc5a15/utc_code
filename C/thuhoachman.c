#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *arr = (int *) malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    long long sum = 0;
    for (int i = 1; i <= n + 1; ++i) {
        int t = arr[i - 1];
        t = min(t, k);
        if (arr[i] + t < k) {
            sum += arr[i] + t;
            arr[i] = 0;
        }
        else {
            arr[i] -= (k - t);
            sum += k;
        }
    }
    printf("%lld", sum);
    free(arr);
    return 0;
}