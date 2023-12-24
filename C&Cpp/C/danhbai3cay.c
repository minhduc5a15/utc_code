#include <stdio.h>

int convert(char c) {
    if (c >= '1' && c <= '9') {
        return c - '0';
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int count_1 = 0, count_2 = 0;
    char c;
    while (n--) {
        int s1 = 0, s2 = 0;
        for (int i = 0; i < 3; ++i) {
            scanf(" %c", &c);
            s1 += convert(c);
        }
        for (int i = 0; i < 3; ++i) {
            scanf(" %c", &c);
            s2 += convert(c);
        }
        s1 = (s1 % 10) ? : 10;
        s2 = (s2 % 10) ? : 10;
        if (s1 > s2) {
            ++count_1;
        }
        if (s1 < s2) {
            ++count_2;
        }
    }
    printf("%d %d", count_1, count_2);
    return 0;
}