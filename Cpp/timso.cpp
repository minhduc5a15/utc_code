#include <iostream>
#include <vector>

std::vector<int> sieve(int limit) {
    std::vector<bool> sieve(limit, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= limit; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j < limit; j += i) {
                sieve[j] = false;
            }
        }
    }
    std::vector<int> primes;
    for (int i = 2; i < limit; ++i) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

void solve(int n) {
    int limit = n;
    std::vector<int> primes;
    while (primes.size() < n) {
        primes = sieve(limit);
        limit *= 2;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << primes[i];
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    solve(n);
    return 0;
}

