#include <iostream>
#include <vector>
#define ll long long
#define MOD 1000000007ll
#define SIZE 2
using std::cin;
using std::cout;
using std::ios_base;
typedef std::vector<std::vector<ll>> matrixll;
typedef std::vector<ll> vectorll;

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
matrixll pow(const matrixll &mat, int power) {
	matrixll result = mat;
	matrixll temp = mat;
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	ll P, S;
	cin >> P >> S;
	matrixll F = {{S * S * S - 3 * P * S, S * S - 2 * P}, {S * S - 2 * P, S}};
	matrixll A = {{S, 1}, {-P, 0}};
	int n;
	cin >> n;
	if (n <= 3) {
		cout << F[0][0];
	}
	else {
		matrixll powResult = pow(A, n - 3);
		matrixll result = multiply(F, powResult);
		cout << (result[0][0] + MOD) % MOD;
	}
	return 0;
}



// code by duck it1
