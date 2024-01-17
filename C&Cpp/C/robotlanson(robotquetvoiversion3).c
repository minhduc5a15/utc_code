#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int *dict_a = (int *) calloc(m + 1, sizeof(int));
    int *dict_b = (int *) calloc(m + 1, sizeof(int));

    while (n--) {
        int a, b;
        scanf("%d%d", &a, &b);
        dict_a[a]++;
        dict_b[b]++;
    }

    int res = 0, count = 0;
    for (int i = 0; i < m; ++i) {
        if (dict_a[i]) count += dict_a[i];
        if (dict_b[i]) count -= dict_b[i];
        if (count >= k) ++res;
    }
    printf("%d", res);

    free(dict_a);
    free(dict_b);
    return 0;
}