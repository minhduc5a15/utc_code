#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000
int min(int a, int b) {
    return a < b ? a : b;
}
void init(int** matrix, int n, int m) {
    for (int i = 1; i <= n; ++i) {
        matrix[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        matrix[u][v] = w;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                matrix[j][k] = min(matrix[j][k], matrix[j][i] + matrix[i][k]);
            }
        }
    }
}

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int** matrix = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; ++i) {
        matrix[i] = (int*)malloc((n + 1) * sizeof(int));
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            matrix[i][j] = MAX;
        }
    }
    init(matrix, n, m);
    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        printf("%d\n", matrix[u][v] != MAX ? matrix[u][v] : -1);
    }
    for (int i = 0; i <= n; ++i) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

