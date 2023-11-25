#include<iostream>
#include<vector>

std::vector<bool> sieve(99999, true);
std::vector<long long> primes;

void generatePrimes() {
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= 99999; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= 99999; j += i) sieve[j] = false;
        }
    }
    for (int i = 2; i <= 99999; ++i) {
        if (sieve[i]) primes.push_back(i);
    }
}

void solve(long long n) {
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
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    long long n;
    std::cin >> n;
    generatePrimes();
    solve(n);
    return 0;
}
