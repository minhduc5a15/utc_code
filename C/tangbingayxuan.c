#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int *arr = (int *) malloc((n + 1) * sizeof(int));
    arr[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    int left = 1, right = 1, max_sum = 0;
    int start = 0, end = 0;
    while (right <= n) {
        int sum = arr[right] - arr[left - 1];
        if (sum <= k) {
            if (sum > max_sum) {
                max_sum = sum;
                start = left;
                end = right;
            }
            right++;
        }
        else {
            left++;
        }
    }
    printf("%d %d", start, end - start + 1);

    free(arr);
    return 0;
}
