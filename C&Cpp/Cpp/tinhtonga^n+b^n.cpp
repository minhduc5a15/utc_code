#include <iostream>
#include <vector>
#define ll long long
#define MOD 1000000007ll
#define SIZE 2
using std::cin;
using std::cout;
using std::ios_base;
typedef std::vector<ll> vectorll;
typedef std::vector<vectorll> matrixll;

matrixll multiply(const matrixll &a, const matrixll &b) {
    matrixll result(SIZE, vectorll(SIZE, 0));
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < SIZE; ++k) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return result;
}

matrixll power(const matrixll &mat, int exponent) {
    matrixll result = mat;
    matrixll temp = mat;
    --exponent;
    while (exponent) {
        if (exponent & 1) {
            result = multiply(result, temp);
        }
        temp = multiply(temp, temp);
        exponent >>= 1;
    }
    return result;
}

ll solve(ll P, ll S, int n) {
    matrixll F = {{S * S * S - 3 * P * S, S * S - 2 * P}, {S * S - 2 * P, S}};
    matrixll A = {{S, 1}, {-P, 0}};
    if (n <= 3) {
        return F[0][0];
    }
    matrixll powResult = power(A, n - 3);
    matrixll result = multiply(F, powResult);
    return (result[0][0] + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll P, S;
    cin >> P >> S;
    int n;
    cin >> n;
    cout << solve(P, S, n);
    return 0;
}
