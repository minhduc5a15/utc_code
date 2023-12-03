#include <iostream>
#include <vector>
#include <algorithm>
#define ull unsigned long long
#define MOD 1000000007ull
#define MAX 1000001
using namespace std;
vector<ull> fact(MAX), inverse(MAX);
ull power(ull base, ull exponent) {
    base %= MOD;
    ull result = 1;
    while (exponent) {
        if (exponent & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent >>= 1ull;
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
vector<ull> memo(vector<ull> arr, int n, ull max) {
    ++max;
    vector<ull> result;
    for (int i = 0; i <= max; ++i) {
        ull d = power(2, i - 1);
        result.push_back(i & 1 ? d : (d % MOD + C(i) % MOD) % MOD);
    }
    return result;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ull> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    fact[0] = 1; inverse[0] = 1;
    ull max_n = *max_element(arr.begin(), arr.end());
    for (int i = 1; i <= MAX; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inverse[i] = inverse_num(fact[i]);
    }
    vector<ull> result = memo(arr, n, max_n);
    for (ull item : arr) {
        cout << result[item] << endl;
    }
    return 0;
}


// code by duck it1
