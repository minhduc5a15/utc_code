#include <iostream>
#include <vector>
#define MOD 1000000007
#define SIZE 2
using std::cin;
using std::cout;
using std::ios_base;
typedef long long ll;
typedef std::vector<std::vector<ll>> matrix;

matrix multiply(matrix &matrix1, matrix &matrix2) {
	matrix result(SIZE, std::vector<ll>(SIZE));
	for (int i = 0; i < SIZE; ++i) {
		for (int j = 0; j < SIZE; ++j) {
			result[i][j] = 0;
			for (int k = 0; k < SIZE; ++k) {
				result[i][j] += (matrix1[i][k] * matrix2[k][j]) % MOD;
				result[i][j] %= MOD;
			}
		}
	}
	return result;
}

matrix power(matrix base, int exponent) {
	matrix identMatrix = {{1, 0}, {0, 1}};
	while (exponent) {
		if (exponent & 1) identMatrix = multiply(identMatrix, base);
		base = multiply(base, base);
		exponent >>= 1;
	}
	return identMatrix;
}

ll solve(int n) {
	matrix fibMatrix = {{1, 1}, {1, 0}};
	if (n == 0) return 0;
	fibMatrix = power(fibMatrix, n + 1);
	return (fibMatrix[0][0] - 1 + MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin >> n;
    cout << solve(n);
	return 0;
}


// code by duck it1
