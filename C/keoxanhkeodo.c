#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if (a > b) swap(&a, &b);
        printf("%s\n", (b <= a * (c + 1)) ? "YES" : "NO");
    }
    return 0;
}
