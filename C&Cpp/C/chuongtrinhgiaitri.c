#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first, second;
} pair;

int compare(const void *a, const void *b) {
    pair *a_ptr = (pair *) a;
    pair *b_ptr = (pair *) b;
    return a_ptr->first - b_ptr->first;
}

int search(pair *arr, int low, int high, int target) {
    int mid;
    while (low < high) {
        mid = low + ((high - low + 1) >> 1);
        if (arr[mid].first < target) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

int main() {
    int n;
    scanf("%d", &n);
    pair *arr = (pair *) malloc(n * sizeof(pair));
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &arr[i].first, &arr[i].second);
    }
    qsort(arr, n, sizeof(pair), compare);
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        int j = search(arr, i, n - 1, arr[i].second);
        count += j - i;
    }
    printf("%lld\n", count);

    free(arr);
    return 0;
}
