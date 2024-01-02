#include <stdio.h>
#include <string.h>
#define MAXN 100000
#define ull unsigned long long
const int MOD = 1000000007;

ull power(ull base, ull exponent, ull modulus) {
    base %= modulus;
    ull result = 1;
    while (exponent) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1ULL;
    }
    return result;
}

int main() {
    char s[MAXN];
    scanf("%s", &s);
    int n = strlen(s);
    ull s1 = 0;
    for (int i = 0; i < n; ++i) {
        s1 = (s1 * 10 + (s[i] - '0')) % MOD;
    }
    ull s2 = 0;
    scanf("%s", &s);
    n = strlen(s);
    for (int i = 0; i < n; ++i) {
        s2 = (s2 * 10 + (s[i] - '0')) % (MOD - 1);
    }
    printf("%llu", power(s1, s2, MOD));
    return 0;
}

// code by duck it1