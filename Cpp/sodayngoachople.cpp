#include <iostream>
#define MOD 1000000007
#define ll long long
int power(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a % MOD;
    ll t = power(a, b / 2);
    t = (t * t) % MOD;
    if (b & 1) t = (t * a) % MOD;
    return t;
}

int catalan(int n) {
    ll res = 1;
    for (int i = 2 * n; i > n; --i)
        res = (res * i) % MOD;
    for (int i = n; i > 0; --i)
        res = (res * power(i, MOD - 2)) % MOD;
    res = (res * power(n + 1, MOD - 2)) % MOD;
    return res;
}
int solve(int n) {
    if (n % 2 != 0) return 0;
    return catalan(n / 2);
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


// code by duck it1
