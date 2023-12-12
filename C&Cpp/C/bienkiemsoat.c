#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int intValue;
    float floatValue;
    char charValue;
} Info;

Info get_info(char *s) {
    Info info;
    sscanf(s, "%d %f %c", &info.intValue, &info.floatValue, &info.charValue);
    return info;
}

int compare(const void *a, const void *b) {
    const Info *infoA = (const Info *) a;
    const Info *infoB = (const Info *) b;
    return (infoA->floatValue > infoB->floatValue) - (infoA->floatValue < infoB->floatValue);
}

int main() {
    int n;
    scanf("%d", &n);
    Info *arr = (Info *) malloc(n * sizeof(Info));
    for (int i = 0; i < n; ++i) {
        char input[100];
        scanf(" %[^\n]s", input);
        arr[i] = get_info(input);
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i].intValue % 3 == 0 && arr[i].charValue == 'B') {
            count++;
        }
    }
    printf("%d\n", count);
    qsort(arr, n, sizeof(Info), compare);
    for (int i = 0; i < 3; ++i) {
        printf("%d\n", arr[i].intValue);
    }
    free(arr);
    return 0;
}
