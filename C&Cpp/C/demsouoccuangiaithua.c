#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define MOD 1000000007

int total_pow(int n, int p) {
    int res = 1;
    int k = log(n) / log(p);
    for (int i = 1; i <= k; ++i) {
        res += n / pow(p, i);
    }
    return res;
}

bool *Sieve(int n) {
    bool *result = (bool *) malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; ++i) result[i] = true;
    result[0] = result[1] = false;
    int p = 2;
    while (p * p <= n) {
        if (result[p]) {
            for (int i = p * p; i <= n; i += p) {
                result[i] = false;
            }
        }
        ++p;
    }

    return result;
}

ll solve(int n) {
    ll res = 1;
    bool *primes = Sieve(n);
    for (int i = 2; i <= n; ++i) {
        if (primes[i]) {
            res = (res * total_pow(n, i)) % MOD;
        }
    }
    free(primes);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", solve(n));
    return 0;
}
