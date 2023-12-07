#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
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

bool* Sieve_of_Eratosthenes(int n, int* primeCount) {
    bool* prime = (bool*)malloc((n + 1) * sizeof(bool));
    for (int i = 0; i <= n; ++i) prime[i] = true;
    prime[0] = prime[1] = false;
    int p = 2;
    while (p * p <= n) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
        ++p;
    }
    *primeCount = 0;
    for (p = 2; p <= n; ++p) {
        if (prime[p]) {
            (*primeCount)++;
        }
    }
    return prime;
}

ll solve(int n) {
    ll res = 1;
    int primeCount;
    bool* primes = Sieve_of_Eratosthenes(n, &primeCount);
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
