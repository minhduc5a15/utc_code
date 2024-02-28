#include <stdio.h>
#include <stdlib.h>
#define ll long long int
const int MAXN = 200005;
const int MAXL = 11;

int main() {
    ll n, res = 0;
    int id = 0;
    int (*digit)[MAXL] = (int (*)[MAXL]) calloc(MAXN, sizeof(int[MAXL]));
    while (scanf("%lld", &n) == 1 && n != -1) {
        for (int i = MAXL - 1; i >= 0; --i) {
            digit[id][i] = n % 10;
            n /= 10;
        }
        for (int i = 0; i < MAXL && id > 0; ++i) {
            if (digit[id][i] > digit[id - 1][i]) digit[id][i] = 0;
            if (digit[id][i] < digit[id - 1][i]) break;
        }
        for (int i = 0; i < MAXL; ++i) {
            n *= 10;
            n += digit[id][i];
        }
        res += n;
        ++id;
    }
    printf("%lld\n", res);
    free(digit);

    return 0;
}
