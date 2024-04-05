#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min(int a, int b) {
    return a < b ? a : b;
}
int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}
int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int*)calloc(n + 3, sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    int res = 0;
    for (int i = 0; i < n + 2; i += 3) {
        res += min(arr[i] + arr[i + 1], ceil(arr[i] * 1.0 * 2 / 3) + ceil(arr[i + 1] * 1.0 * 2 / 3) + ceil(arr[i + 2] * 1.0 * 2 / 3));
    }
    free(arr);
    printf("%d", res);
    return 0;
}
