#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
const int MAXN = 1024;

int main() {
    ll *arr = (ll *) calloc(MAXN, sizeof(ll));
    int n;
    scanf("%d", &n);
    while (n--) {
        int digit = 0;
        char s[1000000];
        scanf("%s", s);
        for (int i = 0; s[i] != '\0'; ++i) {
            digit |= 1 << (s[i] - '0');
        }
        ++arr[digit];
    }
    ll res = 0;

    for (int i = 0; i < MAXN; ++i) {
        if (arr[i]) {
            for (int j = i; j < MAXN; ++j) {
                if (arr[j] && (i | j) == MAXN - 1) {
                    if (i == j) {
                        res += arr[i] * (arr[i] - 1) / 2;
                    }
                    else {
                        res += arr[i] * arr[j];
                    }
                }
            }
        }
    }

    printf("%lld\n", res);

    free(arr);
    return 0;
}
