#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::ios_base;
typedef unsigned long long ull;
typedef std::vector<std::vector<ull>> matrix;
const ull MOD = 1e9 + 7;

matrix multiply(matrix &F, matrix &M) {
    ull x = (F[0][0] * M[0][0] + F[0][1] * M[1][0]) % MOD;
    ull y = (F[0][0] * M[0][1] + F[0][1] * M[1][1]) % MOD;
    ull z = (F[1][0] * M[0][0] + F[1][1] * M[1][0]) % MOD;
    ull w = (F[1][0] * M[0][1] + F[1][1] * M[1][1]) % MOD;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
    return F;
}

matrix power(matrix F, ull n) {
    matrix result = {{1, 0}, {0, 1}}; 
    while (n > 0) {
        if (n & 1) result = multiply(result, F);
        F = multiply(F, F);
        n >>= 1;
    }
    return result;
}

ull solve(ull n) {
    matrix F = {{1, 1}, {1, 0}};
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
