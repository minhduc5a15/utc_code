#include <iostream>
#include <vector>
#define ll long long
#define MOD 1000000007
using namespace std;
typedef vector<vector<ll>> matrix;

void multiply(matrix &F, matrix &M) {
    ll x = (F[0][0] * M[0][0] + F[0][1] * M[1][0]) % MOD;
    ll y = (F[0][0] * M[0][1] + F[0][1] * M[1][1]) % MOD;
    ll z = (F[1][0] * M[0][0] + F[1][1] * M[1][0]) % MOD;
    ll w = (F[1][0] * M[0][1] + F[1][1] * M[1][1]) % MOD;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

void power(matrix &F, ll n) {
    if (n <= 1) return;
    matrix M = {{1, 1}, {1, 0}};
    power(F, n / 2);
    multiply(F, F);
    if (n & 1) multiply(F, M);
}
ll power(ll base, ll exponent) {
    base %= MOD;
    ll result = 1;
    while (exponent) {
        if (exponent & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent >>= 1ULL;
    }
    return result;
}
ll fib(ll n) {
    matrix F = {{1, 1}, {1, 0}};
    if (n == 0) return 0;
    power(F, n - 1);
    return F[0][0] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << (power(2, n) - fib(n + 3) + 1 + MOD) % MOD << '\n';
    }
    return 0;
}