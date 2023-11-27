#include<stdio.h>
int prime(int* a, int x) {
    int count1 = 0, count2 = 0;
    char b[3] = { 'A', 'B' , 'C' };
    for (int i = 0; i < 3; ++i) {
        if (a[i] == x) {
            printf("%c", b[i]);
            return 0;
        }
        if (a[i] - x > 0) count1++;
        else count2++;
    }
    if (count1 == 3 || count2 == 3) {
        printf("0");
        return 0;
    }
    if (count1 == 1) {
        for (int i = 0; i < 3; ++i) {
            if (a[i] - x > 0) {
                printf("%c", b[i]);
                return 0;
            }
        }
    }
    else {
        for (int i = 0; i < 3; ++i) {
            if (a[i] - x < 0) {
                printf("%c", b[i]);
                return 0;
            }
        }
    }
}
int main() {
    int x, a[3], b[3], solve;
    char c[3] = { 'A','B','C' };
    char z;
    scanf("%d", &x);
    while (x--) {
        for (int i = 0; i < 3; ++i) {
            scanf("%d%d", &a[i], &b[i]);
        }
        scanf(" %c%d", &z, &solve);
        if (z == 'x') prime(a, solve);
        else prime(b, solve);
        printf("\n");
    }
}
