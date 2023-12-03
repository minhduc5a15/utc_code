#include <iostream>
#include <vector>
#define ull unsigned long long
#define MOD 1000000007ull
#define MAXN 1000001
using namespace std;
vector<bool> primes(MAXN, true);
vector<ull> primeNumbers;
void Sieve() {
    int p = 2;
    while (p * p <= MAXN) {
        if (primes[p]) {
            for (int i = p * p; i <= MAXN; i += p) {
                primes[i] = false;
            }
        }
        ++p;
    }
    for (int i = 5; i <= MAXN; i += 2) {
        if (primes[i]) {
            primeNumbers.push_back(i);
        }
    }
    return;
}

ull power(ull base, ull exponent) {
    base %= MOD;
    ull result = 1;
    while (exponent) {
        if (exponent & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent >>= 1ull;
    }
    return result;
}

void solve(ull n) {
    if (n == 0) {
        cout << "1" << endl;
    }
    else if (1 <= n && n <= 5) {
        cout << "OK" << endl;
    }
    else if (n % 3 == 0) {
        cout << power(3, n / 3) << endl;
    }
    else if (n % 2 == 0) {
        cout << power(2, n / 2) << endl;
    }
    else if (6 <= n && n <= MAXN) {
        if (primes[n]) {
            cout << "OK" << endl;
        }
        else {
            for (ull& prime : primeNumbers) {
                if (n % prime == 0) {
                    cout << power(prime, n / prime) << endl;
                    break;
                }
            }
        }
    }
    else {
        bool check = false;
        for (ull& prime : primeNumbers) {
            if (n % prime == 0) {
                check = true;
                cout << power(prime, n / prime) << endl;
                break;
            }
        }
        if (!check) {
            cout << "OK" << endl;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t; cin >> t;
    Sieve();
    while (t--) {
        ull n;
        cin >> n;
        solve(n);
    }
    return 0;
}


// code by duck it1
