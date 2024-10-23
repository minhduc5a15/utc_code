#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

int *BIT;

void update(int id, int n) {
    if (id > 2 * n) return;
    return ++BIT[id], update(id + (id & -id), n);
}

ll get(int x) {
    return !x ? 0 : BIT[x] + get(x - (x & -x));
}

int main() {
    int n, x;
    ll count = 0;
    scanf("%d", &n);
    BIT = (int *) calloc(n << 1 | 1,  sizeof(int));
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        x = n - x + 1;
        count += get(x);
        update(x, n);
    }
    printf("%lld", count);
    return 0;
}