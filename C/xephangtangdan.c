#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    int *count;
    for (int j = 1; j <= t; ++j) {
        int n, res = 0;
        scanf("%d", &n);
        count = (int *) calloc(n + 1, sizeof(int));
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            count[x] = count[x - 1] + 1;
            res = res > count[x] ? res : count[x];
        }
        printf("#Case %d: %d\n", j, n - res);
        free(count);
    }
    return 0;
}