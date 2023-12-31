#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, result = 0;
    scanf("%d %d", &n, &m);
    int *prefix_sum = (int *) calloc(n + 1, sizeof(int));
    for (int i = 1; i <= n; ++i) {
        int temp;
        scanf("%d", &temp);
        prefix_sum[i] = prefix_sum[i - 1] + temp;
    }
    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        result += prefix_sum[r] - prefix_sum[l - 1] > 0 ? prefix_sum[r] - prefix_sum[l - 1] : 0;
    }
    printf("%d", result);
    free(prefix_sum);
    return 0;
}