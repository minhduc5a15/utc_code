#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BITMASK 1024

int max(int a, int b) {
    return (a > b) ? a : b;
}

int solve(int n, const int *arr) {
    int currMax[MAX_BITMASK] = {0}, prevMax[MAX_BITMASK] = {0};
    int result = 0;
    for (int i = 0; i < n; ++i) {
        int num = arr[i];
        int digitMask = 0;
        char number[10];
        sprintf(number, "%d", num);
        for (int j = 0; j < strlen(number); ++j) {
            digitMask |= 1 << (number[j] - '0');
        }
        for (int mask = 0; mask < MAX_BITMASK; ++mask) {
            currMax[mask] = max(currMax[mask], prevMax[mask]);
            if (!(mask & digitMask)) {
                int newMask = mask | digitMask;
                currMax[newMask] = max(currMax[newMask], prevMax[mask] + num);
                result = max(result, currMax[newMask]);
            }
        }
        memcpy(prevMax, currMax, sizeof(currMax));
    }

    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int *arr = (int *) malloc(n * sizeof(int));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        int result = solve(n, arr);
        printf("%d\n", result);
        free(arr);
    }
    return 0;
}
