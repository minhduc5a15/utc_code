#include <stdio.h>
#define ll long long
#define MAX 1024

int main() {
    ll arr[MAX] = {0};
    ll res = 0;
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

    for (int i = 0; i < MAX; ++i) {
        if (arr[i] > 0) {
            for (int j = i; j < MAX; ++j) {
                if (arr[j] && (i | j) == MAX - 1) {
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

    return 0;
}
