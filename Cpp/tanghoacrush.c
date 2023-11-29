#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, result = 0;
    scanf("%d %d", &n, &m);
    int* sum_arr = (int*)calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; ++i) {
        int temp;
        scanf("%d", &temp);
        sum_arr[i] = sum_arr[i - 1] + temp;
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        result += sum_arr[r] - sum_arr[l - 1] > 0 ? sum_arr[r] - sum_arr[l - 1] : 0;
    }
    printf("%d", result);
    free(sum_arr);
    return 0;
}