#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1000001;

vector<bool> primes;

void Sieve() {
    primes.resize(MAXN, true);
    for (int p = 2; p * p <= MAXN; ++p) {
        if (primes[p]) {
            for (int i = p * p; i <= MAXN; i += p) {
                primes[i] = false;
            }
        }
    }
    primes[0] = primes[1] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Sieve();
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; ++j) {
            if (primes[j]) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}


