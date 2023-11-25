#include <iostream>
#include <vector>
typedef long long ll;
typedef std::vector<std::vector<ll>> matrix;
const int MOD = 1000000009;

matrix multiply(matrix& matrix1, matrix& matrix2) {
    matrix result(2, std::vector<ll>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < 2; ++k) {
                result[i][j] += (matrix1[i][k] * matrix2[k][j]) % MOD;
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

matrix power(matrix base, int exponent) {
    matrix identMatrix = { {1, 0}, {0, 1} };
    while (exponent) {
        if (exponent & 1) identMatrix = multiply(identMatrix, base);
        base = multiply(base, base);
        exponent >>= 1; 
    }
    return identMatrix;
}

ll solve(int n) {
    matrix fibMatrix = { {1, 1}, {1, 0} };
    if (n == 0) return 0;
    fibMatrix = power(fibMatrix, n + 1);
    return (fibMatrix[0][0] - 1 + MOD) % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n;
    std::cin >> n;
    std::cout << solve(n);
    return 0;
}
