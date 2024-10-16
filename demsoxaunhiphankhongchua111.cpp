#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> matrixll;
constexpr ll MOD = 1000000007;
constexpr int SIZE = 3;

matrixll multiply(const matrixll &matrixA, const matrixll &matrixB) {
    matrixll result(SIZE, vll(SIZE, 0));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                result[i][j] = (result[i][j] + (matrixA[i][k] % MOD) * (matrixB[k][j] % MOD)) % MOD;
            }
        }
    }
    return result;
}

matrixll power(matrixll base, ll exponent) {
    matrixll result = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    while (exponent) {
        if (exponent & 1) result = multiply(result, base);
        base = multiply(base, base);
        exponent >>= 1;
    }
    return result;
}

ll solve(ll n) {
    matrixll F = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
    vll v = {1, 1, 0};
    F = power(F, n);
    ll res = 0;
    for (int i = 0; i < SIZE; ++i) {
        res = (res + (F[0][i] * v[i]) % MOD) % MOD;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    cout << solve(n);
    return 0;
}