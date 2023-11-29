#include <iostream>
#include <vector>
#define ll long long
#define MOD 1000000007ll
#define SIZE 2
typedef std::vector<std::vector<ll>> matrixl;
typedef std::vector<ll> vectorl;

matrixl multiply(const matrixl& a, const matrixl& b) {
    matrixl result(SIZE, vectorl(SIZE, 0));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}
matrixl pow(const matrixl& mat, int power) {
    matrixl result = mat;
    matrixl temp = mat;
    --power;
    while (power) {
        if (power & 1) {
            result = multiply(result, temp);
        }
        temp = multiply(temp, temp);
        power >>= 1;
    }

    return result;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    ll P, S;
    std::cin >> P >> S;
    matrixl F = { {S * S * S - 3 * P * S, S * S - 2 * P}, {S * S - 2 * P, S} };
    matrixl A = { {S, 1}, {-P, 0} };
    int n;
    std::cin >> n;
    if (n <= 3) {
        std::cout << F[0][0];
    }
    else {
        matrixl powResult = pow(A, n - 3);
        matrixl result = multiply(F, powResult);
        std::cout << (result[0][0] + MOD) % MOD;
    }
    return 0;
}

