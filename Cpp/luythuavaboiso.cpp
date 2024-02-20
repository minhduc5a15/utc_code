#include <iostream>
#include <vector>
#define ull unsigned long long
using namespace std;
const int MOD = 1000000007;
const int MAXN = 1000001;

vector<bool> primes(MAXN, true);
vector<ull> primeNumbers;

void Sieve() {
    int p = 2, count = 0;
    while (p * p <= MAXN) {
        if (primes[p]) {
            ++count;
            for (int i = p * p; i <= MAXN; i += p) {
                primes[i] = false;
            }
        }
        ++p;
    }
    primeNumbers.reserve(count * count);
    for (int i = 5; i <= MAXN; i += 2) {
        if (primes[i]) {
            primeNumbers.emplace_back(i);
        }
    }
}

ull power(ull base, ull exponent, int modulus = MOD) {
    base %= modulus;
    ull result = 1;
    while (exponent) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
}

void solve(ull n) {
    if (n == 0) {
        cout << "1\n";
    }
    else if (1 <= n && n <= 5) {
        cout << "OK\n";
    }
    else if (n % 3 == 0) {
        cout << power(3, n / 3) << '\n';
    }
    else if (n % 2 == 0) {
        cout << power(2, n / 2) << '\n';
    }
    else if (6 <= n && n <= MAXN) {
        if (primes[n]) {
            cout << "OK" << '\n';
        }
        else {
            for (ull prime: primeNumbers) {
                if (n % prime == 0) {
                    cout << power(prime, n / prime) << '\n';
                    break;
                }
                if (prime > n) break;
            }
        }
    }
    else {
        bool found = false;
        for (ull prime: primeNumbers) {
            if (n % prime == 0) {
                found = true;
                cout << power(prime, n / prime) << '\n';
                break;
            }
            if (prime > n) break;
        }
        if (!found) cout << "OK\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    Sieve();
    while (t--) {
        ull n;
        cin >> n;
        solve(n);
    }
    return 0;
}

