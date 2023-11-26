#include <stdio.h>
#define SIZE 12

int main() {
    char c;
    int matrix[SIZE][SIZE];
    scanf("%c", &c);
    double sum = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 7; i < SIZE; ++i) {
        for (int j = SIZE - i; j <= i - 1; ++j) {
            scanf("%d", &matrix[i][j]);
            sum += matrix[i][j];
        }
    }
    printf("%.1lf", c == 'S' ? sum : sum / 30);
    return 0;
}