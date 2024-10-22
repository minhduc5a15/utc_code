#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    int min_val = INT_MAX;
    int count = 0;
    int pos = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        if (x < min_val) {
            min_val = x;
            pos = i;
            count = 1;
        }
        else if (x == min_val) {
            count++;
        }
        printf("%d %d %d\n", min_val, count, pos);
    }
    return 0;
}