#include <stdio.h>

int solve(int n) {
    int count = 0;
    int i = 2;
    while (i * i <= n) {
        while (n % i == 0) {
            n /= i;
            ++count;
        }
        i++;
    }
    if (n > 1) ++count;
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", solve(n));
    return 0;
}
