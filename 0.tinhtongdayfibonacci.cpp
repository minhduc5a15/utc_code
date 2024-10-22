#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::ios_base;
typedef long long ll;
typedef std::vector<ll> vll;
typedef std::vector<vll> matrixll;
constexpr int MOD = 1000000009;
constexpr int MAT_SIZE = 2;

matrixll multiply(const matrixll &matrixA, const matrixll &matrixB) {
    matrixll result(MAT_SIZE, vll(MAT_SIZE, 0));
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            for (int k = 0; k < MAT_SIZE; ++k) {
                result[i][j] += (matrixA[i][k] * matrixB[k][j]) % MOD;
            }
        }
    }
    return result;
}

matrixll power(matrixll base, int exponent) {
    matrixll result = {{1, 0}, {0, 1}};
    while (exponent) {
        if (exponent & 1) result = multiply(result, base);
        base = multiply(base, base);
        exponent >>= 1;
    }
    return result;
}

ll solve(int n) {
    if (n == 0) return 0;
    matrixll fibMatrix = {{1, 1}, {1, 0}};
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