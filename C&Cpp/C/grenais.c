#include <stdio.h>

int main() {
    int x, y, a, b, c, d;
    a = b = c = d = 0;
    while (1) {
        scanf("%d%d", &x, &y);
        d++;
        if (x == y)
            c++;
        else if (x > y)
            a++;
        else if (x < y)
            b++;
        printf("Novo grenal (1-sim 2-nao)\n");
        scanf("%d", &x);
        if (x == 2)
            break;
    }
    printf("%d grenais\nanter:%d\nbremio:%d\nEmpates:%d\n", d, a, b, c);
    if (a == b)
        printf("Nao houve vencedor\n");
    else if (a > b)
        printf("anter venceu mais\n");
    else if (a < b)
        printf("bremio venceu mais\n");
    return 0;
}