#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
typedef vector<ull> vull;
const int MAXN = 1000001;
const int MOD = 1000000007;

vull fact(MAXN), inverse(MAXN);

ull power(ull base, ull exponent, ull modulus = MOD) {
    base %= modulus;
    ull result = 1;
    while (exponent) {
        if (exponent & 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent >>= 1;
    }
    return result;
}

ull inverse_num(ull n) {
    return power(n, MOD - 2);
}

ull C(ull n) {
    ull k = (n >> 1) - 1;
    --n;
    return (fact[n] * ((inverse[k] * inverse[n - k]) % MOD)) % MOD;
}

vull memo(ull max) {
    ++max;
    vull result;
    result.reserve(max + 1);
    for (int i = 0; i <= max; ++i) {
        ull d = power(2, i - 1);
        result.emplace_back(i & 1 ? d : (d % MOD + C(i) % MOD) % MOD);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vull arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    fact[0] = 1;
    inverse[0] = 1;
    ull max_n = *max_element(arr.begin(), arr.end());
    for (int i = 1; i <= MAXN; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inverse[i] = inverse_num(fact[i]);
    }
    vull result = memo(max_n);
    for (ull num: arr) {
        cout << result[num] << '\n';
    }
    return 0;
}

