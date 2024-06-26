#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::ios_base;
typedef unsigned long long ull;
typedef std::vector<ull> vull;
typedef std::vector<vull> matrixull;
const int MOD = 1000000007;
const int MAT_SIZE = 2;

matrixull multiply(const matrixull &matrixA, const matrixull &matrixB) {
    matrixull result(MAT_SIZE, vull(MAT_SIZE, 0));
    for (int i = 0; i < MAT_SIZE; ++i) {
        for (int j = 0; j < MAT_SIZE; ++j) {
            for (int k = 0; k < MAT_SIZE; ++k) {
                result[i][j] = (result[i][j] + matrixA[i][k] * matrixB[k][j]) % MOD;
            }
        }
    }
    return result;
}

matrixull power(matrixull base, ull exponent) {
    matrixull result = {{1, 0}, {0, 1}};
    while (exponent) {
        if (exponent & 1) result = multiply(result, base);
        base = multiply(base, base);
        exponent >>= 1;
    }
    return result;
}

ull solve(ull n) {
    matrixull F = {{1, 1}, {1, 0}};
    F = power(F, n + 1);
    return F[0][0] - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ull n;
    cin >> n;
    cout << solve(n);
    return 0;
}
