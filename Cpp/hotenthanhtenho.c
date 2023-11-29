#include <stdio.h>
#include <string.h>

int main() {
    char x[1000];
    scanf("%s", x);
    getchar();
    char y[1000];
    gets(y);
    printf("%s %s", y, x);
    
    return 0;
}