#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}
int solve(int* top, int* bottom, int h) {
    for (int i = h - 1; i >= 0; --i) {
        top[i] += top[i + 1];
        bottom[i] += bottom[i + 1];
    }
    int result = top[h] + bottom[0];
    for (int i = 0; i < h; ++i) {
        result = min(result, top[h - i] + bottom[i]);
    }
    return result;
}

int main() {
    int h, l;
    scanf("%d%d", &h, &l);
    int* top = (int*)calloc(h + 1, sizeof(int));
    int* bottom = (int*)calloc(h + 1, sizeof(int));
    for (int i = 0; i < l; ++i) {
        int n;
        scanf("%d", &n);
        ++top[n];
    }
    for (int i = 0; i < l; ++i) {
        int n;
        scanf("%d", &n);
        ++bottom[n];
    }
    printf("%d", solve(top, bottom, h));
    free(top);
    free(bottom);
    return 0;
}
