#include <iostream>
typedef long long ll;
const int MOD = 1000000007;

int power(ll base, ll exponent, int modulus = MOD) {
    base %= modulus;
    ll result = 1;
    while (exponent) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1ll;
    }
    return result;
}

int catalan(int n) {
    ll res = 1;
    for (int i = n << 1; i > n; --i) res = (res * i) % MOD;
    for (int i = n; i > 0; --i) res = (res * power(i, MOD - 2)) % MOD;
    res = (res * power(n + 1, MOD - 2)) % MOD;
    return res;
}

int solve(int n) {
    if (n & 1) return 0;
    n >>= 1;
    return catalan(n);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::cout << solve(n);
    return 0;
}

