#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    int s = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        s += arr[i];
    }
    int curr_sum = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        curr_sum += arr[i];
        if (curr_sum - arr[i] == s - curr_sum) {
            printf("%d\n", i + 1);
            count++;
        }
    }
    printf("%d\n", count);
    free(arr);
    return 0;
}
