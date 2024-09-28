#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

int cmp(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}

int main() {
    int n;
    scanf("%d", &n);
    ll *arr = (ll *) malloc(n * sizeof(ll));
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &arr[i]);
    }
    qsort(arr, n, sizeof(ll), cmp);
    ll max = 0;
    for (int i = 0; i < n; ++i) {
        if (max < i + arr[i]) {
            max = i + arr[i];
        }
    }
    printf("%lld", max + 2);
    free(arr);
    return 0;
}