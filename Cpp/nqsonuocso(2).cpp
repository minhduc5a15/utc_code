#include <iostream>
#include <vector>
#define ll long long
const int MAXN = 100000;

std::vector<bool> sieve(MAXN, true);
std::vector<ll> primes;

void Sieve() {
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= MAXN; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= MAXN; j += i) sieve[j] = false;
        }
    }
    for (int i = 2; i <= MAXN; ++i) {
        if (sieve[i]) primes.push_back(i);
    }
}

void solve(ll n) {
    int count = 0, prime_count = 0, s = 1;
    for (int i = 0; i < primes.size() && primes[i] * primes[i] <= n; ++i) {
        if (n % primes[i] == 0) {
            prime_count++;
            while (n % primes[i] == 0) {
                n /= primes[i];
                count++;
            }
            s *= count + 1;
            count = 0;
        }
    }
    if (n > 1) {
        s *= 2;
        prime_count++;
    }
    std::cout << s - prime_count;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    ll n;
    std::cin >> n;
    Sieve();
    solve(n);
    return 0;
}


