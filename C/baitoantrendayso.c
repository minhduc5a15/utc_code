#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX_BITMASK = 1024;

int max(int a, int b) {
    return a > b ? a : b;
}

int solve(int n, int *arr) {
    int *currMax = (int *) calloc(MAX_BITMASK, sizeof(int));
    int *prevMax = (int *) calloc(MAX_BITMASK, sizeof(int));
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int num = arr[i];
        int d = 0;
        char temp[10];
        sprintf(temp, "%d", num);
        for (int j = 0; j < strlen(temp); ++j) {
            d |= 1 << (temp[j] - '0');
        }
        for (int mask = 0; mask < MAX_BITMASK; ++mask) {
            currMax[mask] = max(currMax[mask], prevMax[mask]);
            if (mask & d) continue;
            int newMask = mask | d;
            currMax[newMask] = max(currMax[newMask], prevMax[mask] + num);
            result = max(result, currMax[newMask]);
        }
        memcpy(prevMax, currMax, sizeof(int) * MAX_BITMASK);
    }

    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    int *arr;
    while (t--) {
        int n;
        scanf("%d", &n);
        arr = (int *) malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        int result = solve(n, arr);
        printf("%d\n", result);
        free(arr);
    }
    return 0;
}
