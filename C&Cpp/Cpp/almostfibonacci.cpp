#include <iostream>
#include <vector>
#define SIZE 2
#define ull unsigned long long
using std::cin;
using std::cout;
using std::ios_base;
typedef std::vector<ull> vectorull;
typedef std::vector<vectorull> matrixull;
const int MOD = 1000000007;

matrixull multiply(const matrixull &matrixA, const matrixull &matrixB) {
    matrixull result(SIZE, vectorull(SIZE, 0));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
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
    cin.tie(NULL);
    cout.tie(NULL);
    ull n;
    cin >> n;
    cout << solve(n);
    return 0;
}
