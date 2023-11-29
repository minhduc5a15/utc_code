#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    int max_element = arr[0], min_element = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max_element) max_element = arr[i];
        if (arr[i] < min_element) min_element = arr[i];
    }
    if (max_element == min_element) {
        printf("%d", n);
        return 0;
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == max_element || arr[i] == min_element) count++;
    }
    printf("%d", count);
    return 0;
}
