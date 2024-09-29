#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAXN = 1000001;

vector<bool> primes;

bool square_number(ll n) {
    ll k = sqrt(n);
    return k * k == n;
}

void Sieve() {
    primes.resize(MAXN, true);
    int p = 2;
    while (p * p <= MAXN) {
        if (primes[p]) {
            for (int i = p * p; i < MAXN; i += p) {
                primes[i] = false;
            }
        }
        ++p;
    }
    primes[0] = primes[1] = false;
}

void solve(ll n) {
    if (!square_number(n)) {
        cout << "NO\n";
    }
    else {
        ll k = sqrt(n);
        if (primes[k]) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Sieve();
    ll n;
    cin >> n;
    while (n--) {
        ll x;
        cin >> x;
        solve(x);
    }
    return 0;
}
