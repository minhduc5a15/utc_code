#include <iostream>
#include <vector>
#define ll long long
#define MOD 1000000007
#define SIZE 2
using std::cin;
using std::cout;
using std::ios_base;
using std::vector;
using vectorll = vector<ll>;
using matrixll = vector<vector<ll>>;

class Fibo {
private:
    ll n;
    matrixll F = {{1, 1}, {1, 0}};
public:
    Fibo(ll n) {
        this->n = n;
    }
    matrixll multiply(const matrixll &matrixA, const matrixll &matrixB) {
        matrixll result(SIZE, std::vector<ll>(SIZE, 0));
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for (int k = 0; k < SIZE; ++k) {
                    result[i][j] = (result[i][j] + matrixA[i][k] * matrixB[k][j]) % MOD;
                }
            }
        }
        return result;
    }
    matrixll power(const matrixll &base = {{1, 1}, {1, 0}}) {
        matrixll result = {{1, 0}, {0, 1}};
        matrixll current_base = base;
        ll exponent = this->n + 1;
        while (exponent) {
            if (exponent & 1) {
                result = multiply(result, current_base);
            }
            current_base = multiply(current_base, current_base);
            exponent >>= 1;
        }
        return result;
    }

    ll power(ll base) {
        base %= MOD;
        ll result = 1;
        while (n) {
            if (n & 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            n >>= 1;
        }
        return result;
    }

    ll fib() {
        F = this->power(F);
        return F[0][0] % MOD;
    }
    ll result() {
        return (this->power(2) - this->fib() + 1 + MOD) % MOD;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        Fibo *fibo = new Fibo(n);
        cout << fibo->result() << '\n';
        delete fibo;
    }

    return 0;
}
