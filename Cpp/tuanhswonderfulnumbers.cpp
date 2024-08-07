// cách này hơi dài :<
#include <iostream>
#include <vector>
typedef long long ll;
typedef std::vector<ll> vll;
const int MOD = 1000000007;

bool is_good(int a, int b, int n) {
    while (n) {
        int digit = n % 10;
        if (digit != a and digit != b) {
            return false;
        }
        n /= 10;
    }
    return true;
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll factorial(int n) {
    ll res = 1;
    for (int i = 2; i <= n; ++i) {
        res = (res * i) % MOD;
    }
    return res;
}

ll inverse(int n) {
    return power(n, MOD - 2);
}

ll binomial(int n, int k) {
    ll res = factorial(n);
    res = (res * inverse(factorial(k))) % MOD;
    res = (res * inverse(factorial(n - k))) % MOD;
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int a, b, n;
    std::cin >> a >> b >> n;
    ll res = 0;
    vll fact(n + 1, 1);
    vll inv(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = power(fact[i], MOD - 2);
    }
    for (int i = 0; i <= n; ++i) {
        int sum = i * a + (n - i) * b;
        if (is_good(a, b, sum)) {
            res = (res + binomial(n, i)) % MOD;
        }
    }
    if (a == 0) std::cout << 1;
    else std::cout << res;
    return 0;
}

