#include <iostream>
#include <vector>
#define ll long long
using std::cin;
using std::cout;
using std::ios_base;
typedef std::vector<ll> vll;
typedef std::vector<vll> matrixll;
const int MOD = 1000000007;
const int MAT_SIZE = 6;

matrixll multiply(const matrixll &matrixA, const matrixll &matrixB) {
    matrixll result(MAT_SIZE, vll(MAT_SIZE, 0));
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            for (int k = 0; k < MAT_SIZE; ++k) {
                result[i][j] = (result[i][j] + matrixA[i][k] * matrixB[k][j]) % MOD;
            }
        }
    }
    return result;
}

matrixll power(matrixll base, ll exponent) {
    matrixll identMatrix = {{1, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1}};
    while (exponent) {
        if (exponent & 1) {
            identMatrix = multiply(identMatrix, base);
        }
        base = multiply(base, base);
        exponent >>= 1;
    }
    return identMatrix;
}

ll solve(ll n) {
    matrixll F = {{0, 1, 0, 0, 0, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 1}, {1, 1, 1, 1, 1, 1}};
    vll v = {0, 0, 0, 0, 0, 1};
    F = power(F, n + 5);
    ll res = 0;
    for (int i = 0; i < MAT_SIZE; ++i) {
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