#include <iostream>
#include <vector>
#define ll long long
#define MOD 1000000007
#define SIZE 2
using std::cin;
using std::cout;
using std::ios_base;
using std::vector;
using vectorll = vector<ll>;
using matrixll = vector<vector<ll>>;
matrixll multiply(const matrixll &matrixA, const matrixll &matrixB) {
    matrixll result(SIZE, vectorll(SIZE, 0));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                result[i][j] = (result[i][j] + matrixA[i][k] * matrixB[k][j]) % MOD;
            }
        }
    }
    return result;
}

matrixll power(matrixll base, ll exponent) {
    matrixll result = {{1, 1}, {1, 0}};
    while (exponent) {
        if (exponent & 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exponent >>= 1;
    }
    return result;
}
ll power(ll base, ll exponent) {
    base %= MOD;
    ll result = 1;
    while (exponent) {
        if (exponent & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent >>= 1;
    }
    return result;
}
ll fib(ll n) {
    matrixll F = {{1, 1}, {1, 0}};
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
