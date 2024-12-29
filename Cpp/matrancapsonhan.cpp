#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> matrixll;
constexpr ll MOD = 1000000007;

int n;
ll m;

matrixll multiply(const matrixll &A, const matrixll &B) {
    matrixll C(A.size(), vll(B[0].size(), 0));
    for (size_t i = 0; i < A.size(); ++i) {
        for (size_t j = 0; j < B[0].size(); ++j) {
            for (size_t k = 0; k < B.size(); ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

matrixll ident(int size) {
    matrixll I(size, vll(size, 0));
    for (int i = 0; i < size; ++i) {
        I[i][i] = 1;
    }
    return I;
}

matrixll power(matrixll base, ll exp) {
    matrixll result = ident(base.size());
    while (exp) {
        if (exp & 1) result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

matrixll extended(const matrixll &A) {
    int size = A.size();
    matrixll B(size << 1, vll(size << 1, 0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            B[i][j] = A[i][j];
        }
        B[i][size + i] = 1;
        B[size + i][size + i] = 1;
    }
    return B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    matrixll A(n, vll(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
            A[i][j] = (A[i][j] % MOD + MOD) % MOD;
        }
    }
    matrixll B = extended(A);
    B = power(B, m + 1);
    matrixll S(n, vll(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            S[i][j] = B[i][n + j];
        }
    }
    for (const vll row : S) {
        for (ll x : row) {
            cout << x % MOD << ' ';
        }
        cout << '\n';
    }
    return 0;
}