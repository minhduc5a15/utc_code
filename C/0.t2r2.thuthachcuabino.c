#include <stdio.h>

int main() {
    int n, count_two = 0, count_three = 0, count_four = 0, count_five = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) count_two++;
        if (arr[i] % 3 == 0) count_three++;
        if (arr[i] % 4 == 0) count_four++;
        if (arr[i] % 5 == 0) count_five++;
    }
    printf("%d Multiplo(s) de 2\n", count_two);
    printf("%d Multiplo(s) de 3\n", count_three);
    printf("%d Multiplo(s) de 4\n", count_four);
    printf("%d Multiplo(s) de 5\n", count_five);

    return 0;
}