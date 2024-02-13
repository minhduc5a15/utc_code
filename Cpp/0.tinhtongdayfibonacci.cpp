#include <iostream>
#include <vector>
#define ll long long
using std::cin;
using std::cout;
using std::ios_base;
typedef std::vector<ll> vll;
typedef std::vector<vll> matrixll;
const int MOD = 1000000009;
const int MAT_SIZE = 2;

matrixll multiply(const matrixll& matrixA, const matrixll& matrixB) {
    matrixll result(MAT_SIZE, vll(MAT_SIZE, 0));
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            for (int k = 0; k < MAT_SIZE; ++k) {
                result[i][j] += (matrixA[i][k] * matrixB[k][j]) % MOD;
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

matrixll power(matrixll base, int exponent) {
    matrixll identMatrix = {{1, 0}, {0, 1}};
    while (exponent) {
        if (exponent & 1) identMatrix = multiply(identMatrix, base);
        base = multiply(base, base);
        exponent >>= 1; 
    }
    return identMatrix;
}

ll solve(int n) {
    matrixll fibMatrix = {{1, 1}, {1, 0}};
    if (n == 0) return 0;
    fibMatrix = power(fibMatrix, n + 1);
    return (fibMatrix[0][0] - 1 + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}