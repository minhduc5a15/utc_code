#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *) malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}
