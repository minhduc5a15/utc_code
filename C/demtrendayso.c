#include <stdio.h>
#include <math.h>

int square_number(int n) {
    if (n < 0) return 0;
    int k = sqrt(n);
    return k * k == n;
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int count_1 = 0, count_2 = 0, count_3 = 0, count_4 = 0, count_5 = 0, count_6 = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if (arr[i] % 3 != 0) ++count_1;
        count_2 += square_number(arr[i]);
        if (i > 0) {
            if (i <= n - 1) {
                if (i > 1 && arr[i - 2] < arr[i - 1] && arr[i - 1] < arr[i]) {
                    ++count_6;
                }
            }
            if (arr[i - 1] && arr[i] % arr[i - 1] == 0) ++count_3;
        }
        if (abs(arr[i]) % 2) ++count_4;
        else ++count_5;
    }
    printf("%d\n%d\n%d\n%d\n%d\n", count_1, count_2, count_3, (count_4 * (count_4 - 1) + count_5 * (count_5 - 1)) / 2, count_6);
    return 0;
}