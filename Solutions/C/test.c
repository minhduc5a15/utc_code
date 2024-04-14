#include <stdio.h>
#include <stdlib.h>

const int MAXN = 100005;
int *BIT;

void update(int id) {
    if (id > 4 * MAXN) return;
    return ++BIT[id], update(id + (id & -id));
}

int get(int x) {
    return x == 0 ? 0 : BIT[x] + get(x - (x & -x));
}

int main() {
    BIT = (int *) malloc(4 * MAXN * sizeof(int));
    int n, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        x += MAXN;
        printf("%d ", get(x - 1));
        update(x);
    }
    free(BIT);
    return 0;
}
